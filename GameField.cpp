#include "GameField.h"

#include <QStyleOption>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QDialog>
#include <QMouseEvent>

#include "AbstractSheep.h"

#include "GameOverDialog.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

bool GameField::m_sweetsGenerated = false;

GameField::GameField(QWidget *parent) :
    QWidget(parent), m_isMooving(false)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    m_timer.setSingleShot(false);
    m_timer.setInterval(20);
    connect(&m_timer2, SIGNAL(timeout()), this, SLOT(onTimer2()));
    m_timer2.setSingleShot(false);
    m_timer2.setInterval(60);
    m_count = 21;
    decCount();

}

GameField::~GameField()
{
    m_sweetsGenerated = false;
}

void GameField::setSheep(AbstractSheep *sheep)
{
    m_sheep = sheep;
    sheep->setGameField(this);
}


void GameField::run()
{
    m_sheep->setPos(m_sheep->geometry().x(), m_sheep->geometry().y());
    m_timer.start();


    setStyleSheet(""
                  "QWidget#sheep {"
                  "background:url(:/img/texture/Rosy_sheep/Real_run_small/rosy_step_lean.png);"
                  "}"
                  ""
//                  "QWidget#sheep {"
//                  "background:url(:img/texture/Rosy_sheep/Real_run_small/rosy_step_0.png);"
//                  "}"
                  "");
}

void GameField::decCount()
{
    m_count--;
    emit countsChanged(m_count);
    if (!m_count)
        youWin();
}

void GameField::onTimer()
{
    tick();
    m_sheep->rotate();
}

void GameField::onTimer2()
{
    static int n = 0;
    static int k = 0;
    k = (k + 1) % 4;

    QString style = QString(""
                            "QWidget#sheep {"
                            "background:url(:img/texture/Rosy_sheep/Real_run_small/rosy_step_%0.png);"
                            "}"
                            "").arg(k);

//    if (n++ % 3 == 1)
//    {
        setStyleSheet(style);
//    }

}

void GameField::paintEvent(QPaintEvent *e)
{

    generateSweets();
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);

  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
  p.setBrush(Qt::red);
  p.drawLines(m_points);

    const QVector<QPoint> *points = &m_points;

    for (int i = 0; i < points->size() / 2;  ++i)
    {
        QVector<QPoint> line;
        QPoint a = points->at(2 * i);
        QPoint b = points->at(2 * i + 1);
        QPoint n(b.y() - a.y(),b.x() - a.x());
        n /= n.manhattanLength();
        n *= 20;
        QPoint c(a);
        c += n;
        QPoint d(b);
        d += n;

        line.append(a);
        line.append(b);
        line.append(d);
        line.append(c);
        QPolygon pol(line);
        QBrush brush(Qt::TexturePattern);
        brush.setTextureImage(QImage(":/img/texture/fence/Snow_fence_256.jpg"));
        p.setBrush(brush);
        p.drawPolygon(pol);

    }

    foreach (QRegion *r, m_areas.keys()) {
//        p.setBrush(Qt::red);
        p.setPen(Qt::NoPen);
        QBrush brush(Qt::TexturePattern);
        brush.setTextureImage(QImage(":/img/texture/lunka_128.png"));
        p.setBrush(brush);
        p.drawRects(r->rects());
    }

    p.end();
}

void GameField::mousePressEvent(QMouseEvent *event)
{
    qDebug() << m_sheep->geometry();
//    if (m_sheep->geometry().contains(event->pos()) && !m_timer.isActive())
//    {
        m_startPoint = event->pos();
        m_startPoint -= QPoint(m_sheep->width() / 2, m_sheep->height() / 2);
        m_isMooving = true;
        m_timer2.start();
//    }
}

void GameField::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isMooving)
    {
        m_point =  event->pos();

        m_point -= QPoint(m_sheep->width() / 2, m_sheep->height() / 2);
        int dx = m_point.x() - m_startPoint.x(),
                dy = m_point.y() - m_startPoint.y();

        m_sheep->setPos(m_point.x(), m_point.y());


        m_sheep->setVx(-0.1 * dx);
        m_sheep->setVy(-0.1 * dy);

        run();
        m_timer2.stop();
    }
    m_isMooving = false;
}

void GameField::mouseMoveEvent(QMouseEvent *event)
{

    if (m_isMooving)
    {
        m_point = event->pos();
        m_point -= QPoint(m_sheep->width() / 2, m_sheep->height() / 2);
        m_sheep->setPos(m_point.x(), m_point.y());
    }
}

void GameField::generateSweets()
{
    if (m_sweetsGenerated)
        return;

     std::srand(unsigned(std::time(0)));


    for (int i = 0; i < m_count; ++i)
    {

        QString imgName = QString(":/sweety/texture/tX/conf_0%1.png").arg(i % 7);
        QImage im(imgName);
        QWidget *w = new QWidget(this);
        w->resize(im.size());
        w->setStyleSheet(QString(""
                         ""
                    "QWidget {"
                    "background:url(") + imgName + QString( ");"
                    "}"
                         ""
                         ""));
                         w->show();
        int x = (rand() %  (width() - w->width()) );
        int y = rand() % (height() - w->height()) ;
        w->move(x, y);
        m_sweets.push_back(w);
    }
    m_sweetsGenerated = true;
    generateIceHole();
}

void GameField::generateIceHole()
{
    int n = rand() % 5;
    int wid = 128;
    for (int i = 0; i < n; ++i)
    {
        int x = (rand() %  (width() - wid) );
        int y = rand() % (height() - wid) ;
        QRect r(x, y, wid, wid);
        QRegion *reg = new QRegion(r);
        AreaParametrs a;
        a.type = AreaParametrs::ICE_HOLE_AREA;
        addArea(reg, a);
        QWidget *w = new QWidget(this);
        w->move(x, y);
        w->resize(wid, wid);
    }

}

const QVector<QPoint>* GameField::points() const
{
    return &m_points;
}

QList<QWidget *> *GameField::getSweets()
{
    return &m_sweets;
}

void GameField::tick()
{
    if (!m_sheep->tick())
    {
        m_timer.stop();
        m_timer2.stop();
        m_sheep->rotateOff();
        int x = m_sheep->geometry().x();
        int y = m_sheep->geometry().y();
//        QString style = QString(""
//                                ""
//                                "QWidget#sheep {"
//                                "background:url(:img/texture/Rosy_sheep/Real_run_small/rosy_step_%0.png);"
//                                "}"
//                                "").arg(0);
//        setStyleSheet(style);


    setStyleSheet(""
                  ""
                  "QWidget#sheep {"
                  "background:url(:/img/texture/Rosy_sheep/Real_run_small/rosy_step_lean.png);"
                  "}"
                  "");
    }
    foreach (QRegion *r, m_areas.keys()) {
        if (r->contains(QPoint(m_sheep->x() + m_sheep->width() / 2,
                m_sheep->y() + m_sheep->height() / 2)) && m_areas[r].type == AreaParametrs::ICE_HOLE_AREA)
        {
//        qDebug() << *r;
//        qDebug() << m_sheep->rect();
            m_sheep->hide();
            gameOver();

        }
    }
}

void GameField::addArea(QRegion *region, AreaParametrs params)
{
    m_areas[region] = params;
}

void GameField::setBorder(const QVector<QPoint> &points)
{
    m_points.clear();

    foreach (QPoint p, points) {
        m_points.append(p);
    }
//    m_points.append(points);

}

void GameField::gameOver()
{
    GameOverDialog d;
    d.exec();
    close();
    deleteLater();
}

void GameField::youWin()
{
    GameOverDialog d(true);
    d.exec();
    close();
    deleteLater();

}

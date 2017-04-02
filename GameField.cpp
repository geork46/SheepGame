#include "GameField.h"

#include <QStyleOption>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QMouseEvent>

#include "AbstractSheep.h"

GameField::GameField(QWidget *parent) :
    QWidget(parent)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    m_timer.setSingleShot(false);
    m_timer.setInterval(20);
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
}

void GameField::onTimer()
{
    tick();
}

void GameField::paintEvent(QPaintEvent *e)
{
//  QStyleOption o;
//  o.initFrom(this);
  QPainter p(this);
//  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
  p.setBrush(Qt::red);
//  p.drawLines(m_points);

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
//        QPoint c(a.x() + b.y() - a.y(), a.y() + b.x() - a.x());
//        QPoint d(b.x() + b.y() - a.y(), b.y() + b.x() - a.x());

        line.append(a);
        line.append(b);
        line.append(d);
        line.append(c);
        QPolygon pol(line);
        p.drawPolygon(pol);

    }

    p.end();
}

void GameField::mousePressEvent(QMouseEvent *event)
{
    m_startPoint = event->pos();
    m_startPoint -= QPoint(m_sheep->width() / 2, m_sheep->height() / 2);
}

void GameField::mouseReleaseEvent(QMouseEvent *event)
{

    m_point =  event->pos();
    int dx = m_point.x() - m_startPoint.x(),
            dy = m_point.y() - m_startPoint.y();

    m_point += QPoint(-dx, -dy);
    m_point -= QPoint(m_sheep->width() / 2, m_sheep->height() / 2);

    m_sheep->move(m_startPoint);

    m_sheep->setVx(0.1 * dx);
    m_sheep->setVy(0.1 * dy);

    qDebug() << dx;

    run();

}

void GameField::mouseMoveEvent(QMouseEvent *event)
{

    m_newPoint = event->pos();

    int dx = m_newPoint.x() - m_point.x(),
            dy = m_newPoint.y() - m_point.y();

    m_point += QPoint(dx, dy);
    m_point -= QPoint(m_sheep->width() / 2, m_sheep->height() / 2);

    m_sheep->move(m_point);

}

const QVector<QPoint>* GameField::points() const
{
    return &m_points;
}

void GameField::tick()
{
    m_sheep->tick();
}

void GameField::addArea(QRegion region, AreaParametrs params)
{

}

void GameField::setBorder(const QVector<QPoint> &points)
{
    m_points.clear();
    m_points.append(points);

}

#include "SheepTypeA.h"
#include "GameField.h"
#include "math.h"

SheepTypeA::SheepTypeA(QWidget *parent) :
    AbstractSheep(parent)
{

}

bool SheepTypeA::tick()
{
    AbstractSheep::tick();
    m_vx *= 0.98;
    m_vy *= 0.98;

    const QVector<QPoint> *points = m_gameField->points();

    for (int i = 0; i < points->size() / 2;  ++i)
    {
        QVector<QPoint> line;
        QPoint a = points->at(2 * i);
        QPoint b = points->at(2 * i + 1);
        QPoint n(b.y() - a.y(),b.x() - a.x());
        n /= n.manhattanLength();
        n *= 2;
        QPoint c(b);
        c += n;
        QPoint d(a);
        d += n;
//        QPoint c(a.x() + b.y() - a.y(), a.y() + b.x() - a.x());
//        QPoint d(b.x() + b.y() - a.y(), b.y() + b.x() - a.x());

        line.append(a);
        line.append(b);
        line.append(c);
        line.append(d);
        QPolygon p(line);
        QRegion r(p);


        if (r.intersects(rect()))
        {
            m_vx *= -1.0;
            m_vy *= -1.0;
            return true;
        }

    }
    return true;
}


#include "AbstractSheep.h"

#include "GameField.h"

#include <QDebug>
#include <math.h>

AbstractSheep::AbstractSheep(QWidget *parent) :
    QWidget(parent)
{
    m_gameField = 0;
}

void AbstractSheep::setGameField(GameField *gamefield)
{
    m_gameField = gamefield;
    this->setParent(m_gameField);
}

void AbstractSheep::tick()
{
    if (fabs(m_vx) > 0.1)
        m_x += m_vx;
    if (fabs(m_vy) > 0.1)
        m_y += m_vy;

    if (m_x < 0)
    {
        m_x *= -1.0;
        m_vx *= -1.0;
    }
    if (m_x + width() > m_gameField->width())
    {
        m_x = m_gameField->width() - width();
        m_vx *= -1.0;
    }

    if (m_y < 0)
    {
        m_y *= -1.0;
        m_vy *= -1.0;
    }
    if (m_y + height() > m_gameField->height())
    {
        m_y = m_gameField->height() - height();
        m_vy *= -1.0;
    }

    move(m_x, m_y);
        m_vx *= 0.98;
    m_vy *= 0.98;
}

int AbstractSheep::vx() const
{
    return m_vx;
}

void AbstractSheep::setVx(int vx)
{
    m_vx = vx;
}
int AbstractSheep::vy() const
{
    return m_vy;
}

void AbstractSheep::setVy(int vy)
{
    m_vy = vy;
}

double AbstractSheep::y() const
{
    return m_y;
}

void AbstractSheep::setY(double y)
{
    m_y = y;
    move(m_x, m_y);
}

void AbstractSheep::setPos(double x, double y)
{
    m_x = x;
    m_y = y;
    move(m_x, m_y);
    qDebug() << x << y;
}

double AbstractSheep::x() const
{
    return m_x;
}

void AbstractSheep::setX(double x)
{
    m_x = x;
    move(m_x, m_y);
}



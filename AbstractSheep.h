#ifndef ABSTRACTSHEEP_H
#define ABSTRACTSHEEP_H

#include <QWidget>

class GameField;

class AbstractSheep : public QWidget
{
public:
    explicit AbstractSheep(QWidget *parent = 0);

    void setGameField(GameField *gamefield);

    virtual bool tick();

    int vx() const;
    void setVx(int vx);

    int vy() const;
    void setVy(int vy);

    GameField *m_gameField;
    double m_vx, m_vy;
    double m_x, m_y;

    double x() const;
    void setX(double x);
    double y() const;
    void setY(double y);
    void setPos(double x, double y);
};

#endif // ABSTRACTSHEEP_H

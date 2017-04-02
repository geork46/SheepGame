#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QWidget>
#include <QRegion>
#include <QVector>

#include <QTimer>

class AbstractSheep;

struct AreaParametrs
{
    double c;
};

class GameField : public QWidget
{
Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);

    void setSheep(AbstractSheep *sheep);
    void addArea(QRegion region,  AreaParametrs params);
    void setBorder(const QVector<QPoint> &points);

    void tick();
    void run();

    const QVector<QPoint>* points() const;

private slots:
    void onTimer();
    void onTimer2();

protected:
    void paintEvent(QPaintEvent *e);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:
    QPoint m_startPoint;
    QPoint m_point;
    QPoint m_newPoint;
    bool m_isMooving;

    AbstractSheep* m_sheep;
    QVector<QPoint> m_points;
    QTimer m_timer;
    QTimer m_timer2;
};

#endif // GAMEFIELD_H

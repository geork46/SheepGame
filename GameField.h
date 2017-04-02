#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QWidget>
#include <QRegion>
#include <QVector>
#include <QMap>

#include <QTimer>



class AbstractSheep;

struct AreaParametrs
{
    enum TypeArea
    {
        ICE_HOLE_AREA = 0
    };
    TypeArea type;
};

class GameField : public QWidget
{
Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);
    ~GameField();

    void setSheep(AbstractSheep *sheep);
    void addArea(QRegion * region,  AreaParametrs params);
    void setBorder(const QVector<QPoint> &points);

    void gameOver();
    void youWin();

    void tick();
    void run();
    void decCount();

    const QVector<QPoint>* points() const;


    QList<QWidget*>* getSweets();

signals:
    void countsChanged(int n);

private slots:
    void onTimer();
    void onTimer2();

protected:
    void paintEvent(QPaintEvent *e);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:
    void generateSweets();
    void generateIceHole();


    static bool m_sweetsGenerated;
    QList<QWidget*> m_sweets;

    int m_count;

    QPoint m_startPoint;
    QPoint m_point;
    QPoint m_newPoint;
    bool m_isMooving;

    AbstractSheep* m_sheep;
    QVector<QPoint> m_points;
    QMap<QRegion*, AreaParametrs> m_areas;
    QTimer m_timer;
    QTimer m_timer2;
};

#endif // GAMEFIELD_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



private slots:
    void onClose();
    void countChanged(int n);

private:
    Ui::Widget *ui;
    QWidget *e;
    QTimer m_timer;
    int m_da;
};

#endif // WIDGET_H

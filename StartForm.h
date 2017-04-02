#ifndef STARTFORM_H
#define STARTFORM_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class StartForm;
}

class StartForm : public QWidget
{
    Q_OBJECT

public:
    explicit StartForm(QWidget *parent = 0);
    ~StartForm();

protected:
    void paintEvent(QPaintEvent *e);
private slots:
    void on_playButton_clicked();
    void onTimer();

private:
    Ui::StartForm *ui;
    QTimer m_timer;
};

#endif // STARTFORM_H

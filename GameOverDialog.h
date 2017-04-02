#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverDialog(QWidget *parent = 0);
    explicit GameOverDialog(bool l, QWidget *parent = 0);
    ~GameOverDialog();

private slots:
    void on_exitButton_clicked();

    void on_NewGameButton_clicked();

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_H

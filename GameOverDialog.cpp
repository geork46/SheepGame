#include "GameOverDialog.h"
#include "ui_GameOverDialog.h"
#include "QApplication"
#include "widget.h"

GameOverDialog::GameOverDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
}

GameOverDialog::GameOverDialog(bool l, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
    ui->textLabel->setText("Поздравляем! Вы победили!");
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

void GameOverDialog::on_exitButton_clicked()
{
    qApp->exit();
}

void GameOverDialog::on_NewGameButton_clicked()
{
    Widget *w = new Widget(0);
    w->show();
    close();
}

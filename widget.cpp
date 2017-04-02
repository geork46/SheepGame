#include "widget.h"
#include "ui_widget.h"


#include <QPainter>
#include <QPalette>
#include <QDebug>

#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_da = 1;

    ui->gameWidget->setSheep(ui->sheepWidget);
    ui->gameWidget->setObjectName("ice");
    ui->sheepWidget->setObjectName("sheep");

    ui->borderWidget1->setObjectName("border");
    ui->borderWidget2->setObjectName("border");
    ui->borderWidget3->setObjectName("border");
    ui->borderWidget4->setObjectName("border");

}

Widget::~Widget()
{
    delete ui;
}



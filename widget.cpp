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


    ui->snowWidget->setObjectName("snow");
    ui->snowWidget2->setObjectName("snow");
    ui->snowWidget3->setObjectName("snow");
    ui->snowWidget4->setObjectName("snow");
    ui->snowWidget5->setObjectName("snow");
    ui->snowWidget6->setObjectName("snow");


    ui->treeWidget->setObjectName("tree");

}

Widget::~Widget()
{
    delete ui;
}



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

}

Widget::~Widget()
{
    delete ui;
}



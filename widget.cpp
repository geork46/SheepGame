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

    QRect *r = new QRect(400, 300, 128, 128);
    QRegion *reg = new QRegion(*r);
    AreaParametrs a;
    a.type = AreaParametrs::ICE_HOLE_AREA;
    ui->gameWidget->addArea(reg, a);

//    QVector<QPoint> lines;
//    lines.append(QPoint(10, 210));
//    lines.append(QPoint(210, 210));
//    lines.append(QPoint(210, 210));
//    lines.append(QPoint(210, 510));
//    lines.append(QPoint(210, 510));
//    lines.append(QPoint(550, 510));

//    ui->gameWidget->setBorder(lines);

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

    connect(ui->gameWidget, SIGNAL(destroyed(QObject*)), this, SLOT(onClose()));
    connect(ui->gameWidget, SIGNAL(countsChanged(int)), this, SLOT(countChanged(int)));
    move(100, 60);
    resize(1600, 900);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClose()
{
    close();
}

void Widget::countChanged(int n)
{
    ui->numberLabel->setText(QString::number(n));
}



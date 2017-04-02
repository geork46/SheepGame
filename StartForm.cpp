#include "StartForm.h"
#include "ui_StartForm.h"

#include "widget.h"

#include <QStyleOption>
#include <QPainter>

StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);
    m_timer.setSingleShot(false);
    m_timer.setInterval(800);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    m_timer.start();
}

StartForm::~StartForm()
{
    delete ui;
}

void StartForm::paintEvent(QPaintEvent *e)
{
    QStyleOption o;
  o.initFrom(this);
  QPainter p(this);

  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);

}

void StartForm::on_playButton_clicked()
{
    Widget *w = new Widget(0);
    w->show();
    close();
}

void StartForm::onTimer()
{
    static bool i;
    if (i)
    {
        setStyleSheet(""
                      ""
                      "QWidget#sheepWidget {"
                      "background-image:url(:/main/texture/Titul/ce/tit_ships_ce.png) stretch;"
                      "}"
                      ""
                      ""
                      "");
    m_timer.setInterval(600);
    } else
    {
        setStyleSheet(""
                      ""
                      "QWidget#sheepWidget {"
                      "background-image:url(:/main/texture/Titul/ce/tit_ships_e.png) stretch;"
                      "}"
                      ""
                      ""
                      "");
    m_timer.setInterval(1200);

    }
    i = !i;

}

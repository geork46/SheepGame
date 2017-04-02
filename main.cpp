#include "widget.h"
#include "GameField.h"
#include "AbstractSheep.h"
#include "SheepTypeA.h"

#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    GameField gf;


//    gf.setObjectName("ice");

//    QVector<QPoint> lines;
//    lines.append(QPoint(10, 10));
//    lines.append(QPoint(10, 500));
//    lines.append(QPoint(10, 500));
//    lines.append(QPoint(500, 10));
//    lines.append(QPoint(500, 10));
//    lines.append(QPoint(10, 10));

//    gf.setBorder(lines);

//    SheepTypeA as;
//    as.setObjectName("sheep");


//    gf.resize(500, 500);

//    gf.addSheep(&as);
//    as.setVx(10);
//    as.setVy(10);
//    as.resize(100, 120);
//    as.setMinimumHeight(100);
//    as.setMinimumWidth(100);
//    as.setX(100);
//    as.setY(100);
////    as.move(150, 150);

//    gf.show();
//    gf.run();

    Widget w;
    w.show();




    a.setStyleSheet(""
                    "QWidget#hand {"
                    "background:url(/home/info/Рабочий стол/texture/Sheep/Move/drop2.png);"
                    "}"
                    "QWidget#tree {"
                    "background:url(/home/info/Рабочий стол/texture/Snow/Snow_wood.jpg);"
                    "}"
                    "QWidget#snow {"
                    "background:url(/home/info/Рабочий стол/texture/Snow/Snow_300.jpg);"
                    "}"
                    "QWidget#ice {"
                    "background:url(/home/info/Рабочий стол/texture/Ice/Ice.jpg);"
                    "}"
                    "QWidget#sheep {"
                    "background:url(\":img/texture/Rosy_sheep/Real_run_small/rosy_step_0.png\");"
                    "}"
                    "QWidget#border {"
                    "background:url(/home/info/QtCreatorProject/SheepGame/texture/fence/Snow_fence_300.png);"
                    "}"
                    ""
                    "");

    return a.exec();
}

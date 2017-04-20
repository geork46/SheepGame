#include "widget.h"
#include "GameField.h"
#include "AbstractSheep.h"
#include "SheepTypeA.h"
#include "StartForm.h"

#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    StartForm sf;
    sf.setObjectName("mainForm");
    sf.show();


//    Widget w;
//    w.show();




    a.setStyleSheet(""
                    "QWidget#mainForm {"
                    "background-image:url(:/main/texture/Titul/Fon/fon.png) stretch;"
                    "background-repeat: no-repeat;"
                    "background-attachment: scroll;"
                    "}"

                    "QPushButton#playButton {"
                    "background-color:transparent;"
                    "background-image:url(:/main/texture/Titul/Play/play_00.png);"
                    "}"
                    "QPushButton#playButton:pressed {"
                    "background-color:transparent;"
                    "border-width:0;"
                    "border-style:none;"
                    "background:url(:/main/texture/Titul/Play/play_01.png);"
                    "}"
                    "QWidget#sheepWidget {"
                    "background-image:url(:/main/texture/Titul/ce/tit_ships_e.png) stretch;"
                    "}"
                    "QWidget#hand {"
                    "background:url(:/last/texture/Sheep/Move/drop.png);"
                    "}"
                    "QWidget#tree {"
                    "background:url(:/last/texture/Snow/Snow_wood.jpg);"
                    "}"
                    "QWidget#snow {"
                    "background:url(:/last/texture/Snow/Snow_300.jpg);"
                    "}"
                    "QWidget#ice {"
                    "background:url(:/last/texture/Ice/Ice.jpg);"
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

#ifndef SHEEPTYPEA_H
#define SHEEPTYPEA_H

#include "AbstractSheep.h"

class SheepTypeA : public AbstractSheep
{
public:
    SheepTypeA(QWidget *parent = 0);

    bool tick();
};

#endif // SHEEPTYPEA_H

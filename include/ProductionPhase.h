#ifndef PRODUCTIONPHASE_H
#define PRODUCTIONPHASE_H

#include "WorkGroup.h"

class ProductionPhase : public WorkGroup
{
public:
    ProductionPhase(const std::string& name);
    ~ProductionPhase();
};

#endif
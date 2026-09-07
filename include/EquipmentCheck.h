#ifndef EQUIPMENTCHECK_H
#define EQUIPMENTCHECK_H

#include "WorkItemDecorator.h"

class EquipmentCheck : public WorkItemDecorator
{
public:
    EquipmentCheck(WorkItem* component);
    ~EquipmentCheck();

    void process() override;
};

#endif
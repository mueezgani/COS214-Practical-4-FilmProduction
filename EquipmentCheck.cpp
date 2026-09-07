#include "EquipmentCheck.h"
#include <iostream>

EquipmentCheck::EquipmentCheck(WorkItem* component)
    : WorkItemDecorator(component)
{
}

EquipmentCheck::~EquipmentCheck()
{
}

void EquipmentCheck::process()
{
    std::cout << "Performing equipment check for: "
              << getName()
              << std::endl;

    WorkItemDecorator::process();
}
#include "../include/SafetyCheck.h"
#include <iostream>

SafetyCheck::SafetyCheck(WorkItem* component)
    : WorkItemDecorator(component)
{
}

SafetyCheck::~SafetyCheck()
{
}

void SafetyCheck::process()
{
    std::cout << "Performing safety check for: "
              << getName()
              << std::endl;

    WorkItemDecorator::process();
}
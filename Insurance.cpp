#include "Insurance.h"
#include <iostream>

Insurance::Insurance(WorkItem* component)
    : WorkItemDecorator(component)
{
}

Insurance::~Insurance()
{
}

void Insurance::process()
{
    std::cout << "Verifying insurance for: "
              << getName()
              << std::endl;

    WorkItemDecorator::process();
}
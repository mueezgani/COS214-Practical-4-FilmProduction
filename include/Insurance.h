#ifndef INSURANCE_H
#define INSURANCE_H

#include "WorkItemDecorator.h"

class Insurance : public WorkItemDecorator
{
public:
    Insurance(WorkItem* component);
    ~Insurance();

    void process() override;
};

#endif
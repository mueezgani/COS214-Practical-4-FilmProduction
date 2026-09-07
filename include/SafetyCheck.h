#ifndef SAFETYCHECK_H
#define SAFETYCHECK_H

#include "WorkItemDecorator.h"

class SafetyCheck : public WorkItemDecorator
{
public:
    SafetyCheck(WorkItem* component);
    ~SafetyCheck();

    void process() override;
};

#endif
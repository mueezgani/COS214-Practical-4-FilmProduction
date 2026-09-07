#ifndef WORKITEMDECORATOR_H
#define WORKITEMDECORATOR_H

#include "WorkItem.h"

class WorkItemDecorator : public WorkItem
{
protected:
    WorkItem* component;

public:
    WorkItemDecorator(WorkItem* component);
    virtual ~WorkItemDecorator();

    void process() override;
    std::string getName() const override;
    Priority getPriority() const override;
};

#endif
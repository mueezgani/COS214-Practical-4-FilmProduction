#ifndef WORKITEM_H
#define WORKITEM_H

#include <string>
#include "Priority.h"

class WorkItem
{
public:
    virtual ~WorkItem() {}

    virtual void process() = 0;
    virtual std::string getName() const = 0;
    virtual Priority getPriority() const = 0;
};

#endif
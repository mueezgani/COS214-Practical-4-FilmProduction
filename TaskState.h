#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>

class ProductionTask;

class TaskState
{
public:
    virtual ~TaskState() {}

    virtual void start(ProductionTask* task) = 0;
    virtual void block(ProductionTask* task) = 0;
    virtual void resume(ProductionTask* task) = 0;
    virtual void complete(ProductionTask* task) = 0;
    virtual void cancel(ProductionTask* task) = 0;

    virtual std::string getName() const = 0;
};

#endif
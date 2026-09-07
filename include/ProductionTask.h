#ifndef PRODUCTIONTASK_H
#define PRODUCTIONTASK_H

#include <string>
#include "WorkItem.h"

class TaskState;

class ProductionTask : public WorkItem
{
private:
    std::string name;
    Priority priority;
    TaskState* state;

public:
    ProductionTask(const std::string& name, Priority priority);
    ~ProductionTask();

    void process() override;
    std::string getName() const override;
    Priority getPriority() const override;

    void start();
    void block();
    void resume();
    void complete();
    void cancel();
    void setState(TaskState* newState);
    TaskState* getState() const;
};

#endif
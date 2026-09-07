#ifndef CANCELLED_H
#define CANCELLED_H

#include "TaskState.h"

class Cancelled : public TaskState
{
public:
    void start(ProductionTask* task) override;
    void block(ProductionTask* task) override;
    void resume(ProductionTask* task) override;
    void complete(ProductionTask* task) override;
    void cancel(ProductionTask* task) override;

    std::string getName() const override;
};

#endif
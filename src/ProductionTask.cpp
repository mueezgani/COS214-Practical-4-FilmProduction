#include "../include/ProductionTask.h"
#include "../include/TaskState.h"
#include "../include/Planned.h"

#include <iostream>

ProductionTask::ProductionTask(const std::string& name, Priority priority)
    : name(name), priority(priority), state(new Planned())
{
}

ProductionTask::~ProductionTask()
{
    delete state;
}

void ProductionTask::process()
{
    std::cout << "Processing task: "
              << name
              << " | Priority: "
              << static_cast<int>(priority)
              << " | State: "
              << state->getName()
              << std::endl;
}

std::string ProductionTask::getName() const
{
    return name;
}

Priority ProductionTask::getPriority() const
{
    return priority;
}

void ProductionTask::start()
{
    state->start(this);
}

void ProductionTask::block()
{
    state->block(this);
}

void ProductionTask::resume()
{
    state->resume(this);
}

void ProductionTask::complete()
{
    state->complete(this);
}

void ProductionTask::cancel()
{
    state->cancel(this);
}

void ProductionTask::setState(TaskState* newState)
{
    TaskState* oldState = state;
    state = newState;
    delete oldState;
}

TaskState* ProductionTask::getState() const
{
    return state;
}
#include "InProgress.h"
#include "ProductionTask.h"
#include "Blocked.h"
#include "Completed.h"
#include "Cancelled.h"

#include <iostream>

void InProgress::start(ProductionTask* task)
{
    std::cout << task->getName()
              << " is already in progress."
              << std::endl;
}

void InProgress::block(ProductionTask* task)
{
    std::cout << task->getName()
              << " has been blocked."
              << std::endl;

    task->setState(new Blocked());
}

void InProgress::resume(ProductionTask* task)
{
    std::cout << task->getName()
              << " is already in progress."
              << std::endl;
}

void InProgress::cancel(ProductionTask* task)
{
    std::cout << task->getName()
              << " has been cancelled."
              << std::endl;

    task->setState(new Cancelled());
}

void InProgress::complete(ProductionTask* task)
{
    std::cout << task->getName()
              << " has been completed."
              << std::endl;

    task->setState(new Completed());
}

std::string InProgress::getName() const
{
    return "In Progress";
}
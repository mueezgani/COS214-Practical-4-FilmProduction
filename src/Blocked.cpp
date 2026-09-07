#include "../include/Blocked.h"
#include "../include/ProductionTask.h"
#include "../include/InProgress.h"
#include "../include/Cancelled.h"

#include <iostream>

void Blocked::start(ProductionTask* task)
{
    std::cout << "Cannot start "
              << task->getName()
              << " because it is blocked."
              << std::endl;
}

void Blocked::block(ProductionTask* task)
{
    std::cout << task->getName()
              << " is already blocked."
              << std::endl;
}

void Blocked::resume(ProductionTask* task)
{
    std::cout << task->getName()
              << " has resumed."
              << std::endl;

    task->setState(new InProgress());
}

void Blocked::cancel(ProductionTask* task)
{
    std::cout << task->getName()
              << " has been cancelled."
              << std::endl;

    task->setState(new Cancelled());
}

void Blocked::complete(ProductionTask* task)
{
    std::cout << "Cannot complete "
              << task->getName()
              << " while it is blocked."
              << std::endl;
}

std::string Blocked::getName() const
{
    return "Blocked";
}
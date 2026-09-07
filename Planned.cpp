#include "Planned.h"
#include "ProductionTask.h"
#include "InProgress.h"
#include "Cancelled.h"

#include <iostream>

void Planned::start(ProductionTask* task)
{
    std::cout << task->getName()
              << " started." << std::endl;

    task->setState(new InProgress());
}

void Planned::block(ProductionTask* task)
{
    std::cout << "Cannot block "
              << task->getName()
              << " because it has not started."
              << std::endl;
}

void Planned::resume(ProductionTask* task)
{
    std::cout << "Cannot resume "
              << task->getName()
              << " because it has not started."
              << std::endl;
}

void Planned::cancel(ProductionTask* task)
{
    std::cout << task->getName()
              << " has been cancelled."
              << std::endl;

    task->setState(new Cancelled());
}

void Planned::complete(ProductionTask* task)
{
    std::cout << "Cannot complete "
              << task->getName()
              << " because it has not started."
              << std::endl;
}

std::string Planned::getName() const
{
    return "Planned";
}
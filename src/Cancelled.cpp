#include "../include/Cancelled.h"
#include "../include/ProductionTask.h"

#include <iostream>

void Cancelled::start(ProductionTask* task)
{
    std::cout << "Cannot start "
              << task->getName()
              << " because it has been cancelled."
              << std::endl;
}

void Cancelled::block(ProductionTask* task)
{
    std::cout << "Cannot block "
              << task->getName()
              << " because it has been cancelled."
              << std::endl;
}

void Cancelled::resume(ProductionTask* task)
{
    std::cout << "Cannot resume "
              << task->getName()
              << " because it has been cancelled."
              << std::endl;
}

void Cancelled::complete(ProductionTask* task)
{
    std::cout << "Cannot complete "
              << task->getName()
              << " because it has been cancelled."
              << std::endl;
}

void Cancelled::cancel(ProductionTask* task)
{
    std::cout << task->getName()
              << " is already cancelled."
              << std::endl;
}

std::string Cancelled::getName() const
{
    return "Cancelled";
}
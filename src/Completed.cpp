#include "../include/Completed.h"
#include "../include/ProductionTask.h"

#include <iostream>

void Completed::start(ProductionTask* task)
{
    std::cout << "Cannot start "
              << task->getName()
              << " because it is already completed."
              << std::endl;
}

void Completed::block(ProductionTask* task)
{
    std::cout << "Cannot block "
              << task->getName()
              << " because it is already completed."
              << std::endl;
}

void Completed::resume(ProductionTask* task)
{
    std::cout << "Cannot resume "
              << task->getName()
              << " because it is already completed."
              << std::endl;
}

void Completed::cancel(ProductionTask* task)
{
    std::cout << "Cannot cancel "
              << task->getName()
              << " because it is already completed."
              << std::endl;
}

void Completed::complete(ProductionTask* task)
{
    std::cout << task->getName()
              << " is already completed."
              << std::endl;
}

std::string Completed::getName() const
{
    return "Completed";
}
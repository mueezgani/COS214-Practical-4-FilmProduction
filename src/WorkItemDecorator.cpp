#include "../include/WorkItemDecorator.h"

WorkItemDecorator::WorkItemDecorator(WorkItem* component)
    : component(component)
{
}

WorkItemDecorator::~WorkItemDecorator()
{
    delete component;
}

void WorkItemDecorator::process()
{
    if (component != nullptr)
    {
        component->process();
    }
}

std::string WorkItemDecorator::getName() const
{
    if (component != nullptr)
    {
        return component->getName();
    }

    return "";
}

Priority WorkItemDecorator::getPriority() const
{
    if (component != nullptr)
    {
        return component->getPriority();
    }

    return Priority::LOW;
}
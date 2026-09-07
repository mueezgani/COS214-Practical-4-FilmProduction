#include "WorkGroup.h"

#include <algorithm>
#include <iostream>

WorkGroup::WorkGroup(const std::string& name)
    : name(name)
{
}

WorkGroup::~WorkGroup()
{
    for (WorkItem* item : children)
    {
        delete item;
    }
}

void WorkGroup::add(WorkItem* item)
{
    if (item != nullptr)
    {
        children.push_back(item);
    }
}

void WorkGroup::remove(WorkItem* item)
{
    auto it = std::find(children.begin(), children.end(), item);

    if (it != children.end())
    {
        children.erase(it);
    }
}

WorkItem* WorkGroup::getChild(int index) const
{
    if (index < 0 || index >= static_cast<int>(children.size()))
    {
        return nullptr;
    }

    return children[index];
}

void WorkGroup::process()
{
    std::cout << "Processing group: " << name << std::endl;

    for (WorkItem* item : children)
    {
        item->process();
    }
}

std::string WorkGroup::getName() const
{
    return name;
}

Priority WorkGroup::getPriority() const
{
    Priority highest = Priority::LOW;

    for (WorkItem* item : children)
    {
        if (static_cast<int>(item->getPriority()) >
            static_cast<int>(highest))
        {
            highest = item->getPriority();
        }
    }

    return highest;
}
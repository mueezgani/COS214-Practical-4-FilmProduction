#include "../include/PriorityIterator.h"
#include "../include/WorkGroup.h"

#include <algorithm>

PriorityIterator::PriorityIterator(WorkItem* root)
    : currentIndex(0)
{
    buildTraversal(root);

    std::stable_sort(
        items.begin(),
        items.end(),
        [](WorkItem* a, WorkItem* b)
        {
            return static_cast<int>(a->getPriority()) >
                   static_cast<int>(b->getPriority());
        }
    );
}

PriorityIterator::PriorityIterator(
    const std::vector<ProductionPhase*>& phases
)
    : currentIndex(0)
{
    for (ProductionPhase* phase : phases)
    {
        buildTraversal(phase);
    }

    std::stable_sort(
        items.begin(),
        items.end(),
        [](WorkItem* a, WorkItem* b)
        {
            return static_cast<int>(a->getPriority()) >
                   static_cast<int>(b->getPriority());
        }
    );
}

PriorityIterator::~PriorityIterator()
{
    // Iterator does not own the WorkItems.
}

void PriorityIterator::buildTraversal(WorkItem* item)
{
    if (item == nullptr)
    {
        return;
    }

    WorkGroup* group = dynamic_cast<WorkGroup*>(item);

    if (group != nullptr)
    {
        int index = 0;
        WorkItem* child = group->getChild(index);

        while (child != nullptr)
        {
            buildTraversal(child);

            index++;
            child = group->getChild(index);
        }
    }
    else
    {
        items.push_back(item);
    }
}

bool PriorityIterator::hasNext() const
{
    return currentIndex < items.size();
}

WorkItem* PriorityIterator::next()
{
    if (!hasNext())
    {
        return nullptr;
    }

    return items[currentIndex++];
}

void PriorityIterator::reset()
{
    currentIndex = 0;
}
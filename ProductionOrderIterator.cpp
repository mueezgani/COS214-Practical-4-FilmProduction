#include "ProductionOrderIterator.h"
#include "WorkGroup.h"

ProductionOrderIterator::ProductionOrderIterator(WorkItem* root)
    : currentIndex(0)
{
    buildTraversal(root);
}

ProductionOrderIterator::ProductionOrderIterator(
    const std::vector<ProductionPhase*>& phases
)
    : currentIndex(0)
{
    for (ProductionPhase* phase : phases)
    {
        buildTraversal(phase);
    }
}

ProductionOrderIterator::~ProductionOrderIterator()
{

}

void ProductionOrderIterator::buildTraversal(WorkItem* item)
{
    if (item == nullptr)
    {
        return;
    }

    items.push_back(item);


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
}

bool ProductionOrderIterator::hasNext() const
{
    return currentIndex < items.size();
}

WorkItem* ProductionOrderIterator::next()
{
    if (!hasNext())
    {
        return nullptr;
    }

    return items[currentIndex++];
}

void ProductionOrderIterator::reset()
{
    currentIndex = 0;
}
#ifndef PRIORITYITERATOR_H
#define PRIORITYITERATOR_H

#include <vector>
#include <cstddef>

#include "WorkIterator.h"
#include "WorkItem.h"
#include "ProductionPhase.h"

class PriorityIterator : public WorkIterator
{
private:
    std::vector<WorkItem*> items;
    std::size_t currentIndex;

    void buildTraversal(WorkItem* item);

public:
    PriorityIterator(WorkItem* root);

    PriorityIterator(
        const std::vector<ProductionPhase*>& phases
    );

    ~PriorityIterator();

    bool hasNext() const override;
    WorkItem* next() override;
    void reset() override;
};

#endif
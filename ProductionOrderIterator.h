#ifndef PRODUCTIONORDERITERATOR_H
#define PRODUCTIONORDERITERATOR_H

#include <vector>
#include <cstddef>

#include "WorkIterator.h"
#include "WorkItem.h"
#include "ProductionPhase.h"

class ProductionOrderIterator : public WorkIterator
{
private:
    std::vector<WorkItem*> items;
    std::size_t currentIndex;

    void buildTraversal(WorkItem* item);

public:
    ProductionOrderIterator(WorkItem* root);

    ProductionOrderIterator(
        const std::vector<ProductionPhase*>& phases
    );

    ~ProductionOrderIterator();

    bool hasNext() const override;
    WorkItem* next() override;
    void reset() override;
};

#endif
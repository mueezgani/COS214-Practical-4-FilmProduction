#ifndef FILMPRODUCTION_H
#define FILMPRODUCTION_H

#include <string>
#include <vector>

#include "ProductionPhase.h"
#include "WorkIterator.h"

class FilmProduction
{
private:
    std::string name;
    std::vector<ProductionPhase*> phases;

public:
    FilmProduction(const std::string& name);
    ~FilmProduction();

    void addPhase(ProductionPhase* phase);
    void removePhase(ProductionPhase* phase);

    ProductionPhase* getPhase(int index) const;

    WorkIterator* createProductionOrderIterator() const;
    WorkIterator* createPriorityIterator() const;
};

#endif
#include "FilmProduction.h"
#include "ProductionOrderIterator.h"
#include "PriorityIterator.h"

#include <algorithm>

FilmProduction::FilmProduction(const std::string& name)
    : name(name)
{
}

FilmProduction::~FilmProduction()
{
    for (ProductionPhase* phase : phases)
    {
        delete phase;
    }
}

void FilmProduction::addPhase(ProductionPhase* phase)
{
    if (phase != nullptr)
    {
        phases.push_back(phase);
    }
}

void FilmProduction::removePhase(ProductionPhase* phase)
{
    auto it = std::find(phases.begin(), phases.end(), phase);

    if (it != phases.end())
    {
        phases.erase(it);
    }
}

ProductionPhase* FilmProduction::getPhase(int index) const
{
    if (index < 0 || index >= static_cast<int>(phases.size()))
    {
        return nullptr;
    }

    return phases[index];
}

WorkIterator* FilmProduction::createProductionOrderIterator() const
{
    return new ProductionOrderIterator(phases);
}

WorkIterator* FilmProduction::createPriorityIterator() const
{
    return new PriorityIterator(phases);
}
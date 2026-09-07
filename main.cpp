#include <iostream>

#include "include/FilmProduction.h"
#include "include/ProductionPhase.h"
#include "include/Scene.h"
#include "include/ProductionTask.h"

#include "include/WorkIterator.h"

#include "include/EquipmentCheck.h"
#include "include/SafetyCheck.h"
#include "include/Insurance.h"

int main()
{
    std::cout << "=== FILM PRODUCTION TEST ===" << std::endl;

    FilmProduction* filmProduction =
        new FilmProduction("TaskForge Film");

    ProductionPhase* production =
        new ProductionPhase("Production");

    Scene* openingScene =
        new Scene("Opening Scene");

    Scene* climaxScene =
        new Scene("Climax Scene");

    ProductionTask* filming =
        new ProductionTask(
            "Film Opening Scene",
            Priority::HIGH
        );

    ProductionTask* lighting =
        new ProductionTask(
            "Set Up Lighting",
            Priority::MEDIUM
        );

    ProductionTask* dialogue =
        new ProductionTask(
            "Record Dialogue",
            Priority::HIGH
        );

    openingScene->add(filming);
    openingScene->add(lighting);

    climaxScene->add(dialogue);

    production->add(openingScene);
    production->add(climaxScene);

    filmProduction->addPhase(production);

    std::cout
        << "\n=== COMPOSITE HIERARCHY ==="
        << std::endl;

    production->process();

    std::cout
        << "\n=== STATE TEST ==="
        << std::endl;

    std::cout << "\nStarting filming..." << std::endl;
    filming->start();

    std::cout << "\nBlocking filming..." << std::endl;
    filming->block();

    std::cout
        << "\nTrying to complete while blocked..."
        << std::endl;

    filming->complete();

    std::cout << "\nResuming filming..." << std::endl;
    filming->resume();

    std::cout << "\nCompleting filming..." << std::endl;
    filming->complete();

    std::cout
        << "\nTrying to start completed task..."
        << std::endl;

    filming->start();

    std::cout
        << "\n=== CANCELLATION TEST ==="
        << std::endl;

    lighting->cancel();

    std::cout
        << "\nTrying to start cancelled task..."
        << std::endl;

    lighting->start();

    std::cout
        << "\n=== PRODUCTION ORDER ITERATOR ==="
        << std::endl;

    WorkIterator* productionIterator =
        filmProduction->createProductionOrderIterator();

    while (productionIterator->hasNext())
    {
        WorkItem* item = productionIterator->next();

        std::cout
            << item->getName()
            << std::endl;
    }

    std::cout
        << "\n=== RESET PRODUCTION ITERATOR ==="
        << std::endl;

    productionIterator->reset();

    while (productionIterator->hasNext())
    {
        WorkItem* item = productionIterator->next();

        std::cout
            << item->getName()
            << std::endl;
    }

    std::cout
        << "\n=== PRIORITY ITERATOR ==="
        << std::endl;

    WorkIterator* priorityIterator =
        filmProduction->createPriorityIterator();

    while (priorityIterator->hasNext())
    {
        WorkItem* item = priorityIterator->next();

        std::cout
            << item->getName()
            << " | Priority: "
            << static_cast<int>(item->getPriority())
            << std::endl;
    }

    std::cout
        << "\n=== INDEPENDENT ITERATORS ==="
        << std::endl;

    WorkIterator* iteratorOne =
        filmProduction->createProductionOrderIterator();

    WorkIterator* iteratorTwo =
        filmProduction->createProductionOrderIterator();

    if (iteratorOne->hasNext())
    {
        std::cout
            << "Iterator 1 first item: "
            << iteratorOne->next()->getName()
            << std::endl;
    }

    if (iteratorOne->hasNext())
    {
        std::cout
            << "Iterator 1 second item: "
            << iteratorOne->next()->getName()
            << std::endl;
    }

    if (iteratorTwo->hasNext())
    {
        std::cout
            << "Iterator 2 first item: "
            << iteratorTwo->next()->getName()
            << std::endl;
    }

    std::cout
        << "\n=== SNAPSHOT TEST ==="
        << std::endl;

    WorkIterator* oldIterator =
        filmProduction->createProductionOrderIterator();

    ProductionTask* cameraSetup =
        new ProductionTask(
            "Camera Setup",
            Priority::HIGH
        );

    openingScene->add(cameraSetup);

    std::cout
        << "Old iterator created BEFORE Camera Setup was added:"
        << std::endl;

    while (oldIterator->hasNext())
    {
        std::cout
            << oldIterator->next()->getName()
            << std::endl;
    }

    std::cout
        << "\nNew iterator created AFTER Camera Setup was added:"
        << std::endl;

    WorkIterator* newIterator =
        filmProduction->createProductionOrderIterator();

    while (newIterator->hasNext())
    {
        std::cout
            << newIterator->next()->getName()
            << std::endl;
    }

    std::cout
        << "\n=== DECORATOR TEST ==="
        << std::endl;

    ProductionTask* stuntTask =
        new ProductionTask(
            "Film Stunt Scene",
            Priority::HIGH
        );

    WorkItem* decoratedStunt =
        new Insurance(
            new SafetyCheck(
                new EquipmentCheck(
                    stuntTask
                )
            )
        );

    climaxScene->add(decoratedStunt);

    std::cout
        << "\nProcessing decorated task:"
        << std::endl;

    decoratedStunt->process();

    std::cout
        << "\n=== PRODUCTION ORDER AFTER CHANGES ==="
        << std::endl;

    WorkIterator* updatedOrderIterator =
        filmProduction->createProductionOrderIterator();

    while (updatedOrderIterator->hasNext())
    {
        std::cout
            << updatedOrderIterator->next()->getName()
            << std::endl;
    }

    std::cout
        << "\n=== PRIORITY ORDER AFTER CHANGES ==="
        << std::endl;

    WorkIterator* updatedPriorityIterator =
        filmProduction->createPriorityIterator();

    while (updatedPriorityIterator->hasNext())
    {
        WorkItem* item =
            updatedPriorityIterator->next();

        std::cout
            << item->getName()
            << " | Priority: "
            << static_cast<int>(item->getPriority())
            << std::endl;
    }

    std::cout
        << "\n=== FINAL PRODUCTION STATE ==="
        << std::endl;

    production->process();

    delete productionIterator;
    delete priorityIterator;
    delete iteratorOne;
    delete iteratorTwo;
    delete oldIterator;
    delete newIterator;
    delete updatedOrderIterator;
    delete updatedPriorityIterator;

    delete filmProduction;

    return 0;
}
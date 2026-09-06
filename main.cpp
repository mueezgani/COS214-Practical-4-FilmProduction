#include <iostream>
 
#include "include/FilmProduction.h"
#include "include/ProductionPhase.h"
#include "include/Scene.h"
#include "include/ProductionTask.h"
#include "include/WorkGroup.h"
 
#include "include/WorkIterator.h"
 
#include "include/EquipmentCheck.h"
#include "include/SafetyCheck.h"
#include "include/Insurance.h"
 
 
struct ProductionWorld
{
    FilmProduction* film;
    Scene* harborOpening;
    Scene* warehouseClimax;
    ProductionTask* filmOpeningScene;
    ProductionTask* setUpLighting;
    ProductionTask* recordDialogue;
    WorkItem* carStunt;
};
 
ProductionWorld buildProductionWorld()
{
    ProductionWorld world{};
 
    world.film = new FilmProduction("Midnight Harbor");
 
    ProductionPhase* preProduction = new ProductionPhase("Pre-Production");
    ProductionPhase* principalPhotography = new ProductionPhase("Principal Photography");
 
    Scene* readThrough = new Scene("Script Read-Through");
    world.harborOpening = new Scene("Harbor Opening");
    world.warehouseClimax = new Scene("Warehouse Climax");
 
    ProductionTask* tableRead = new ProductionTask("Table Read", Priority::LOW);
    world.filmOpeningScene = new ProductionTask("Film Opening Scene", Priority::HIGH);
    world.setUpLighting = new ProductionTask("Set Up Lighting", Priority::MEDIUM);
    world.recordDialogue = new ProductionTask("Record Dialogue", Priority::HIGH);
 
    ProductionTask* stuntTask = new ProductionTask("Film Car Stunt", Priority::HIGH);
    world.carStunt = new SafetyCheck(new EquipmentCheck(stuntTask));
 
    readThrough->add(tableRead);
 
    world.harborOpening->add(world.filmOpeningScene);
    world.harborOpening->add(world.setUpLighting);
 
    world.warehouseClimax->add(world.recordDialogue);
    world.warehouseClimax->add(world.carStunt);
 
    preProduction->add(readThrough);
    principalPhotography->add(world.harborOpening);
    principalPhotography->add(world.warehouseClimax);
 
    world.film->addPhase(preProduction);
    world.film->addPhase(principalPhotography);
 
    return world;
}
 
void printAll(WorkIterator* it)
{
    while (it->hasNext())
    {
        std::cout << "  " << it->next()->getName() << std::endl;
    }
}
 
void printByPriority(WorkIterator* it)
{
    while (it->hasNext())
    {
        WorkItem* item = it->next();
        std::cout << "  " << item->getName()
                   << " (priority " << static_cast<int>(item->getPriority()) << ")"
                   << std::endl;
    }
}
 
void runMorningCallScenario(ProductionWorld& world)
{
    std::cout << "\nSCENARIO 1: ROLL CALL" << std::endl;
 
    std::cout << "\nCall sheet (shooting order):" << std::endl;
    WorkIterator* callSheet = world.film->createProductionOrderIterator();
    printAll(callSheet);
    delete callSheet;
 
    std::cout << "\nMost urgent first (priority order):" << std::endl;
    WorkIterator* urgentFirst = world.film->createPriorityIterator();
    printByPriority(urgentFirst);
    delete urgentFirst;
 
    std::cout << "\nRunner and 1st AD walk the call sheet independently:" << std::endl;
    WorkIterator* runnerCopy = world.film->createProductionOrderIterator();
    WorkIterator* firstADCopy = world.film->createProductionOrderIterator();
    std::cout << "  runner sees:   " << runnerCopy->next()->getName() << std::endl;
    std::cout << "  runner sees:   " << runnerCopy->next()->getName() << std::endl;
    std::cout << "  1st AD sees:   " << firstADCopy->next()->getName() << std::endl;
    delete runnerCopy;
    delete firstADCopy;
 
    std::cout << "\nFilming the opening scene:" << std::endl;
    world.filmOpeningScene->start();
    world.filmOpeningScene->block();
    world.filmOpeningScene->complete();   // invalid: still blocked
    world.filmOpeningScene->resume();
    world.filmOpeningScene->complete();
 
    std::cout << "\nTrying to wrap lighting:" << std::endl;
    world.setUpLighting->complete();      // invalid: not started
 
    std::cout << "\nProcessing Principal Photography:" << std::endl;
    world.harborOpening->process();
    world.warehouseClimax->process();
}
 
void runMiddayDisruptionScenario(ProductionWorld& world)
{
    std::cout << "\nSCENARIO 2: DISRUPTION" << std::endl;
 
    WorkIterator* printedCallSheet = world.film->createProductionOrderIterator();
 
    std::cout << "\nWeather closes the harbor set: move lighting indoors" << std::endl;
    world.harborOpening->remove(world.setUpLighting);
    world.warehouseClimax->add(world.setUpLighting);
 
    std::cout << "\nOld call sheet:" << std::endl;
    printAll(printedCallSheet);
    delete printedCallSheet;
 
    std::cout << "\nNew call sheet:" << std::endl;
    WorkIterator* revisedCallSheet = world.film->createProductionOrderIterator();
    printAll(revisedCallSheet);
    delete revisedCallSheet;
 
    std::cout << "\nActor injury: cancelling the dialogue recording" << std::endl;
    world.recordDialogue->cancel();
    world.recordDialogue->start();        // all invalid from here
    world.recordDialogue->block();
    world.recordDialogue->resume();
    world.recordDialogue->complete();
 
    std::cout << "\nInsurer now requires sign-off" << std::endl;
    world.warehouseClimax->remove(world.carStunt);
    world.carStunt = new Insurance(world.carStunt);
    world.warehouseClimax->add(world.carStunt);
    world.warehouseClimax->process();
 
    std::cout << "\nRe-checking priority order" << std::endl;
    WorkIterator* triage = world.film->createPriorityIterator();
    printByPriority(triage);
    delete triage;
}
 
int main()
{
    std::cout << "FILM PRODUCTION" << std::endl;
 
    ProductionWorld world = buildProductionWorld();
 
    runMorningCallScenario(world);
    runMiddayDisruptionScenario(world);
 
    delete world.film;
 
    return 0;
}
 
#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class PhysicsList : public G4VModularPhysicsList
{
    public:
PhysicsList();
virtual ~PhysicsList();
void ConstructProcess();
void ConstructParticle();
void SetCuts();
};
#endif
#include "PhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

PhysicsList::PhysicsList():G4VModularPhysicsList()
{
  SetVerboseLevel(1);

  // Default physics
  RegisterPhysics(new G4DecayPhysics());

  // EM physics
  RegisterPhysics(new G4EmStandardPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());
}

PhysicsList::~PhysicsList(){}

void PhysicsList::ConstructProcess()
{
G4VModularPhysicsList::ConstructProcess();
}

void PhysicsList::ConstructParticle()
{
G4VModularPhysicsList::ConstructParticle();
}

void PhysicsList::SetCuts()
{
    G4VModularPhysicsList::SetCuts();
}
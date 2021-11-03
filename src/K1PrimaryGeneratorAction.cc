#include "K1PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleGun.hh"

K1PrimaryGeneratorAction::K1PrimaryGeneratorAction():
G4VUserPrimaryGeneratorAction(),
gps(0)
{
    gps = new G4GeneralParticleSource();
}

K1PrimaryGeneratorAction::~K1PrimaryGeneratorAction() 
{ 
    delete gps;
}

void K1PrimaryGeneratorAction:: GeneratePrimaries(G4Event* anEvent)
{
    gps -> GeneratePrimaryVertex(anEvent);
}
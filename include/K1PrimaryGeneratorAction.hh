#ifndef K1PrimaryGeneratorAction_h
#define K1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4GeneralParticleSource.hh"

class G4GeneralParticleSource;
class G4Event;
class K1PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
                 K1PrimaryGeneratorAction();
   virtual      ~K1PrimaryGeneratorAction();
   virtual void  GeneratePrimaries(G4Event*);
protected:
    G4GeneralParticleSource* gps;
};
#endif
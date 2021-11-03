#include "K1DetSD.hh"
#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "K1DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "Run.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
K1DetSD::K1DetSD(const G4String name):
G4VSensitiveDetector(name)
{

}

K1DetSD::~K1DetSD(){}

void K1DetSD::Initialize(G4HCofThisEvent*)
{
 //  for ( auto& p : particles ) { 
//    p = 0.; 
//  }
}
G4bool K1DetSD::ProcessHits(G4Step* step,G4TouchableHistory*)
{
    //Gereftan Run Barname
    Run* run = static_cast<Run*>(
    G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    //const G4VTouchable* touchable = step->GetPreStepPoint()->GetTouchable();
   G4int iz = step->GetPreStepPoint()->GetPosition().z();

    //Get Track
    G4Track* track = step->GetTrack();
    //Get Particle Definition
   const G4ParticleDefinition* particle = track->GetParticleDefinition();
    //Get Atomic Mass
    G4int mass = particle->GetAtomicMass();
    G4bool check=false;
    for(int i=0;i<particles.size();i++)
    {
      if(particles[i]==particle->GetParticleName())
      {
      check=true;
      break;
      }
    }
    if(!check)
    {
    particles.push_back(particle->GetParticleName());
    G4cout<<"Particle Name : "<<particle->GetParticleName()<<" Atomic Number :"<<
    mass<<" At Z ="<<iz/cm<<G4endl;
    }
    else
    {
      
    }
    
  
  run->AddData(iz,mass);
 //   run->AddData(dose,(G4double)iz);
    return true;
    
}
void K1DetSD::EndOfEvent(G4HCofThisEvent*)
{
    
}
#include "K1RunAction.hh"
#include "HistoManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "K1HitBase.hh"
#include "MagnetFieldSetup.hh"
#include <vector>
#include <array>
K1RunAction::K1RunAction(HistoManager* his):
G4UserRunAction()
{
G4RunManager::GetRunManager()->SetPrintProgress(1000);  
histomanager = his;   
}
K1RunAction::~K1RunAction(){}
G4Run* K1RunAction::GenerateRun()
{ 
  frun = new Run(histomanager);
  return frun;
}
void K1RunAction::BeginOfRunAction(const G4Run*)
{
histomanager->Book();
G4RunManager::GetRunManager()->SetRandomNumberStore(true);

}
void K1RunAction::EndOfRunAction(const G4Run*)
{

//MagnetFieldSetup* obj_mag = new MagnetFieldSetup();
//G4double mag =obj_mag->GetMagnetZValue();
////G4cout<<mag/tesla<<"IN TESLAS"<<G4endl;

histomanager->Save();
}

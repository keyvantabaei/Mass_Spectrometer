
#include "G4Run.hh"
#include "Run.hh"
#include "G4DataVector.hh"
#include "G4SystemOfUnits.hh"
#include "HistoManager.hh"
Run::Run(HistoManager* his):G4Run()
{
histomanager = his;
}
Run::~Run(){}
void Run::Merge(const G4Run* run)
{


}

void Run::EndOfRun()
{

}
void Run::AddData(G4double z,G4int A)
{
histomanager->FillForPDD(z,A);
}

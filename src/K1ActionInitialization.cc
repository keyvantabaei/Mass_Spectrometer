#include "K1ActionInitialization.hh"
#include "K1PrimaryGeneratorAction.hh"
#include "K1DetectorConstruction.hh"
#include "K1RunAction.hh"
#include "HistoManager.hh"
K1ActionInitialization::K1ActionInitialization():
G4VUserActionInitialization()
{
}

K1ActionInitialization::~K1ActionInitialization()
{

}

void K1ActionInitialization::Build() const
{
    HistoManager* histo = new HistoManager();
K1RunAction* runaction=new K1RunAction(histo);
SetUserAction(new K1PrimaryGeneratorAction);
SetUserAction(runaction);


}

void K1ActionInitialization::BuildForMaster() const 
{
HistoManager* histo = new HistoManager();
SetUserAction(new K1RunAction(histo));
}
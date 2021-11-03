#include "K1DetectorConstruction.hh"
#include "K1ActionInitialization.hh"
#include "PhysicsList.hh"
//#ifdef G4MULTITHREADED
//#include "G4MTRunManager.hh"
//#else
#include "G4RunManager.hh"
//#endif

#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Randomize.hh"
#include "FTFP_BERT.hh"
int main(int argc,char** argv)
{

 G4UIExecutive* ui = nullptr;;
 if(argc==1) { ui = new G4UIExecutive(argc,argv); }

 G4Random::setTheEngine(new CLHEP::RanecuEngine);

//#ifdef G4MULTITHREADED
//G4MTRunManager* runmanager = new G4MTRunManager;
//#else
 G4RunManager* runmanager   = new G4RunManager;
//#endif

 runmanager->SetUserInitialization(new K1DetectorConstruction());
runmanager->SetUserInitialization(new PhysicsList());

runmanager->SetUserInitialization(new K1ActionInitialization());

G4VisManager* vis = new G4VisExecutive;
vis->Initialize();
runmanager->Initialize();
G4UImanager* uimanager = G4UImanager::GetUIpointer();
if(!ui)
{
G4String command = "/control/execute";
G4String filename = argv[1];
uimanager->ApplyCommand(command+filename);
}
else
{
    uimanager->ApplyCommand("/control/execute vis.mac");
  ui->SessionStart();
delete ui;
    
  
}

delete vis;
delete runmanager;
return 0;
}
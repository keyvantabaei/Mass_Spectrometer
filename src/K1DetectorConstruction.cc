#include "K1DetectorConstruction.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4PVPlacement.hh"
#include "K1DetSD.hh"
#include "G4SDManager.hh"
#include "MagnetFieldSetup.hh"
#include "G4AutoDelete.hh"
#include "ElectricFieldSetup.hh"
K1DetectorConstruction::K1DetectorConstruction():
G4VUserDetectorConstruction(),
magnet_logic(0),
elec_logic(0)
{}

K1DetectorConstruction::~K1DetectorConstruction(){}

G4VPhysicalVolume* K1DetectorConstruction:: Construct()
{
//Material Define
 G4NistManager* nist  = G4NistManager::Instance();
 G4Material* water    = nist->FindOrBuildMaterial("G4_WATER");
 G4Material* galactic = nist->FindOrBuildMaterial("G4_Galactic");
//Define Gas
// CL35 - CL37 -
G4double z, a, density;
G4int natoms, ncomponents;
G4String symbol, name;
a = 7*g/mole;
G4Element* cl35  = new G4Element(name="CL-35",symbol="CL-35",z= 3.,a);
a = 9*g/mole;
G4Element* cl37  = new G4Element(name="CL-37",symbol="CL-37",z= 3.,a);
density = 100*mg/cm3;
G4Material* CL = new G4Material(name="CL_GAS",density,ncomponents=2);
CL->AddElement(cl35, 70.0*perCent);
CL->AddElement(cl37, 30.0*perCent);

//end define gas

//World define
G4Box* worldbox                   = new G4Box("WORLD",0.75*m,0.75*m,0.75*m);
G4LogicalVolume* world_LOvolume      = new G4LogicalVolume(worldbox,galactic,"WORLD");
G4VPhysicalVolume* world_PHvolume = new G4PVPlacement(0,G4ThreeVector(),world_LOvolume,"WORLD",0,false,0,true);
/*
//Ion Box
G4Box* ionbox                 = new G4Box("ION",0.5*cm,0.5*cm,0.5*cm);
ion_logic = new G4LogicalVolume(ionbox,galactic,"ION");
new G4PVPlacement(0,G4ThreeVector(0.0,0,-80*cm),ion_logic,"ION",world_LOvolume,false,0,true);
*/
//Detector
G4Box* envelopebox                 = new G4Box("Detector",0.01*m,0.5*m,0.5*m);
detec_logic = new G4LogicalVolume(envelopebox,galactic,"Detector");
new G4PVPlacement(0,G4ThreeVector(-70*cm,0,0*cm),detec_logic,"Detector",world_LOvolume,false,0,true);

//Magnet
G4Box* magnet_box                 = new G4Box("MF",0.5*m,0.5*m,0.1*m);
magnet_logic = new G4LogicalVolume(magnet_box,galactic,"MF");
new G4PVPlacement(0,G4ThreeVector(0,0,0*cm),magnet_logic,"MF",world_LOvolume,false,0,true);

//Electric
G4Box* elec_box                 = new G4Box("EF",0.5*m,0.5*m,0.1*m);
elec_logic = new G4LogicalVolume(elec_box,galactic,"EF");
new G4PVPlacement(0,G4ThreeVector(0,0,-50*cm),elec_logic,"EF",world_LOvolume,false,0,true);

return world_PHvolume;
}
void K1DetectorConstruction::ConstructSDandField()
{

    G4String trackerChamberSDname = "B2/TrackerChamberSD";
  K1DetSD* aTrackerSD = new K1DetSD(trackerChamberSDname);
  G4SDManager::GetSDMpointer()->AddNewDetector(aTrackerSD);
  // Setting aTrackerSD to all logical volumes with the same name 
  // of "det".
  SetSensitiveDetector("Detector", aTrackerSD, true);


        MagnetFieldSetup* magnetfieldSetup
       = new MagnetFieldSetup();
    G4AutoDelete::Register(magnetfieldSetup); // Kernel will delete the F01FieldSetup
    //fEmFieldSetup.Put(magnetfieldSetup);
    magnet_logic->SetFieldManager(magnetfieldSetup->GetLocalFieldManager(),false);
//fasele beyne 2 electrod 20 cm ast
         ElectricFieldSetup* elecfieldSetup
       = new ElectricFieldSetup(G4ThreeVector( 0.0,0.0,800*volt/cm ));
     G4AutoDelete::Register(elecfieldSetup); // Kernel will delete the F01FieldSetup
    // fEmFieldSetup.Put(elecfieldSetup);
     elec_logic->SetFieldManager(elecfieldSetup->GetGlobalFieldManager(), true);

/*
              ElectricFieldSetup* elecfield_ion
       = new ElectricFieldSetup(G4ThreeVector( 0.0,0.0,1000000000*megavolt/cm ));
     G4AutoDelete::Register(elecfield_ion); // Kernel will delete the F01FieldSetup
    // fEmFieldSetup.Put(elecfieldSetup);
    ion_logic->SetFieldManager(elecfield_ion->GetGlobalFieldManager(), true);
    
   */
}
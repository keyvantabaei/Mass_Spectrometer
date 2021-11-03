#ifndef K1DetectorConstruction_h
#define K1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class K1DetectorConstruction : public G4VUserDetectorConstruction
{
public:
K1DetectorConstruction();
virtual ~K1DetectorConstruction();
virtual G4VPhysicalVolume* Construct();
virtual void ConstructSDandField();
G4LogicalVolume* magnet_logic;
G4LogicalVolume* elec_logic;
G4LogicalVolume* detec_logic;
G4LogicalVolume* ion_logic;
};
#endif
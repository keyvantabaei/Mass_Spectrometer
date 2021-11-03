#ifndef K1DetSD_h
#define K1DetSD_h 1

#include "G4VSensitiveDetector.hh"
#include "K1HitBase.hh"
#include <vector>
class G4Step;
class G4HCofThisEvent;
class K1DetSD : public G4VSensitiveDetector
{
public:
K1DetSD(const G4String);
virtual ~K1DetSD();
virtual void Initialize(G4HCofThisEvent*);
virtual G4bool ProcessHits(G4Step*,G4TouchableHistory*);
virtual void EndOfEvent(G4HCofThisEvent*);
private:
std::vector<G4String> particles;
};
#endif
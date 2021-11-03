#ifndef K1HitBase_h
#define K1HitBase_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class K1HitBase : public G4VHit
{
public:
//Construct and De-Construct Methods
K1HitBase();
virtual ~K1HitBase();
K1HitBase(const K1HitBase&);

//Virtual Method
virtual void Print();
virtual void Draw();

//operators
const K1HitBase& operator=(const K1HitBase&);
G4bool operator==(const K1HitBase&) const;
inline void* operator new (size_t);
inline void operator delete(void*);

//Set And Get Methods
//G4ThreeVector GetPos() const {return pos;}
G4double GetDose() const {return Dose;}
G4int GetVolumeIndex() const {return Volumeindex;}
//void SetPos(G4ThreeVector epos){pos=epos;}
void SetDose(G4double dose){Dose=dose;}
void SetVolumeIndex(G4int vi){Volumeindex=vi;}

//Variables
private:
//G4ThreeVector pos;
G4double Dose;
G4int Volumeindex;
};

typedef G4THitsCollection<K1HitBase> K1HitsCollection;
extern G4ThreadLocal G4Allocator<K1HitBase>* K1Allocator;
inline void* K1HitBase::operator new (size_t)
{
if(!K1Allocator)
K1Allocator = new G4Allocator<K1HitBase>;
return (void*)K1Allocator->MallocSingle();
}

inline void K1HitBase::operator delete(void *hit)
{
    K1Allocator->FreeSingle((K1HitBase*) hit);
}
#endif
#include "K1HitBase.hh"
#include "G4VHit.hh"
#include "G4ThreeVector.hh"
#include "G4Allocator.hh"
#include <iomanip>

G4ThreadLocal G4Allocator<K1HitBase>* K1Allocator=0;

K1HitBase::K1HitBase():G4VHit(),
Dose(0.),Volumeindex(0.)
{

}

K1HitBase::~K1HitBase(){}

K1HitBase::K1HitBase(const K1HitBase& K1BH):G4VHit()
{
    Dose = K1BH.Dose;
    //pos  = K1BH.pos;
    Volumeindex =K1BH.Volumeindex;
}
const K1HitBase& K1HitBase::operator=(const K1HitBase& K1BH)
{
    Dose = K1BH.Dose;
    //pos  = K1BH.pos;
    Volumeindex =K1BH.Volumeindex;
    return *this;
}

G4bool K1HitBase::operator==(const K1HitBase& K1BH) const
{
    return (this == &K1BH) ? true : false;
}

void K1HitBase::Print()
{
}

void K1HitBase::Draw()
{

}
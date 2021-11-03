#ifndef K1ActionInitialization_h
#define K1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class K1ActionInitialization : public G4VUserActionInitialization
{
    public:
K1ActionInitialization();
virtual ~K1ActionInitialization();    
virtual void Build() const;
virtual void BuildForMaster() const;
};
#endif
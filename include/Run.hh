#ifndef Run_h
#define Run_h 1

#include "G4Run.hh"
#include "G4DataVector.hh"
#include <array>
class HistoManager;
class Run : public G4Run
{
    public:
    Run(HistoManager*);
    virtual ~Run();
    virtual void Merge(const G4Run*);
    void EndOfRun();
    void AddData(G4double,G4int);
    std::array<G4double,250> GetDose(){return dose;}
    private:
    std::array<G4double,250>  dose;
    HistoManager* histomanager;
};

#endif
#ifndef K1RunAction_h
#define K1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "Run.hh"
#include "G4Accumulable.hh"
#include <vector>
#include <array>
//const G4int N=1;
class Run;
class HistoManager;
class K1RunAction : public G4UserRunAction
{
public:
K1RunAction(HistoManager*);
virtual ~K1RunAction();
virtual void BeginOfRunAction(const G4Run*);
virtual void EndOfRunAction(const G4Run*);
virtual G4Run* GenerateRun();
private:
Run* frun;
HistoManager* histomanager;
};
#endif
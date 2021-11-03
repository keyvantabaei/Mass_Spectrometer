#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

class TH2;
class TH1D;
class TFile;
class TTree;
class HistoManager
{
public:
 HistoManager();
~HistoManager();

void Book();
void Fill(G4double,G4double,G4double,G4double);
void Save();
void FillForPDD(G4double,G4int);
private:
G4int Zpdd;
G4double PDD;
TH2* histo;
TH1D* histo1D[1];
TFile* rootfile;
TTree* ntuple;
};
#endif
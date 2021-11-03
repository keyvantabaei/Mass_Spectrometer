#include "HistoManager.hh"
#include <TH2D.h>
#include <TFile.h>
#include <TTree.h>
//there is another way to include following header .
#include <CLHEP/Units/SystemOfUnits.h>

HistoManager::HistoManager():rootfile(0),PDD(0),ntuple(0),Zpdd(0)
{
  histo=0;
  histo1D[0]=0;
  ntuple=0; 
}

HistoManager::~HistoManager(){if(rootfile)delete rootfile;}

void HistoManager::Save()
{
    if(!rootfile)return;
    rootfile->Write();
    rootfile->Close();
}

void HistoManager::Book()
{
  //G4cout<<"File is opened"<<G4endl;
    rootfile = new TFile("R.root","RECREATE");
histo = new TH2D("h2","Edept At tissue",250,0.,250*CLHEP::mm,2000,0,2*CLHEP::gray);
histo1D[0] = new TH1D("Mass","Frequantly",269,0.,270);
//creating Ntuple
//G4cout<<"ntuple is created"<<G4endl;
ntuple = new TTree("ntuple","MS");
//E/D yani E an noe Double ast
/*
ntuple->Branch("E",&Edep,"E/D");
ntuple->Branch("Z",&Z,"Z/D");
ntuple->Branch("X",&X,"X/D");
//ntuple->Branch("Y",&Y,"Y/D");
*/
//pdd = new TTree("PDD","RR");

ntuple->Branch("A",&PDD,"A1/D");
ntuple->Branch("Z",&Zpdd,"Z1/I");

}


void HistoManager::Fill(G4double,G4double ,G4double ,G4double)
{
//G4cout<<"Baba Edep Ine :"<<edep<<G4endl;
//histo[0]->Fill(edep);
//G4cout<<"this Histo is Z:"<<depth<<"this Histo is Edep :"<<Edep<<G4endl;
//histo[0]->Fill(Edep);
}

void HistoManager::FillForPDD(G4double z,G4int A)
{
  //histo->Fill(z,pdd);
PDD=A;
Zpdd=z;
histo1D[0]->Fill(A);
//ntuple->Fill();
}
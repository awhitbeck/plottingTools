#ifndef DISSECTINGJETMET
#define DISSECTINGJETMET
#include "dissectingJetsMET.cc"
#endif

#ifndef FILLHT
#define FILLHT

#include "filler.h"
#include <iostream>
#include "TString.h"

using namespace std;

class fillHT : public filler {

public : 
  
  fillHT( dissectingJetsMET* ntuple_ , 
	  int nBins = 20 , 
	  float lowEdge = 500. , float highEdge = 1500. , 
	  TString name = "baseline" ) : filler(ntuple_)
  {
    
    histo = new TH1F("HT_"+name,"HT_"+name,nBins,lowEdge,highEdge);
    
  };
  
  bool process( ) override {

    //cout << "filling HT histo with " << ntuple->HT << endl;

    histo->Fill(ntuple->HT);

    return true;

  };

};

#endif

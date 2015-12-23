#ifndef DISSECTINGJETMET
#define DISSECTINGJETMET
#include "dissectingJetsMET.cc"
#endif

#ifndef ANALYZER
#define ANALYZER

#include "processor.h"
#include "TString.h"
#include <map>

using namespace std;

class analyzer{
  
public : 
  
  // ntuple class
  dissectingJetsMET* ntuple;

  // maintain a list of processes that should be 
  // run on each event:
  //     note, processor is a purely virtual class, 
  //     so it must be used as a pointer
  vector<processor*> processorRegistry;

  analyzer( dissectingJetsMET* ntuple_ ){
    ntuple = ntuple_ ;
  };

  ~analyzer(){};

  // push processor into registry list
  void registerProcessor( processor* p ){
    processorRegistry.push_back( p ) ;
  };

  // see implementation for notes
  void looper();

};

// function for looping over events in ntuple
// each process is called once.  If any of them 
// return false, the next event is processed. 
void analyzer::looper(){

  for( int iEvt = 0 ; iEvt < ntuple->fChain->GetEntries() ; iEvt++ ){

    ntuple->fChain->GetEntry(iEvt);
 
    // loop over all registered processors
    for( auto &processor : processorRegistry ){
      //cout << "selector: " << selector.first << endl;
      if( ! processor->process() ){
	//cout << "false" << endl;
	break;
      }
    }// end loop over processors

  }

}

#endif

#ifndef DISSECTINGJETMET
#define DISSECTINGJETMET
#include "dissectingJetsMET.cc"
#endif

#ifndef PROCESSOR
#define PROCESSOR

class processor {

 public : 
  
  dissectingJetsMET *ntuple ; 

  processor( dissectingJetsMET* ntuple_ ){
    ntuple = ntuple_ ;
  };

  // purely virtual method to be implement by children
  virtual bool process( ) = 0 ;

};

#endif

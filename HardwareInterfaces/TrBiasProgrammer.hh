#include "TrProgrammer.hh"
#include "TrBiasInitialisationState.hh"

#ifndef TRBIASPROGRAMMER_HH
#define TRBIASPROGRAMMER_HH

class TrBiasProgrammer : public TrProgrammer {
	private:
		/*! Map of the programmer member functions, in case the order
		 * that the functions are called in should be variable */
		//std::map<std::string, (*void)> programmerFunctions;
	public:
		
		int program(TrBiasInitialisationState*);
		TrCommandListHolder<TrCommandList*> prepareCommands(TrBiasInitialisationState*);
};

#endif
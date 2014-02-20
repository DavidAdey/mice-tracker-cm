#ifndef TRFPGAPROGRAMMER_HH
#define TRFPGAPROGRAMMER_HH

#include "TrInterfaceProgrammer.hh"
#include "TrFPGACommandList.hh"
#include "TrPICProgrammer.hh"
#include "TrPICWrapper.hh"



class TrFPGAProgrammer : public TrInterfaceProgrammer {

	private:
		TrPICProgrammer picProgrammer;
		TrPICWrapper picWrapper;

	public:
		int program(TrFPGACommandList*);

};

#endif
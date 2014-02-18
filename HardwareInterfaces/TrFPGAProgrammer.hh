#ifndef TRFPGAPROGRAMMER_HH
#define TRFPGAPROGRAMMER_HH

#include "TrInterfaceProgrammer.hh"
#include "TrFPGACommandList.hh"
#include "TrPICProgrammer.hh"



class TrFPGAProgrammer : public TrInterfaceProgrammer {

	private:
		TrPICProgrammer picProgrammer;

	public:
		int program(TrCommandList*);

};

#endif
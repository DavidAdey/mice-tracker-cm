//#include "TrFPGADecodePair.hh"
//#include "Tr1553CommandList.hh"
#include "TrPICCommandList.hh"
#include "TrVMEProgrammer.hh"
#include "Tr1553Wrapper.hh"

#ifndef TR1553PROGRAMMER_HH
#define TR1553PROGRAMMER_HH

class Tr1553Programmer : public TrInterfaceProgrammer {
	
	friend class TrPICProgrammer;
	
	private:
		Tr1553Wrapper wrapper;
		TrVMEProgrammer vmeProgrammer;
	public:
		int program(TrPICCommandList);
		
};

#endif
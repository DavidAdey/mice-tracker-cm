//#include "TrFPGADecodePair.hh"
//#include "Tr1553CommandList.hh"
#include "TrPICCommandList.hh"
#include "TrVMEProgrammer.hh"
#include "TrVMEWrapper.hh"

#ifndef TR1553PROGRAMMER_HH
#define TR1553PROGRAMMER_HH

class Tr1553Programmer : public TrInterfaceProgrammer {
	
	friend class TrPICProgrammer;
	
	private:
		TrVMEWrapper wrapper;
		TrVMEProgrammer vmeProgrammer;
	public:
		virtual int program(Tr1553CommandList*);
		
};

#endif
#include "TrInterfaceProgrammer.hh"
#include "Tr1553Wrapper.hh"
#include "Tr1553Programmer.hh"

#ifndef TRPICPROGRAMMER_HH
#define TRPICPROGRAMMER_HH

class TrPICProgrammer : public TrInterfaceProgrammer {
	
	/*! The FPGA programmer will use the PIC Wrapper */
	friend class TrFPGAProgrammer;
	
	private:
		Tr1553Wrapper wrapper;
		Tr1553Programmer mil1553Programmer;
		virtual int program(TrCommandList*);
		virtual int program(TrPICCommandList*);
	public:
};

#endif
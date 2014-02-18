#include "TrInterfaceProgrammer.hh"
#include "TrTriPtWrapper.hh"
#include "Tr1553Programmer.hh"
#include "TrPICProgrammer.hh"

#ifndef TRTRIPTSTREAMPROGRAMMER_HH
#define TRTRIPTSTREAMPROGRAMMER_HH

class TrTriPtStreamProgrammer : public TrInterfaceProgrammer {
	
	friend class TrPICProgrammer;
	
	private:
		TrTriPtWrapper wrapper;
		Tr1553Programmer mil1553Programmer;
		virtual int program(TrFPGACommandList);
	public:
};

#endif
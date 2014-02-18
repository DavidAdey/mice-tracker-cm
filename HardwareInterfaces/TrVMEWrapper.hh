#ifndef TRVMEWRAPPER_HH
#define TRVMEWRAPPER_HH

#include "TrVMECommandList.hh"
#include "TrBase.hh"

class TrVMEWrapper : public TrBase {
	
	friend class TrVMEProgrammer;

	private:
		TrVMECommandList wrapAsVMECommands(Tr1553CommandList);

};
#endif
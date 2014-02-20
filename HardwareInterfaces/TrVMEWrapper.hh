#ifndef TRVMEWRAPPER_HH
#define TRVMEWRAPPER_HH

#include "TrVMECommandList.hh"
#include "TrBase.hh"

class TrVMEWrapper : public TrBase {
	
	friend class Tr1553Programmer;

	private:
		TrVMECommandList* wrapAsVMECommands(Tr1553CommandList*);

};
#endif
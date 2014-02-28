#ifndef TRVMECOMMANDLIST_HH
#define TRVMECOMMANDLIST_HH

#include "Tr1553CommandList.hh"
#include "TrCommandList.hh"

class TrVMECommandList : public TrCommandList {
	private:
		int mil1553ControllerAddress;
	public:
		TrVMECommandList();
		int convertFrom1553Command(Tr1553CommandList);
};

#endif
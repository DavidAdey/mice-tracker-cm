#include "TrVMEWrapper.hh"

TrVMECommandList* TrVMEWrapper::wrapAsVMECommands(Tr1553CommandList* list) {
	return new TrVMECommandList();
}
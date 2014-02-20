#include "Tr1553Programmer.hh"

int Tr1553Programmer::program(Tr1553CommandList* commands) {
	TrVMECommandList* vmeCommands = wrapper.wrapAsVMECommands(commands);
	return vmeProgrammer.program(vmeCommands);
}
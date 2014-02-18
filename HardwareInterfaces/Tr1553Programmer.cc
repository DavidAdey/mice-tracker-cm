#include "Tr1553Programmer.hh"

int Tr1553Programmer::program(TrPICCommandList commands) {
	Tr1553CommandList mil1553Commands = wrapper.wrapAs1553Commands(commands);
	return vmeProgrammer.program(mil1553Commands);
}
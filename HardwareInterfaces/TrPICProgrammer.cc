#include "TrPICProgrammer.hh"

int TrPICProgrammer::program(TrCommandList *commands) {
	TrPICCommandList *picCommands = dynamic_cast<TrPICCommandList*>(commands);
	return program(picCommands);
}

int TrPICProgrammer::program(TrPICCommandList *commands) {
	Tr1553CommandList* mil1553Commands = wrapper.wrapAs1553Commands(commands);
	return mil1553Programmer.program(mil1553Commands);
}

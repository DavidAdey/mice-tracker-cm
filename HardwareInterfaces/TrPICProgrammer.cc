#include "TrPICProgrammer.hh"

int TrPICProgrammer::program(TrCommandList *commands) {
	TrFPGACommandList *fpgaCommands = dynamic_cast<TrFPGACommandList*>(commands);
	return program(fpgaCommands);
}

int TrPICProgrammer::program(TrFPGACommandList *commands) {
	TrPICCommandList picCommands = wrapper.wrapAsPICCommands(commands);
	return mil1553Programmer.program(picCommands);
}

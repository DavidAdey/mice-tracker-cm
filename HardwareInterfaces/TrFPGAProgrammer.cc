#include "TrFPGAProgrammer.hh"

int TrFPGAProgrammer::program(TrFPGACommandList* commands) {
	TrPICCommandList* picCommands = picWrapper.wrapAsPICCommands(commands);
	picProgrammer.program(picCommands);
}
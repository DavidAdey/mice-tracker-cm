#include "TrFPGAProgrammer.hh"

int TrFPGAProgrammer::program(TrCommandList* commands) {
	picProgrammer.program(commands);
}
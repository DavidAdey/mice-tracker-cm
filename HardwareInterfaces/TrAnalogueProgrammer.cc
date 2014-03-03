#include "TrAnalogueProgrammer.hh"

TrAnalogueProgrammer::TrAnalogueProgrammer() {}

int TrAnalogueProgrammer::prepareCommands() {

	int status(0);
	//analogueCommands.insert(static_cast<TrCommandList*>(state.picCommandLists["Turn on AFPGA"]));
	TrPICCommandList* firmwareCommands = new TrPICCommandList();
	/*

			mAFEIItCore->CheckHeartBeat(lBeatActive);
	*/
	return status;
}
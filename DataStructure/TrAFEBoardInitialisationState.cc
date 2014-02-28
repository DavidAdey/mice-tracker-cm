#include "TrAFEBoardInitialisationState.hh"

TrAFEBoardInitialisationState::TrAFEBoardInitialisationState() {
	setupFunctionList();
	setupParameterMap();
}

int TrAFEBoardInitialisationState::setupParameterMap() {
	boardParameters.insert(std::pair<std::string,int>("pipeline",4));
	boardParameters.insert(std::pair<std::string,int>("clockGenFirmware",0));
	boardParameters.insert(std::pair<std::string,int>("1553Firmware",0));
	boardParameters.insert(std::pair<std::string,int>("helperFirmware",0));
	boardParameters.insert(std::pair<std::string,int>("collectorFirmware",0));
	boardParameters.insert(std::pair<std::string,int>("clockSource",0));
	boardParameters.insert(std::pair<std::string,int>("triggerMode",0));
}

int TrAFEBoardInitialisationState::setupFunctionList() {
	fpgaFunctions.insert(std::pair<std::string,TrFPGACommandList>("getFirmware",TrFPGACommandList() ) );
}

int TrAFEBoardInitialisationState::getParameter(std::string parameterName) {
	return boardParameters[parameterName];
}
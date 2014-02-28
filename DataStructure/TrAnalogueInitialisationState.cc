#include "TrAnalogueInitialisationState.hh"

TrAnalogueInitialisationState::TrAnalogueInitialisationState() {}

int TrAnalogueInitialisationState::setupParameterMap() {
	parameterValues.insert(std::pair<std::string,int>("injectionLevel",0));
	parameterValues.insert(std::pair<std::string,int>("injectionFineDelay",0));
	
	/*programAFPGA[0] = TrDecodePair(0x480,0x0,"Dual Progam RAM");
	programAFPGA[1] = TrDecodePair(0x481,0x17E,"Num Byte blocks");
	programAFPGA[2] = TrDecodePair(0x482,0x2,"Flash timeout counter");
	programAFPGA[3] = TrDecodePair(0x483,fpgaID,"FPGA index");*/
}

int TrAnalogueInitialisationState::insertChargeInjectionLevel(int level) {
	parameterValues["injectionLevel"] = level;
}

int TrAnalogueInitialisationState::insertChargeInjectionFineDelay(int delay) {
	parameterValues["injectionFineDelay"] = delay;
}

int TrAnalogueInitialisationState::prepareRegisterMap() {
	registerValues.insert(std::pair<int,int>(0,0));
}
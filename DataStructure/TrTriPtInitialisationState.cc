#include "TrTriPtInitialisationState.hh"

TrTriPtInitialisationState::TrTriPtInitialisationState() {}

int TrTriPtInitialisationState::createParameterMap() {
	/*! TriPt parameters - Power on defaults or most likely values */
	parameterValues.insert(std::pair<std::string, int> ("VTh", 0)); // Comparator reference voltage
	parameterValues.insert(std::pair<std::string, int> ("VRef",170)); // Reference voltage
	parameterValues.insert(std::pair<std::string, int> ("IBT",80)); // Time circuit current source (TDC gain)
	parameterValues.insert(std::pair<std::string, int> ("IBP",130)); //Preamp drive current
	parameterValues.insert(std::pair<std::string, int> ("IBBNFoll",0)); // Preamp feedback control
	parameterValues.insert(std::pair<std::string, int> ("IFF",0)); // Preamp feedback control
	parameterValues.insert(std::pair<std::string, int> ("IBBIFF1REF",0)); // Preamp reset strength
	parameterValues.insert(std::pair<std::string, int> ("IBBOPAMP",255)); // OpAmp drive current
	parameterValues.insert(std::pair<std::string, int> ("IFFP2",0)); // OpAmp feedback control
	parameterValues.insert(std::pair<std::string, int> ("IBCOMP",10)); // Comparator drive current
	parameterValues.insert(std::pair<std::string, int> ("IRWSEL",0)); // Drive currents for pipeline R/W
	parameterValues.insert(std::pair<std::string, int> ("Pipeline",4)); // Pipeline depth in integration periods
	parameterValues.insert(std::pair<std::string, int> ("OpAmps",0x4)); // 3 bits high for 3 OpAmps ON
	parameterValues.insert(std::pair<std::string, int> ("PreAmp",1)); // Single PreAmp ON (later inverted in register)
	parameterValues.insert(std::pair<std::string, int> ("InjectionMap",0)); // Chaarge injection map
}

int TrTriPtInitialisationState::insertValue(std::string valueName, int value) {
	if (! (parameterValues.find(valueName) == parameterValues.end())) {
		parameterValues[valueName] = value;
	}
}	

int TrTriPtInitialisationState::getValue(std::string valueName) {
	return parameterValues[valueName];
}

int TrTriPtInitialisationState::prepareRegisterMap() {
	/*! Insert the values into the register map
	* Key is the address of the register */
	registerValues.insert(std::pair<int,int> (0,parameterValues["IBP"]));
	registerValues.insert(std::pair<int,int> (1,parameterValues["IBBNFoll"]));
	registerValues.insert(std::pair<int,int> (2,parameterValues["IFF"]));
	registerValues.insert(std::pair<int,int> (3,parameterValues["IBPIF1REF"]));
	registerValues.insert(std::pair<int,int> (4,parameterValues["IBOPAMP"]));
	registerValues.insert(std::pair<int,int> (5,parameterValues["IBT"]));
	registerValues.insert(std::pair<int,int> (6,parameterValues["IFFP2"]));
	registerValues.insert(std::pair<int,int> (7,parameterValues["IBCOMP"]));
	registerValues.insert(std::pair<int,int> (8,parameterValues["VRef"]));
	registerValues.insert(std::pair<int,int> (9,parameterValues["VTh"]));
	
	int amp_pipe_register = parameterValues["Pipeline"];
	/*! Only 5 bits available for pipeline depth */
	if (amp_pipe_register > 31) {
		sprintf(messageBuffer,"Pipeline too deep in %i module %i chip %i truncating",board, analogueModule, tripID);
		warning( messageBuffer,__FILE__,__LINE__);
		amp_pipe_register = 0x1F;
	}
	/*! Move the OpAmps into bits 5-8 */
	amp_pipe_register |= (parameterValues["OpAmps"]) << 5;
	/*! PreAmp is 0 when on - move to bit 9 */
	amp_pipe_register |= (! parameterValues["PreAmp"]) << 8;
	/*! Warn if they're not all on */
	if ((amp_pipe_register & 0x1E0) != 0x7) {
		sprintf(messageBuffer,"WARNING not all amps are on for board %i module %i chip %i",board, analogueModule, tripID);
		warning(messageBuffer,__FILE__,__LINE__);	
	}
	registerValues.insert(std::pair<int,int> (10,amp_pipe_register));
}

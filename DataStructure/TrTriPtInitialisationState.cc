#include "TrTriPtInitialisationState.hh"

TrTriPtInitialisationState::TrTriPtInitialisationState() {}

int TrTriPtInitialisationState::getValue(std::string valueName) {
	return parameterValues[valueName];
}

int TrTriPtInitialisationState::insertVThValue(int value) {
	parameterValues.insert(std::pair<std::string, int> ("VTh", value));
}

int TrTriPtInitialisationState::insertVRefValue(int value) {
	parameterValues.insert(std::pair<std::string, int> ("VRef", value));
}


int TrTriPtInitialisationState::insertIBTValue(int value) {
	parameterValues.insert(std::pair<std::string, int> ("IBT", value));
}

int TrTriPtInitialisationState::insertPipeDepthValue(int value) {
	parameterValues.insert(std::pair<std::string, int> ("IBT", value));
}

int TrTriPtInitialisationState::prepareRegisterValues() {
	registerValues.insert(std::pair<int, int> (0, parameterValues["VTh"]));

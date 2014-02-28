#include "TrBiasInitialisationState.hh"

TrBiasInitialisationState::TrBiasInitialisationState() {}

TrBiasInitialisationState::TrBiasInitialisationState(int boardIn, int moduleIn, double biasIn, double biasSlopeIn, double biasOffsetIn) {

	board = boardIn;
	analogueModule = moduleIn;
	values.bias = biasIn;
	values.slope = biasSlopeIn;
	values.offset = biasOffsetIn;
}

int TrBiasInitialisationState::prepareRegisterMap() {}

int TrBiasInitialisationState::setBias(double biasIn) {
	values.bias = biasIn;
	return 0;
}

int TrBiasInitialisationState::setBiasSlope(double biasSlopeIn) {
	values.slope = biasSlopeIn;
	return 0;
}

int TrBiasInitialisationState::setBiasOffset(double biasOffsetIn) {
	values.offset = biasOffsetIn;
	return 0;
}

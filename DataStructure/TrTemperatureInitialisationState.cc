#include "TrTemperatureInitialisationState.hh"

TrTemperatureInitialisationState::TrTemperatureInitialisationState() {}

TemperatureValues TrTemperatureInitialisationState::getTemperatureValues() const {
	return values;
}
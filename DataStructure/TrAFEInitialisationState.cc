#include "TrAFEInitialisationState.hh"

TrAFEInitialisationState::TrAFEInitialisationState() {
	/*! Setup the counters for yielding the sub-states */
	stateCounters.insert(std::pair<std::string,int>("analogue",0));
	stateCounters.insert(std::pair<std::string,int>("digital",0));
	stateCounters.insert(std::pair<std::string,int>("bias",0));
	stateCounters.insert(std::pair<std::string,int>("temperature",0));
	stateCounters.insert(std::pair<std::string,int>("tript",0));
}

int TrAFEInitialisationState::harmoniseValues() {
	int status = 0;
	/*! Get the master pipeline depth from the board state */
	int pipelineDepth = boardState.getParameter("PipelineDepth");
	/*! Distribute to the DPFGAs to set the discriminator pipeline depth */
	for (unsigned int dfpga = 0; dfpga < Globals::DFPGATotal; ++dfpga) {
		status |= updateDigitalState(dfpga, "PipelineDepth", pipelineDepth);
	}
	/*! Distribute to the TriPts to set the analogue and timing
	 * pipeline depths */
	for (unsigned int tript = 0; tript < Globals::TriPtTotal; ++tript) {
		status |= updateTriPtState(tript, "PipelineDepth", pipelineDepth);
	}
	return status;
}

int TrAFEInitialisationState::updateDigitalState(int id, std::string parameter, int value) {
	int status = 0;
	if (parameter == "PipelineDepth") {
		status |= digitalStates[id].insertDiscriminatorPipeline(value);
	}
	return status;
}

int TrAFEInitialisationState::updateTriPtState(int id, std::string parameter, int value) {
	int status = 0;
	if (parameter == "PipelineDepth") {
		status |= triptStates[id].insertValue(parameter, value);
	}
	return status;
}

int TrAFEInitialisationState::prepareAllRegisters() {
	int status = 0;
	/*! Prepare the digital registers */
	for (unsigned int dfpga = 0; dfpga < Globals::DFPGATotal; ++dfpga) {
		status |= digitalStates[dfpga].prepareRegisterValues();
	}
	/*! Prepare the analogue registers, including
	 * bias and temperature (if right-hand board) */
	for (unsigned int afpga = 0; afpga < Globals::AFPGATotal; ++afpga) {
		status |= analogueStates[afpga].prepareRegisterMap();
		status |= biasStates[afpga].prepareRegisterMap();
		if (boardType == "Right") {
			status |= temperatureStates[afpga].prepareRegisterMap();
		}
	}
	/*! Prepare the tript registers */
	for (unsigned int tript = 0; tript < Globals::TriPtTotal; ++tript) {
		status |= triptStates[tript].prepareRegisterMap();
	}
	return status;
}

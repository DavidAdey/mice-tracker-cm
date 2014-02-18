#include "TrBiasProgrammer.hh"

int TrBiasProgrammer::program(TrBiasInitialisationState* biasState) {
	if (!biasState->getPrepared()) {
		biasState->prepareRegisterMap();
	}
	TrCommandListHolder<TrCommandList*> commands = prepareCommands(biasState);
	// make new command lists based on regisgters
	return programCommand(commands);
	// from the base class interfaceprogrammers->program(each_command_list)
	//return 0;
} 

TrCommandListHolder<TrCommandList*> TrBiasProgrammer::prepareCommands(TrBiasInitialisationState* biasState) {
	// need some hard coded conversion of register values to commands...
	
}
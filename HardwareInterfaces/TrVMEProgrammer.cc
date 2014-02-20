#include "TrVMEProgrammer.hh"

int TrVMEProgrammer::program(TrVMECommandList* vmeCommands) {
	int result(0);
	/*! Convert the 1553 command list into VME commands */
	//TrVMECommandList vmeCommands = wrapper.wrapAsVMECommands(commands);
	
	/*! loop over the commands and write them via the CAEN VME library */
	for (unsigned int command; command < vmeCommands->getLength(); ++command) {
		/*! Get the address and value from the command */
		int address = vmeCommands->getCommands()[command].getDecode();
		int data = vmeCommands->getCommands()[command].getData();
		/*! Write over VME - print to screen for now */
		//result |= CAENVME_WriteCycle(vmeHandle, address, &data, addressModifier, dataWidth);
		std::cout << "VME" << address << " " << data << std::endl;
	}
	return result;
}
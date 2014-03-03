#include "TrProgrammer.hh"

class TrDigitalProgrammer : public TrProgrammer {

	friend class TrAFEProgrammer;
	
	private:
		TrCommandListHolder<TrCommandList*> analogueCommands;
		
		/*! Program the state to the specific DFPGA */
		int program(TrDigitalInitialisationState*);
		
		/*! Prepare all of the commands */
		int prepareCommands();
		/*! Prepare the turn on commands */
		int setupTurnOnCommands();
		/*! Prepare the commands to download the firmware */
		int setupGetFirmwareCommands();
	public:
		TrDigitalProgrammer();

};
#include "TrProgrammer.hh"
#include "TrAnalogueInitialisationState.hh"

class TrAnalogueProgrammer : public TrProgrammer {

	friend class TrAFEProgrammer;
	
	private:
		TrCommandListHolder<TrCommandList*> analogueCommands;
		
		/*! Program the state to the specific AFPGA */
		int program(TrAnalogueInitialisationState*);
		
		/*! Prepare all of the commands */
		int prepareCommands();
		/*! Prepare the turn on commands */
		int setupTurnOnCommands();
		/*! Prepare the commands to download the firmware */
		int setupGetFirmwareCommands();
	public:
		TrAnalogueProgrammer();

};
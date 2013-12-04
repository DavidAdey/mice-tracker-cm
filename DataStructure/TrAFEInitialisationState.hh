#include <map>
#include <vector>
#include <string>


/*! Class to hold all the parameters (including from sub-states) used to 
* initialise a single AFE board */
class TrAFEInitialisationState {
	private:
		// Nothing to see here
	protected:
		/*! The state common to the entire board, eg, ClkGen settings */
		TrAFEBoardInitialisationState board_state;
		/*! TriPt initialisation states */
		std::map<int, TrTriPtInitialisationState> tript_states;
		/*! AGPFA states */
		std::map<int, TrAnalogueInitialisationState> analogue_states;
		/*! DFPGA states, including discriminator pipelines */
		std::map<int, TrDigitalInitialisationState> digitial_states;
		/*! VLPC bias states encoded onto AFPGA */
		std::map<int, TrBiasInitialisationState>
		/*! Temperature states encoded on top of AFPGA analogue states */
		std::map<int, TrTemperatureInitialisationState> temperature_states;

	public:
		inline const std::map<int, TrTrTriPtInitialisationState> getTrTriPtStates() {return tript_states;}
		inline const std::map<int, TrAnalogueInitialisationState> getAnalogueStates() {return analogue_states;}
		inline const std::map<int, TrDigitalInitialisationState> getDigitalStates() {return digital_states;}
		inline const std::map<int, TrTemperatureInitialisationState> getTemperatureStates() {return temperature_states;}

		TrTriPtInitialisationState yieldTriPtState(int id);
		TrAnalogueInitialisationState yieldAnalogueState(int id);
		TrDigitalInitialisationState yieldDigitalState(int id);
		TrBiasInitialisationState yieldBiasState(int id);
		TrTemperatureState yielfTemperatureState(int id);	

		/*! Take common values from board_state and distribute to all
		* other sub-states eg. pipe delay to TriPt, DFPGA 
		* \return Function called successfully */
		int harmoniseValues();
};

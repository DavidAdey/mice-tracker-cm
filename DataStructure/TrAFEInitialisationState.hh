#include <map>
#include <vector>
#include <string>

#include "TrGlobals.hh"

#include "TrAFEBoardInitialisationState.hh"
#include "TrDigitalInitialisationState.hh"
#include "TrAnalogueInitialisationState.hh"
#include "TrTriPtInitialisationState.hh"
#include "TrBiasInitialisationState.hh"
#include "TrTemperatureInitialisationState.hh"

/*! Class to hold all the parameters (including from sub-states) used to 
* initialise a single AFE board */
class TrAFEInitialisationState {
	private:
		int initialiseDateTime;
	protected:
		/*! The type of the board - "Left" or "Right" */
		std::string boardType;
		/*! The state common to the entire board, eg, ClkGen settings */
		TrAFEBoardInitialisationState boardState;
		/*! TriPt initialisation states */
		std::map<int, TrTriPtInitialisationState> triptStates;
		/*! AGPFA states */
		std::map<int, TrAnalogueInitialisationState> analogueStates;
		/*! DFPGA states, including discriminator pipelines */
		std::map<int, TrDigitalInitialisationState> digitalStates;
		/*! VLPC bias states encoded onto AFPGA */
		std::map<int, TrBiasInitialisationState> biasStates;
		/*! Temperature states encoded on top of AFPGA analogue states */
		std::map<int, TrTemperatureInitialisationState> temperatureStates;
		
		mutable std::map<std::string, int> stateCounters;

	public:
		TrAFEInitialisationState();
		~TrAFEInitialisationState();
		
		std::map<int, TrTriPtInitialisationState>* getTriPtStates() const;
		std::map<int, TrAnalogueInitialisationState>* getAnalogueStates() const;
		std::map<int, TrDigitalInitialisationState>* getDigitalStates() const;
		std::map<int, TrTemperatureInitialisationState>* getTemperatureStates() const;

		TrTriPtInitialisationState* yieldTriPtState(int) const;
		TrAnalogueInitialisationState* yieldAnalogueState(int) const;
		TrDigitalInitialisationState* yieldDigitalState(int) const;
		TrBiasInitialisationState* yieldBiasState(int) const;
		TrTemperatureInitialisationState* yieldTemperatureState(int) const;
		
		TrTriPtInitialisationState* yieldNextTriPtState() const;
		TrAnalogueInitialisationState* yieldNextAnalogueState() const;
		TrDigitalInitialisationState* yieldNextDigitalState() const;
		TrBiasInitialisationState* yieldNextBiasState() const;
		TrTemperatureInitialisationState* yieldNextTemperatureState() const;
		
		int addTriPtState(int, TrTriPtInitialisationState);
		int addAnalogueSTate(int, TrAnalogueInitialisationState);
		int addDigitalState(int, TrDigitalInitialisationState);
		int addBiasState(int, TrBiasInitialisationState);
		int addTemperatureState(int, TrTemperatureInitialisationState);
		
		int updateTriPtState(int, std::string, int);
		//int updateAnalogueSTate(int, TrAnalogueInitialisationState);
		int updateDigitalState(int, std::string, int);
		//int updateBiasState(int, TrBiasInitialisationState);
		//int updateTemperatureState(int, TrTemperatureInitialisationState);
		
		/*! Take common values from board_state and distribute to all
		* other sub-states eg. pipe delay to TriPt, DFPGA 
		* \return Function called successfully */
		int harmoniseValues();
		/*! Prepare all values into register entries
		* \return Function called successfully */
		int prepareAllRegisters();
};

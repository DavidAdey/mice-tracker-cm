#include <map>
#include <string>

class TrAnalogueInitialisationState {
	private:
		/*! Physical values used in initialisation */
		std::map<std::string, double> parameterValues;
		/*! Values written to registers to achieve physical result */
		std::map<int, int> registerValues;

	public:
		/*! Constructor */
		TrAnalogueInitialisationState();
		/* Convert the physical parameters from parameterValues
		* into the values understood by the AFPGA in registerValues 
		* \return Function called successfully */
		int prepareRegisterValues();
		/*! add fine delay of charge injection, measured in clock
		* cycles within the integration period defined in the ClkGen 
		* \param delay The delay in 18.8ns clock cycles 
		* \return Function called successfully*/
		int insertChargeInjectionFineDelay(int delay);
		/*! Level of charge injected into channel defined by which
		* OpAmps are turned on. Options are 0x0, 0x5, 0xA, 0xF
		* \param level The charge injection level 
		* \return Function called successfully*/
		int insertChargeInjectionLevel(int level);

};

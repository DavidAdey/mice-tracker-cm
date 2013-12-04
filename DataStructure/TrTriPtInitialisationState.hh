#include <map>
#include <vector>
#include <string>

class TrTriPtInitialisationState {
	private:
		std::map<std::string, int> parameterValues;
		std::map<int, int> registerValues;

	public:
		TrTriPtInitialisationState();
		/*! Fill the register map from the physical parameters 
		* \return Function successfully called */
		int prepareRegisterValues();
		/*! Retrieve a specific value from the register map
		* \param value_name Name of the value wanted
		* \return Function successfully called */
		int getValue(std::string value_name);
		int insertVThValue(int vth);
		int insertVRefValue(int vref);
		int insertIBTValue(int ibt);
		int insertPipeDepthValue(int pipe_delay);
};

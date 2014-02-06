#include <map>
#include <vector>
#include <string>

#include "TrAFEObject.hh"

#ifndef TRTRIPTINITIALISATIONSTATE_HH
#define TRTRIPTINITIALISATIONSTATE_HH

class TrTriPtInitialisationState : public TrAFEObject {
	private:
		std::map<std::string, int> parameterValues;
		std::map<int, int> registerValues;

	public:
		TrTriPtInitialisationState();
		/*! Set up which paraemters exist for TriPt
		* \return Function successfully called */
		int createParameterMap();
		/*! Fill the register map from the physical parameters 
		* \return Function successfully called */
		int prepareRegisterMap();
		/*! Retrieve a specific value from the register map
		* \param value_name Name of the value wanted
		* \return Function successfully called */
		int insertValue(std::string, int);
		int updateValue(std::string, int);
		int getValue(std::string value_name);
};

#endif

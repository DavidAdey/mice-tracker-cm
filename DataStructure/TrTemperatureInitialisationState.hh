#include <map>
#include <string>

#include "TrAFEObject.hh"
#include "TrValueHolders.hh"

#ifndef TRTEMPERATUREINITIALISAIONSTATE_HH
#define TRTEMPERATUREINITIALISAIONSTATE_HH

class TrTemperatureInitialisationState : public TrAFEObject {
	private:
		TemperatureValues values;
		std::map<int,int> registerValues;
	public:
		/*! Default constructor */
		TrTemperatureInitialisationState();
		
		/*! Constructor with values
		 * \param Board
		 * \param Module
		 * \param Temperature
		 * \param Slope
		 * \param Offset */
		TrTemperatureInitialisationState(int, int, double, double, double);
		
		/*! Get the temperature state
		 * \return TemperatureValues */
		TemperatureValues getTemperatureValues() const;
		int prepareRegisterMap();
		
};

#endif
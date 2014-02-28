#include <map>

#include "TrAFEObject.hh"
#include "TrValueHolders.hh"
//#include "TrBiasProgrammer.hh"

#ifndef TRBIASINITIALISATIONSTATE_HH
#define TRBIASINITIALISATIONSTATE_HH

class TrBiasInitialisationState : public TrAFEObject {
	
	friend class TrBiasProgrammer;
	
	private:
		BiasValues values;
		std::map<int, int> registerMap;
		int prepared;
	public:
		/*! Default constructor */
		TrBiasInitialisationState();
		
		/*! Constructor with values
		 * \param BoardNumber The AFE board index
		 * \param ModuleNumber The analogue FPGA/module index
		 * \param Bias
		 * \param Slope
		 * \param Offset */
		TrBiasInitialisationState(int, int, double, double, double);
		
		/*! Fill the register values from the physical values
		 * \return CalledSuccessfully */
		int prepareRegisterMap();
		
		/*! Get the bias
		 * \return Bias */
		double getBias() const {return values.bias;}
		
		/*! Get the Bias slope
		 * \return BiasSlope */
		double getBiasSlope() const {return values.slope;}
		
		/*! Get the bias offset
		 * \return BiasOffset */
		double getBiasOffset() const {return values.offset;}
		
		/*! Set the bias
		 * \param  Bias Float in V
		 * \return CalledSuccessfully */
		int setBias(double);
		
		/*! Set the slope/gain of the bias DAC
		 * \param Slope
		 * \return CalledSuccessfully */
		int setBiasSlope(double);
		
		/*! Set the offset of the bias DAC
		 * \param Offset
		 * \return CalledSuccessfully */
		int setBiasOffset(double);
		
		int getPrepared() const {return prepared;}

};

#endif


#ifndef TRGLOBALS_HH
#define TRGLOBALS_HH

namespace Globals {
	
	int prepareGlobalValues() {}

	/*! Temperature limits in K */
	double MaximumTemperature = 10.0;
	double MinimumTemperature = 6.0;
	
	/*! Bias limits in V */
	double MaximumBias = 10.0;
	double MinimumBias = 0.0;
	
	/*! Physical numbers of things on boards - will never change */
	int AFPGATotal = 8;
	int DFPGATotal = 4;
	int TriPtTotal = 32;
	
	/*! Numbers of things in MICE */
	int TrackersTotal = 2;
	int AFEBoardTotal = 16;
	
	namespace ErrorCodes {
		int Fail = -1;
	}
}

#endif
#include "../Base/TrBase.hh"

#ifndef TRAFEOBJECT_HH
#define TRAFEOBJECT_HH


/*! Base class for all AFE entities. Stores board, module etc. indices */
class TrAFEObject : public TrBase {
	protected:
		int board;
		int analogueModule;
		int digitalModule;
		int fpgaID;
		int tripID;
	public:
		/*! Get the board ID 
		 \return BoardNumber */
		inline int getBoard() const {return board;}
		
		/*! Get the bank/DPFGA ID 0-3
		* \return DPFGANumber */
		inline int getDigitalModule() const {return digitalModule;}
		
		/*! Get the module ID 0-7 
		 * \return AFPGANumber */
		inline int getAnalogueModule() const {return analogueModule;}
		
		/*! Get the chip ID  - TriPts only
		* \return TriPtNumber */
		inline int getTrip() const {return tripID;}
		
		/*! Get the FPGA ID 0-7 AFPGA, 8-11 DFPGA
		 * \return FPGAID */
		inline int getFPGA() const {return fpgaID;}
		

};

#endif

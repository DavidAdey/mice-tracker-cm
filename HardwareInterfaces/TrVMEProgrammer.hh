#ifndef TRVMEPROGRAMMER_HH
#define TRVMEPROGRAMMER_HH

#include <iostream>

//#include "CAENVMELib.h"

#include "TrInterfaceProgrammer.hh"
#include "TrVMEWrapper.hh"
#include "TrDecodePair.hh"

class TrVMEProgrammer : public TrInterfaceProgrammer {
	
	friend class Tr1553Programmer;

	private:
		/*! Static properties of the VME controller -
		 * The handle of the PCI interface */
		static int vmeHandle;
		/*! The modifer to 32bit addressing */
		static int addressModifer;
		/*! The modifier to 32bit data length */
		static int dataWidth;
		
		TrVMEWrapper wrapper;
		virtual int program(TrVMECommandList*);
	public:
};

#endif
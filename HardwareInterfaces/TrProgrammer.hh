#include <map>
#include <string>

#include "TrInterfaceProgrammer.hh"
#include "TrCommandListHolder.hh"
#include "TrBase.hh"
#include "TrPICProgrammer.hh"
#include "TrVMEProgrammer.hh"
#include "Tr1553Programmer.hh"
#include "TrFPGAProgrammer.hh"
#include "TrTriPtStreamProgrammer.hh"

#ifndef TRPROGRAMMER_HH
#define TRPROGRAMMER_HH

class TrProgrammer : public TrBase {
	protected:
		/*! Map of interface programmers eg. VME, 1553 */
		std::map<std::string, TrInterfaceProgrammer*> programmers;
	public:
		/*! Constructor */
		TrProgrammer();
		/*! Destructor */
		~TrProgrammer();
		/*! Program a particular command list */
		int programCommand(TrCommandListHolder<TrCommandList*>);
};

#endif
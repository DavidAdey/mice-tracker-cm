#include "TrBase.hh"
#include "TrPICCommandList.hh"
#include "TrFPGACommandList.hh"
#include "TrCommandList.hh"
#include "TrDecodePair.hh"

#ifndef TRPICWRAPPER_HH
#define TRPICWRAPPER_HH

//class TrPICCommandList;

class TrPICWrapper : public TrBase {

	friend class TrPICProgrammer;
	friend class TrFPGAProgrammer;

	private:
		TrPICCommandList* wrapAsPICCommands(TrFPGACommandList*);
	public:

};

#endif
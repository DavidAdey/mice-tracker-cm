#include "TrCommandList.hh"

#ifndef TRFPGACOMMANDLIST_HH
#define TRFPGACOMMANDLIST_HH

class TrFPGACommandList : public TrCommandList {
	protected:
	public:
		virtual std::string getType() const {return "FPGACommandList";}
};

#endif
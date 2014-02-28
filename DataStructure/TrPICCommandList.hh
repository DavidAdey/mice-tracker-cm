#include "TrCommandList.hh"

#ifndef TRPICCOMMANDLIST_HH
#define TRPICCOMMANDLIST_HH

class TrPICCommandList : public TrCommandList {
	protected:
	public:
		virtual std::string getType() const {return "PICCommandList";}
};

#endif
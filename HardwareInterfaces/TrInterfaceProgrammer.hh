#include <map>
#include <string>

#include "TrBase.hh"
#include "TrCommandList.hh"

#ifndef TRINTERFACEPROGRAMMER_HH
#define TRINTERFACEPROGRAMMER_HH

class TrInterfaceProgrammer : public TrBase {
	protected:
		static std::map<std::string, int> parameters;
	public:
		/*! Does nothing for now */
		virtual int program(TrCommandList*);
};

#endif
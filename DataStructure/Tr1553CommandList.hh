#include "TrCommandList.hh"

#ifndef TR1553COMMANDLIST_HH
#define TR1553COMMANDLIST_HH

class Tr1553CommandList : public TrCommandList {
	private:
	public:
		/*! Constructor */
		Tr1553CommandList();
		
		/*! Polymorphic getType
		* \return TypeName */
		virtual std::string getType() const {return "1553CommandList";}
};

#endif
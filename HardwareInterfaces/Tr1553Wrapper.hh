#include "TrDecodePair.hh"
#include "Tr1553CommandList.hh"
#include "TrPICCommandList.hh"

#ifndef TR1553WRAPPER_HH
#define TR1553WRAPPER_HH

class Tr1553Wrapper : public TrBase {
	
	friend class Tr1553Programmer;
	
	private:
		Tr1553CommandList wrapAs1553Commands(TrPICCommandList);
	public:
		
		
};

#endif
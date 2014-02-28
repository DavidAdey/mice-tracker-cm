#include "TrCommandList.hh"
#include <vector>

#ifndef TRCOMMANDLISTHOLDER_HH
#define TRCOMMANDLISTHOLDER_HH

template <class T> class TrCommandListHolder {
	private:
		std::vector<T> commandLists;
	public:
		T& operator[](int id) {return commandLists[id];}
		int getLength() const {return commandLists.size();}
  
};

#endif
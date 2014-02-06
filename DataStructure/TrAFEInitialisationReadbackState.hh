
#include "TrAFEInitialisationState.hh"

class TrAFEInitialisationReadbackState : public TrAFEInitialisationState {

	private:
		/*! Private members */
		int readTime;
		std::map<std::string, bool> readValues;

		/*! Private member functions */
		int prepareReadValueMap();
	public:
		TrAFEInitialisationReadbackState();

};

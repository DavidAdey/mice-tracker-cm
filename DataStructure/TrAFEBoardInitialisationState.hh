#include <map>
#include <string>

#include "TrFPGACommandList.hh"
#include "TrAFEObject.hh"

class TrAFEBoardInitialisationState : public TrAFEObject {

	private:
		std::map<std::string, TrFPGACommandList> fpgaFunctions;
		std::map<std::string, int> boardParameters;
		
		int setupParameterMap();
		int setupFunctionList();
	public:
		TrAFEBoardInitialisationState();
		int getParameter(std::string);
};

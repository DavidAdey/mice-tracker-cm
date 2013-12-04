#include <map>

class TrAFEBoardInitialisationState {

	private:
		std::map<std::string, TrFPGACommandList> fpga_functions;
		std::map<std::string, int> board_parameters;

#include "TrCodeTeter.hh"

TrCodeTester::intialise() {
	errorCodes.insert(std::pair<int, std::string>(1,"Pass"));
	errorCodes.insert(std::pair<int, std::string>(0,"Fail"));
	return 0;
}	



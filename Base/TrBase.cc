#include "TrBase.hh"

void TrBase::log(std::string message, std::string file, int line) {
	TrLogger::getInstance().writeLog(message,2,file,line);
}

void TrBase::error(std::string message) {
}	

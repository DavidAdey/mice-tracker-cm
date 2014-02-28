#include <string>
#include <iostream>
#include <stdio.h>

#include "TrLogger.hh"

#ifndef TRBASE_HH
#define TRBASE_HH

/*! Base class for all classes - includes access to logger */
class TrBase {
	protected:
		char messageBuffer[1024];	
	public:
		void debug(std::string);	
		void log(std::string, std::string, int);
		void warning(std::string, std::string, int);
		void broadcast(std::string);
		void error(std::string);
		void fatal(std::string);
};

#endif

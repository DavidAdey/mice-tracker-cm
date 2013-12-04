// C++ Includes
#include <map>
#include <string>

// Tracker C&M includes
#include "TrFPGADecodePair.hh"

#ifndef TRFPGACOMMANDLIST_HH
#define TRFPGACOMMANDLIST_HH

/*! Object to contain a list of FPGA commands usually performed in a single burst */

class TrFPGACommandList {

	private:
		/*! The addresses and values */
		std::map<int, TrFPGADecodePair> commands;	
	public:
		/*! Get the command list map
		* \return Command list */
		inline std::map<int, TrFPGADecodePair> getCommands() {return commands};
		
		/*! Get a command identified by its order in the burst 
		* \param order The command identified by its order of programming (init)
		* \return command TrFPGADecodePair */
		TrFPGADecodePair getCommand(int);

		/*! Find a particular decode identified by the string
		* Replace it within the Decode pair.
		* \param name The command identifier (string)
		* \param command The command (TrFPGADecodePair) 
		* \return OK */
		int updateDecodePair(std::string, TrFPGADecodePair);

};

#endif

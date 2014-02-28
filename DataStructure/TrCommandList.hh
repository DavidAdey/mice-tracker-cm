// C++ Includes
#include <map>
#include <string>

// Tracker C&M includes
#include "TrDecodePair.hh"
#include "TrFPGAInitialisationState.hh"

#ifndef TRCOMMANDLIST_HH
#define TRCOMMANDLIST_HH

/*! Object to contain a list of  commands usually performed in a single burst */

class TrCommandList : public TrBase {

	protected:
		/*! The addresses and values */
		std::map<int, TrDecodePair> commands;
		std::map<std::string, double> relevantParameters();
		
	public:
		/*! Get the command list map
		* \return Command list */
		std::map<int, TrDecodePair> getCommands() const {return commands;}
		
		/*! Get a command identified by its order in the burst 
		* \param order The command identified by its order of programming (init)
		* \return command TrDecodePair */
		TrDecodePair getCommand(int) const;

		/*! Find a particular decode identified by the string
		* Replace it within the Decode pair.
		* \param name The command identifier (string)
		* \param command The command (TrDecodePair) 
		* \return OK */
		int updateDecodePair(std::string, TrDecodePair);
		int addCommand(TrDecodePair);
		/*! Get the number of commands in the list 
		 * \return NumberOfCommands */
		virtual int getLength() const {return commands.size();}
		
		/*! When cast as pointer to base we want to know what the derived type was
		 * \return DerivedType as a string */
		virtual std::string getType() const {return "CommandList";}
		
		virtual double getRelevant(std::string) const;
		
		/*! Python-style access operator, kept non-public 
		 * \param IndexOfCommand
		 * \return Command */
		//TrDecodePair& operator[](int id);
		//const TrDecodePair& operator[](int id) const;
		
		

};

#endif

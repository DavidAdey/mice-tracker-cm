#include <string>
#ifndef TRDECODEPAIR_HH
#define TRDECODEPAIR_HH

/*! Object to contain the information for a single  read or write.
* The description allows for replacing of the specific pair within
* the rest of the C&M code */

class TrDecodePair {
	private:
		/*! The address within the  */
		int decode;
		/*! The value to be written or read, or command */		
		int data;		
		/*! Description of what this does */
		std::string meaning;	

	public:
		TrDecodePair();
		TrDecodePair(int, int, std::string);
		inline int getDecode() const {return decode;}
		inline int getData() const {return data;}
		inline std::string getMeaning() const {return meaning;}

};

#endif

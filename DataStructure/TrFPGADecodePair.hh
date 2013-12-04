
#ifndef TRFPGADECODEPAIR_HH
#define TRFPGADECODEPAIR_HH

/*! Object to contain the information for a single FPGA read or write.
* The description allows for replacing of the specific pair within
* the rest of the C&M code */

class TrFPGADecodePair {
	private:
		/*! The address within the FPGA */
		int decode;
		/*! The value to be written or read, or command */		
		int data;		
		/*! Description of what this does */
		std::string meaning;	

	public:
		inline int getDecode() {return decode;}
		inline int getData() {return data;}
		inline std::string getMeaning() {return meaning;}

};

#endif

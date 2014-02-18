#include "TrPICWrapper.hh"

TrPICCommandList TrPICWrapper::wrapAsPICCommands(TrFPGACommandList *commands) {
	for (unsigned int command = 0; command < commands->getLength(); ++command) {
		int decode = commands->getCommands()[command].getDecode();
		int data = commands->getCommands()[command].getData();
		TrDecodePair picCommand1 = TrDecodePair(0x10, 0x100,"");
		TrDecodePair picCommand2 = TrDecodePair(0x11, decode,"");
		TrDecodePair picCommand3 = TrDecodePair(0x11, data,"");
	}
}
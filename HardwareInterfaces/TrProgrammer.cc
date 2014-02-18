#include "TrProgrammer.hh"

TrProgrammer::TrProgrammer() {
	/*! Create a new PIC programmer */
	TrPICProgrammer* picProgrammer = new TrPICProgrammer();
	
	/*! Cast it as its base Interface Programmer and add to programmer map 
	 * The inheritence is polymorphic and so it will "remember" some PICProgrammer functions */
	programmers.insert(std::pair<std::string,TrInterfaceProgrammer*>("PICProgrammer",dynamic_cast<TrInterfaceProgrammer*>(picProgrammer) ));
	
	/*! 1553*/
	Tr1553Programmer* mil1553Programmer = new Tr1553Programmer();
	programmers.insert(std::pair<std::string,TrInterfaceProgrammer*>("1553Programmer",dynamic_cast<TrInterfaceProgrammer*>(mil1553Programmer) ));
	/*! FPGA */
	TrFPGAProgrammer* fpgaProgrammer = new TrFPGAProgrammer();
	programmers.insert(std::pair<std::string,TrInterfaceProgrammer*>("FPGAProgrammer",dynamic_cast<TrInterfaceProgrammer*>(fpgaProgrammer) ));
	/*! VME */
	TrVMEProgrammer* vmeProgrammer = new TrVMEProgrammer();
	programmers.insert(std::pair<std::string,TrInterfaceProgrammer*>("VMEProgrammer",dynamic_cast<TrInterfaceProgrammer*>(vmeProgrammer) ));
	/*! TriPt */
	TrTriPtStreamProgrammer* triptProgrammer = new TrTriPtStreamProgrammer();
	programmers.insert(std::pair<std::string,TrInterfaceProgrammer*>("TriPtProgrammer",dynamic_cast<TrInterfaceProgrammer*>(triptProgrammer) ));
}

TrProgrammer::~TrProgrammer() {
	/*! Delete the programmer pointers */
	delete programmers["PICProgrammer"];
	delete programmers["1553Programmer"];
	delete programmers["FPGAProgrammer"];
	delete programmers["VMEProgrammer"];
	delete programmers["TriPtProgrammer"];
}

int TrProgrammer::programCommand(TrCommandListHolder<TrCommandList*> commands) {
	int result = 0;
	for (unsigned int i = 0; i< commands.getLength(); ++i) {
		/*! Get the command type (polymorphically inherited */
		std::string type = commands[i]->getType();
		result |= programmers[type]->program(commands[i]);
	}
	return result;
}
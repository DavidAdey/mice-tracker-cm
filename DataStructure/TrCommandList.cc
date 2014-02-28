#include "TrCommandList.hh"

int TrCommandList::updateDecodePair(std::string purpose, TrDecodePair decode_data) {
	
}

/*! Overloaded operator to allow Python style access to the command liust map */
//TrDecodePair& TrCommandList::operator[](int id) {
	/*! If the index of the commands doesn't exist, create a new command */
	/*if (commands.find(id) == commands.end()) {
		commands.insert(std::pair<int, TrDecodePair>(id, TrDecodePair()));
		return commands[id];
	}
	else {*/
//		return commands[id];
	//}
//}

/*const TrDecodePair& TrCommandList::operator[](int id) const {
	return const_cast<const TrDecodePair&>(commands[id]);
}*/
double TrCommandList::getRelevant(std::string) const {return 0.0;}

int TrCommandList::addCommand(TrDecodePair pair) {
	commands.insert(std::pair<int, TrDecodePair>(commands.size(),pair));
	return 0;
}

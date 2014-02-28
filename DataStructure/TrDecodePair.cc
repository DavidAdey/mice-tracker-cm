#include "TrDecodePair.hh"

TrDecodePair::TrDecodePair() {}

TrDecodePair::TrDecodePair(int decodeIn, int dataIn, std::string meaningIn) {
	decode = decodeIn;
	data = dataIn;
	meaning = meaningIn;
}
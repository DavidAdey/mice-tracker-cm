

TrAFEInitialisationReadbackState::TrAFEInitialisationReadbackState() {
	prepareReadValueMap();
}

int TrAFEInitialisationReadbackState::prepareReadValueMap() {
	readValues.insert(std::pair<std::string, bool> ("bias",false));
	readValues.insert(std::pair<std::string, bool> ("temperature",false));
	readValues.insert(std::pair<std::string, bool> ("bias",false));
}

#include "TriPtInitialisaionStateTester.hh"

int TriPtInitialisationStateTester::testAll() {
	combinedTestResult &= testConstructor();
	return combinedTestResult;
}

int TriPtInitialisationStateTester::testConstructor() {
	int result = 1;
	testResults.append(std::pair<std::string, bool>("constructor",true));
	try {
		TriPTInitialisationState testState = TriPtInitialisationState();
	}
	catch (...) {
		testResults["constructor"] = false;
		result = 0;
	}
	return result;
}
		

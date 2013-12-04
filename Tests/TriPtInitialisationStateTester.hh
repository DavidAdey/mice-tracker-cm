#include "TrackerCodeTester.hh"
#include "TriPtInitialisationState.hh"

class TriPtInitialisationStateTester : public TrackerCodeTester {

	private:
		int combinedTestResult;
		std::map<std::string, bool> testResults;
	public:
		int testAll();
		int testConstructor();
		int testGetValue();

};

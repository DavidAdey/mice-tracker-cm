/*! std includes */
#include <map>
#include <string>
/*! CM software includes */
#include "TrAFEObject.hh"
#include "TrFPGACommandList.hh"


/*! Storage class represnting values written to the Digitial FPGAs */
class TrDigitalInitialisationState : public TrAFEObject {
	private:
		/*! Values with physical meaning */
		std::map<std::string, int> parameterValues;
		/*! Values written to registers */
		std::map<int, int> registerValues;
		/*! Block parameter-less commands, eg. turn on, load firmware */
		std::map<std::string, TrFPGACommandList> fpgaCommands;
	public:
		/*! Constructor */
		TrDigitalInitialisationState();
		/*! Setup the maps 
		 * \return CalledSuccessfully */
		int setupParameterMap();
		/*! Convert physical values into register values 
		 * \return CalledSuccessfully */
		int prepareRegisterValues();
		/*! Add the discriminator pipeline depth
		 * \param PipelineDepth
		 * \return CalledSuccessfully */
		int insertDiscriminatorPipeline(int);
};
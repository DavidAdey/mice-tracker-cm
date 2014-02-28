#ifndef TRFPGAINITIALISATIONSTATE_HH
#define TRFPGAINITIALISATIONSTATE_HH

#include "TrAFEObject.hh"
#include "TrCommandList.hh"
#include "TrCommandListHolder.hh"

class TrFPGAInitialisationState : public TrAFEObject {
	private:
	protected:
		TrCommandListHolder<TrCommandList*> commands;
	public:
		virtual TrCommandList getWriteCommand() const;
		virtual int prepareCommandLists();
};

#endif
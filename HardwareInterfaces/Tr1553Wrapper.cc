#include "Tr1553Wrapper.hh"

Tr1553CommandList* Tr1553Wrapper::wrapAs1553Commands(TrPICCommandList* list) {
	Tr1553CommandList* l = new Tr1553CommandList();
	return l;
}
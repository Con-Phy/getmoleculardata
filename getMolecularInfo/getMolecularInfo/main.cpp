#include "getmolecularinfo.h"

int main(int argc, char *argv[])
{
	GetMolecularInfo molecular("D:/2017-06-01-/2017-09-21-gdbOganicMolecular/dsgdb9nsd.xyz/test/000264_C3H8N2O.xyz");
	MolecularInfo my=molecular.getMolecularInfo();
	//my=molecular.getMolecularInfo();
	my.clearAll();
}

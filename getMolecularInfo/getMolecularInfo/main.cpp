#include "getmolecularinfo.h"
#include <QDir>


int main(int argc, char *argv[])
{
	QString rootPath("D:/2017-06-01-/gdbOganicMolecular/dsgdb9nsd.xyz/test/");
	QDir dir;
	dir.setPath(rootPath);
	dir.setFilter(QDir::Files | QDir::NoSymLinks);
	QFileInfoList list = dir.entryInfoList();

	QString groundname = rootPath+"groundState/";
	QString s1name = rootPath+"s1State/";
	QString t1name = rootPath+"t1State/";
	QDir gstates(groundname);
	if (!gstates.exists())
	{
		gstates.mkdir(groundname);
	}
	QDir s1states(s1name);
	if (!s1states.exists())
	{
		s1states.mkdir(s1name);
	}
	QDir t1states(t1name);
	if (!t1states.exists())
	{
		t1states.mkdir(t1name);
	}
	
	MolecularInfo my;

	for (int i = 0; i < list.size(); ++i) 
	{
		my.clearAll();
		QFileInfo fileInfo = list.at(i);
		QString names    = fileInfo.fileName();
		QString dirnames = fileInfo.absoluteFilePath();

		QList<QString> list = names.split(".");

		GetMolecularInfo molecular(dirnames);
		my=molecular.getMolecularInfo();

		QString molecularfile = groundname + list.at(0)+"/";


	}
	//GetMolecularInfo molecular("D:/2017-06-01-/2017-09-21-gdbOganicMolecular/dsgdb9nsd.xyz/test/055492_C6H7NO2.xyz");
	//MolecularInfo my=molecular.getMolecularInfo();
	//my=molecular.getMolecularInfo();
	//my.clearAll();
}

#include "getmolecularinfo.h"
#include <QFile>
#include <QList>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

GetMolecularInfo::GetMolecularInfo(QString str):file_dir(str)
{
	parseFile();
}

GetMolecularInfo::~GetMolecularInfo()
{

}
int GetMolecularInfo::parseFile()
{
	QFile in_file(file_dir);
	if (!in_file.open(QIODevice::ReadOnly | QIODevice::Text))
		return -2;
	QTextStream in(&in_file);
	QString line = in.readLine();
	QStringList line_info;
	unsigned int n = 1;

	while (!line.isNull())
	{
		line_info = line.split(QRegExp("\\s+"),QString::SkipEmptyParts);
		QString pattern("[0-9]+");
		QRegExp rx(pattern);
		if (!line_info.isEmpty() && rx.exactMatch(line_info[0]))
		{
			molecular_info.total_atom = line_info.at(0).toInt();
		}
		if (!line_info.isEmpty()&& line_info.at(0)=="gdb")
		{
			molecular_info.tag   = line_info.at(0);
			molecular_info.index = line_info.at(1).toInt();
			molecular_info.A     = line_info.at(2).toDouble();
			molecular_info.B     = line_info.at(3).toDouble();
			molecular_info.C     = line_info.at(4).toDouble();
			molecular_info.mu    = line_info.at(5).toDouble();
			molecular_info.alpha = line_info.at(6).toDouble();
			molecular_info.homo  = line_info.at(7).toDouble();
			molecular_info.lumo  = line_info.at(8).toDouble();
			molecular_info.gap   = line_info.at(9).toDouble();
			molecular_info.r2    = line_info.at(10).toDouble();
			molecular_info.zpve  = line_info.at(11).toDouble();
			molecular_info.U0    = line_info.at(12).toDouble();
			molecular_info.U     = line_info.at(13).toDouble();
			molecular_info.H     = line_info.at(14).toDouble();
			molecular_info.G     = line_info.at(15).toDouble();
			molecular_info.Cv    = line_info.at(16).toDouble();
		}
		pattern = "([^0-9])+((\\s*)(-*)([0-9]+(\\.+)[0-9]+)(.*)){4}";
		rx.setPattern(pattern);
		if ( rx.exactMatch(line))
		{
			qDebug()<<line;
			AtomPosition temp;
			temp.atom_name = line_info.at(0);
			temp.x         = line_info.at(1).toDouble();
			temp.y         = line_info.at(2).toDouble();
			temp.z         = line_info.at(3).toDouble();
			temp.charge    = line_info.at(4).toDouble();
			molecular_info.atom_postion.push_back(temp);
		}

		pattern = "(\\s*[0-9]*(\\.+)[0-9]*\\s*)+";
		rx.setPattern(pattern);
		if (rx.exactMatch(line))
		{
			qDebug()<<line;
			for (unsigned int i = 0;i<line_info.size();i++)
			{
				molecular_info.vibration.push_back(line_info.at(i).toDouble());
			}
		}
		if (n==(molecular_info.total_atom+3+1))
		{
			qDebug()<<line;
			molecular_info.smiles.push_back(line_info.at(0));
			molecular_info.smiles.push_back(line_info.at(1));
		}
		pattern = "InChI=(.*)";
		rx.setPattern(pattern);
		if (rx.exactMatch(line))
		{
			qDebug()<<line;
			QList<QString> names = line_info.at(0).split("/");
			molecular_info.molecular_name = names.at(1);
		}

		line = in.readLine();
		n++;
	}
	return 1;
}
MolecularInfo GetMolecularInfo::getMolecularInfo()
{
	return molecular_info;
}

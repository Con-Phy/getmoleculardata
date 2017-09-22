#ifndef GETMOLECULARINFO_H
#define GETMOLECULARINFO_H
#include <QString>
#include <QVector>

struct AtomPosition 
{
	QString atom_name;
	double x;
	double y;
	double z;
	double charge;
	AtomPosition(){atom_name="";x=0;y=0;z=0;charge=0.0;}
	AtomPosition &operator=(const AtomPosition &a)
	{
		this->atom_name = a.atom_name;
		this->x         = a.x;
		this->y         = a.y;
		this->z         = a.z;
		this->charge    = a.charge;
		return *this;
	}
};

struct MolecularInfo 
{
	
	QString molecular_name;
	int total_atom;
	QString tag;
	int index;
	double A;
	double B;
	double C;
	double mu;
	double alpha;
	double homo;
	double lumo;
	double gap;
	double r2;
	double zpve;
	double U0;
	double U;
	double H;
	double G;
	double Cv;

	QVector<AtomPosition> atom_postion;
	QVector<double> vibration;
	QVector<QString> smiles;

	MolecularInfo(){molecular_name="";tag="";index=0;total_atom=0;A=0.0;
	B=0.0;C=0.0;mu=0.0;alpha=0.0;homo=0.0;lumo=0.0;gap=0.0;r2=0.0;zpve=0.0;U0=0.0;U=0.0;
	H=0.0;G=0.0;Cv=0.0;}
	void clearAll(){atom_postion.clear();vibration.clear();smiles.clear();molecular_name="";tag="";index=0;total_atom=0;A=0.0;
	B=0.0;C=0.0;mu=0.0;alpha=0.0;homo=0.0;lumo=0.0;gap=0.0;r2=0.0;zpve=0.0;U0=0.0;U=0.0;
	H=0.0;G=0.0;Cv=0.0;}
	MolecularInfo &operator=(const MolecularInfo &molecular)
	{
		this->molecular_name = molecular.molecular_name;
		this->total_atom     = molecular.total_atom;
		this->tag            = molecular.tag;
		this->A              = molecular.A;
		this->B              = molecular.B;
		this->C              = molecular.C;
		this->mu             = molecular.mu;
		this->alpha          = molecular.alpha;
		this->homo           = molecular.homo;
		this->lumo           = molecular.lumo;
		this->gap            = molecular.gap;
		this->r2             = molecular.r2;
		this->zpve           = molecular.zpve;
		this->U0             = molecular.U0;
		this->U              = molecular.U;
		this->H              = molecular.H;
		this->G              = molecular.G;
		this->Cv             = molecular.Cv;
		this->atom_postion   = molecular.atom_postion;
		this->vibration      = molecular.vibration;
		this->smiles         = molecular.smiles;
		return *this;
	}
};

class GetMolecularInfo
{
public:
	GetMolecularInfo(QString str);
	~GetMolecularInfo();
public:
	MolecularInfo getMolecularInfo();
private:
	int parseFile();
private:
	QString file_dir;
private:
	MolecularInfo molecular_info;
};

#endif // GETMOLECULARINFO_H

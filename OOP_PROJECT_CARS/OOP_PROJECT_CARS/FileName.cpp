#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string >
#include <iostream>
#include <fstream>
#include<list>
#include<vector>
#include<map>
#include<set>
using namespace std;

class IClient
{
public:
	virtual float sumaMarita() = 0;
};

class AbsIncasare
{
public:
	virtual float pretcuTVA() = 0;
	virtual void afisare() = 0;
};



// diferite rapoarte care sa analizeze activitatea utilizatorilor (data mining in seturile de date pentru a extrage informatii cu privire la activitatea utilizatorilor)
class DataMining
{
private:
	int nrAfisari;
	int nrObiecte;

public:

	DataMining()
	{
		this->nrAfisari = 0;
		this->nrObiecte = 0;
	}

	void crestereAfisari()
	{
		this->nrAfisari++;
	}
	void obiecteCreate()
	{
		this->nrObiecte++;
	}

	void raportAfisari(ofstream& fout)
	{
		fout << "Utilizatorul a folosit functia de afisare de " << this->nrAfisari << " ori " << endl;
	}
	void raportNrObiecte(ofstream& fout)
	{
		fout << " Utilizatorul a create " << this->nrObiecte << " obiecte ";
	}
};

DataMining dm;

class Dealer
{
private:
	string nume;
	char adresa[100];
	string nrtel;
	int nrMasiniStoc;
	string* masiniStoc;

public:


	void scriereBinar(ofstream& o)
	{
		// scriere nume
		int lungime = strlen(this->nume.c_str()) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->nume.c_str(), sizeof(char) * lungime);

		// scriere adresa
		lungime = strlen(this->adresa) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->adresa, sizeof(char) * lungime);

		// scriere nrtel
		lungime = strlen(this->nrtel.c_str()) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->nrtel.c_str(), sizeof(char) * lungime);


		// scriere nrMasini+ masini Stoc
		o.write((char*)&this->nrMasiniStoc, sizeof(this->nrMasiniStoc));
		for (int i = 0; i < this->nrMasiniStoc; i++) {
			lungime = strlen(this->masiniStoc[i].c_str()) + 1;
			o.write((char*)&lungime, sizeof(int));
			o.write(this->masiniStoc[i].c_str(), sizeof(char) * lungime);

		}
	}

	void citireBinar(ifstream& in)
	{
		// citire nume
		int lungime2;
		in.read((char*)&lungime2, sizeof(int));
		char s1[200];
		in.read(s1, lungime2);
		this->nume = s1;

		//citire adresa
		in.read((char*)&lungime2, sizeof(int));
		char s5[100];
		in.read(s5, lungime2);
		strcpy(this->adresa, s5);

		//citire nrtel
		in.read((char*)&lungime2, sizeof(int));
		char s2[200];
		in.read(s2, lungime2);
		this->nrtel = s2;

		//citire nrMasini+ masini stoc
		in.read((char*)&this->nrMasiniStoc, sizeof(this->nrMasiniStoc));
		delete[]  this->masiniStoc;
		this->masiniStoc = new string[this->nrMasiniStoc];
		for (int i = 0; i < this->nrMasiniStoc; i++) {
			in.read((char*)&lungime2, sizeof(int));
			char s3[200];
			in.read(s3, lungime2);
			this->masiniStoc[i] = s3;

		}

	}


	// constructor fara paramatri
	Dealer()
	{
		this->nume = "na";
		strcpy(this->adresa, "na");
		this->nrtel = "na";
		this->nrMasiniStoc = 0;
		this->masiniStoc = NULL;
	}

	// constructor cu toti parametrii
	Dealer(string numed, char* adresad, string nrteld, int numard, string* masini)
	{
		dm.obiecteCreate();
		if (numed.length() > 2)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
			cout << "\nNumele introdus este gresit";
		}
		if (strlen(adresad) > 2)
		{
			strcpy(this->adresa, adresad);
		}
		else
		{
			strcpy(this->adresa, "na");
			cout << "\n Adresa introdusa este gresita";
		}
		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
			cout << "\nNr de tel introdus este gresit";
		}
		if (numard > 0 && masini != NULL)
		{
			this->nrMasiniStoc = numard;
			this->masiniStoc = new string[numard];
			int i;
			for (i = 0; i < numard; i++)
			{
				this->masiniStoc[i] = masini[i];
			}
		}
		else
		{
			this->nrMasiniStoc = 0;
			this->masiniStoc = NULL;
		}
	}

	// constructor cu cativa parametri
	Dealer(string numed, const char* adresad, string nrteld)
	{
		dm.obiecteCreate();
		nrMasiniStoc = 0;
		masiniStoc = NULL;
		if (numed.length() > 2)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
			cout << "\nNumele introdus este gresit";
		}
		if (strlen(adresad) > 2)
		{
			strcpy(this->adresa, adresad);
		}
		else
		{
			strcpy(this->adresa, "na");
			cout << "\n Adresa introdusa este gresita";
		}
		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
			cout << "\nNr de tel introdus este gresit";
		}
	}

	// constructor de copiere
	Dealer(const Dealer& sursa)
	{
		dm.obiecteCreate();
		this->nume = sursa.nume;
		strcpy(this->adresa, sursa.adresa);
		this->nrtel = sursa.nrtel;
		this->nrMasiniStoc = sursa.nrMasiniStoc;
		this->masiniStoc = new string[sursa.nrMasiniStoc];
		int i;
		for (i = 0; i < sursa.nrMasiniStoc; i++)
		{
			this->masiniStoc[i] = sursa.masiniStoc[i];
		}
	}

	// get si set pentru atribute
	string getNume()
	{
		cout << endl;
		return this->nume;
	}
	void setNume(string numed)
	{
		if (numed.length() > 2)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
			cout << "\nnumele introdus este gresit";
		}
	}
	char* getAdresa()
	{
		cout << endl;
		return this->adresa;
	}

	void setAdresa(char* adresad)
	{
		if (strlen(adresad) > 2)
		{

			strcpy(this->adresa, adresad);
		}
		else
		{

			strcpy(this->adresa, "na");
			cout << "\n Adresa introdusa este gresita";
		}
	}
	string getNrTel()
	{
		cout << endl;
		return this->nrtel;
	}
	void setNrTel(string nrteld)
	{
		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
			cout << "\nNr de tel introdus este gresit";
		}
	}
	int getNrMasini()
	{
		cout << endl;
		return this->nrMasiniStoc;
	}
	string* getMasiniStoc()
	{

		return this->masiniStoc;

	}

	void setMasiniStoc(int numard, string* masini)
	{
		if (numard > 0 && masini != NULL)
		{

			delete[] masiniStoc;
			this->nrMasiniStoc = numard;
			this->masiniStoc = new string[numard];
			int i;
			for (i = 0; i < numard; i++)
			{
				this->masiniStoc[i] = masini[i];
			}
		}
		else
		{
			this->nrMasiniStoc = 0;
			this->masiniStoc = NULL;
		}
	}

	// apel destructor
	~Dealer()
	{
		delete[] this->masiniStoc;
	}

	// operator=
	Dealer& operator=(const Dealer& sursa)
	{
		if (this != &sursa)
		{

			delete[] this->masiniStoc;
			this->nume = sursa.nume;
			strcpy(this->adresa, sursa.adresa);
			this->nrtel = sursa.nrtel;
			this->nrMasiniStoc = sursa.nrMasiniStoc;
			this->masiniStoc = new string[sursa.nrMasiniStoc];
			int i;
			for (i = 0; i < sursa.nrMasiniStoc; i++)
			{
				this->masiniStoc[i] = sursa.masiniStoc[i];
			}
		}
		return *this;
	}

	// functie de afisare;
	void afisare()
	{

		cout << "\n-------------------------------";
		cout << "\nDealer:" << nume;
		cout << "\nAdresa:" << adresa;
		cout << "\nNumarul de telefon este:" << nrtel;
		cout << "\nNumarul de masini in stoc:" << nrMasiniStoc;
		if (nrMasiniStoc > 0)
		{
			int i;
			for (i = 0; i < nrMasiniStoc; i++)
			{
				cout << "\nMasina de pe pozitia  " << i + 1 << " este :" << masiniStoc[i];
			}
		}
		cout << "\n-------------------------------";
	}

	// functie de prelucrare
	void scaderenrMasini(int nrmasini)// cum sa fac sa imi citeasca cu spatiu;
	{

		int nrmasiniNoi;
		string* masinistocaux;
		nrmasiniNoi = this->nrMasiniStoc - nrmasini;
		masinistocaux = new string[nrmasiniNoi];
		int i;
		for (i = 0; i < nrmasiniNoi; i++)
		{
			masinistocaux[i] = this->masiniStoc[i];
		}

		this->nrMasiniStoc = nrmasiniNoi;
		delete[] this->masiniStoc;
		this->masiniStoc = masinistocaux;


	}


	// supraincarcare operator <<
	friend ostream& operator<<(ostream& out, const Dealer  sursa)
	{
		dm.crestereAfisari();
		out << "\n-------------------------------";
		out << "\nDealer:" << sursa.nume;
		out << "\nAdresa:" << sursa.adresa;
		out << "\nNumarul de telefon este:" << sursa.nrtel;
		out << "\nNumarul de masini in stoc:" << sursa.nrMasiniStoc;
		if (sursa.nrMasiniStoc > 0)
		{
			int i;
			for (i = 0; i < sursa.nrMasiniStoc; i++)
			{
				out << "\nMasina de pe pozitia  " << i + 1 << " este :" << sursa.masiniStoc[i];
			}
		}
		out << "\n-------------------------------";
		return out;
	}


	friend ofstream& operator<<(ofstream& out, const Dealer  sursa)
	{

		out << sursa.nume << endl;
		out << sursa.adresa << endl;
		out << sursa.nrtel << endl;
		out << sursa.nrMasiniStoc << endl;
		if (sursa.nrMasiniStoc > 0)
		{
			int i;
			for (i = 0; i < sursa.nrMasiniStoc; i++)
			{
				out << sursa.masiniStoc[i] << endl;
			}
		}
		return out;
	}


	// supraincarcare operator >>
	friend istream& operator>>(istream& in, Dealer& sursa)
	{
		cout << "\nDealer: ";
		in >> sursa.nume;
		in.ignore();

		cout << "\nAdresa:";
		char buffer[200];
		in.getline(buffer, 200);
		strcpy(sursa.adresa, buffer);

		cout << "\nNr de telefon:";
		in >> sursa.nrtel;

		cout << "\nNumarul de masini in stoc:";
		in >> sursa.nrMasiniStoc;
		delete[] sursa.masiniStoc;
		sursa.masiniStoc = new string[sursa.nrMasiniStoc];
		int i;
		for (i = 0; i < sursa.nrMasiniStoc; i++)
		{
			cout << "\nMasina de pe pozitia " << i + 1 << " este :";
			in >> sursa.masiniStoc[i];
		}
		return in;
	}


	friend     ifstream& operator>> (ifstream& in, Dealer& sursa) // & imereu cu apersand ca sa faci modificari in orignal 
	{
		in >> sursa.nume;
		in.ignore();
		char buffer[200];
		in.getline(buffer, 200);
		strcpy(sursa.adresa, buffer);

		in >> sursa.nrtel;

		in >> sursa.nrMasiniStoc;

		delete[] sursa.masiniStoc;
		sursa.masiniStoc = new string[sursa.nrMasiniStoc];
		int i;
		for (int i = 0; i < sursa.nrMasiniStoc; i++)
		{
			in >> sursa.masiniStoc[i];
		}
		return in;
	}

	// operatorul + imi adauga o masina in stoc
	Dealer operator+(int nrmasiniaduse)
	{
		if (nrmasiniaduse >= 0)
		{
			int nrmasiniNoi;
			string* masinistocaux;
			nrmasiniNoi = this->nrMasiniStoc + nrmasiniaduse;
			masinistocaux = new string[nrmasiniNoi];
			int i;
			for (i = 0; i < this->nrMasiniStoc; i++)
			{
				masinistocaux[i] = this->masiniStoc[i];
			}
			for (i = this->nrMasiniStoc; i < nrmasiniNoi; i++)
			{
				cout << "\nIntroduceti masina noua in stoc:";
				cin >> masinistocaux[i];
			}
			//this->nrMasiniStoc = nrmasiniNoi;
			delete[] this->masiniStoc;
			this->masiniStoc = masinistocaux;
		}
		else
		{
			cout << "\nNu se poate adauga un nr negativ de masini";
		}
		return *this;
	}

	//op +=
	Dealer operator+=(int nrMasiniAduse)
	{
		return *this + nrMasiniAduse;
	}

	// op ++ postincrementare?
	Dealer operator++()
	{
		return *this + 1;
	}

	// op ++ preincrementare
	Dealer operator++(int)
	{
		Dealer copie(*this);
		*this += 1;
		return copie;
	}

	// op index[]
	string& operator[](int i)
	{
		if (i <= this->nrMasiniStoc && i > 0)
		{
			return this->masiniStoc[i - 1];
		}
		else
		{
			cout << "\nNu a fost introdus un index corect";
		}
	}

	// op ==
	bool operator==(Dealer sursa)
	{
		bool gasit = true;
		if (this->nume != sursa.nume)
		{
			gasit = false;
		}
		if (strcmp(this->adresa, sursa.adresa) != 0)
		{
			gasit = false;
		}
		if (this->nrtel != sursa.nrtel)
		{
			gasit = false;
		}
		if (this->nrMasiniStoc != sursa.nrMasiniStoc)
		{
			gasit = false;
		}
		else
		{
			for (int i = 0; i < sursa.nrMasiniStoc; i++)
			{

				if (this->masiniStoc[i] != sursa.masiniStoc[i])
				{
					gasit = false;
				}
			}
		}
		return gasit;
	}

	// op <
	bool operator<(Dealer sursa)
	{
		if (this->nrMasiniStoc < sursa.nrMasiniStoc)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//op !
	bool  operator! () {
		if (this->nrMasiniStoc > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// op cast
	explicit operator int() {
		return this->nrMasiniStoc;
	}

	void raportDealer(const char* fisieraport)
	{
		ofstream fout;
		fout.open(fisieraport, ofstream::out);
		fout << "Dealer ul: " << this->getNume() << " are : " << this->getNrMasini() << " masini." << endl;
		fout << "Masinile sunt:";
		for (int i = 0; i < this->getNrMasini(); i++)
		{
			fout << this->getMasiniStoc()[i] << " ";
		}

	}
};

class Masina
{
private:
	const int serieSasiu = 0;
	string marca = "na";
	char model[60] = { "na" };
	int anFabricatie = 0;
	int km = 0;
	int nrRevizii = 0;
	int* reviziiKm = NULL;

public:

	void scriereBinar(ofstream& o)
	{
		// scriere marca
		int lungime = strlen(this->marca.c_str()) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->marca.c_str(), sizeof(char) * lungime);

		// scriere model
		lungime = strlen(this->model) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write((char*)&this->model, lungime * sizeof(char));


		// scriere an Fabricatie
		o.write((char*)&this->anFabricatie, sizeof(this->anFabricatie));

		//scriere km
		o.write((char*)&this->km, sizeof(this->km));


		// scriere nr Revizii + revizii Km
		o.write((char*)&this->nrRevizii, sizeof(this->nrRevizii));
		for (int i = 0; i < this->nrRevizii; i++) {

			o.write((char*)&this->reviziiKm[i], sizeof(this->reviziiKm[i]));
		}
	}

	void citireBinar(ifstream& in)
	{
		// citire marca
		int lungime;
		in.read((char*)&lungime, sizeof(int));
		char s1[200];
		in.read(s1, lungime);
		this->marca = s1;

		//citire model
		in.read((char*)&lungime, sizeof(int));
		in.read(s1, lungime);
		strcpy(this->model, s1);
		this->setModel(s1);

		//citire an Fabricatie
		in.read((char*)&this->anFabricatie, sizeof(this->anFabricatie));

		//citire km
		in.read((char*)&this->km, sizeof(this->km));

		// scriere nr Revizii + revizii Km
		in.read((char*)&this->nrRevizii, sizeof(this->nrRevizii));
		delete[]  this->reviziiKm;
		this->reviziiKm = new int[this->nrRevizii];
		for (int i = 0; i < this->nrRevizii; i++) {
			in.read((char*)&this->reviziiKm[i], sizeof(this->reviziiKm[i]));

		}

	}


	// constructor fara parametri
	Masina()
	{

	}

	// constructor cu toti parametri
	Masina(int seried, string marcad, char* modeld, int anfabd, int kmd, int nrReviziid, int* reviziiKmd) :serieSasiu(seried)
	{
		if (marcad.length() > 2)
		{
			this->marca = marcad;
		}
		else
		{
			this->marca = "na";
		}
		if (strlen(modeld) > 1)
		{
			strcpy(this->model, modeld);
		}
		else
		{
			strcpy(this->model, "na");
		}
		if (anfabd > 1990 && anfabd < 2023)
		{
			this->anFabricatie = anfabd;
		}
		else
		{
			this->anFabricatie = 0;
		}
		if (nrReviziid > 0 && reviziiKmd != NULL)
		{
			this->nrRevizii = nrReviziid;
			this->reviziiKm = new int[nrReviziid];
			int i;
			for (i = 0; i < nrReviziid; i++)
			{
				this->reviziiKm[i] = reviziiKmd[i];
			}
		}
		else
		{
			this->nrRevizii = 0;
			this->reviziiKm = NULL;
		}
		if (kmd >= 0)
		{
			this->km = kmd;
		}
		else
		{
			this->km = 0;
		}

	}

	// constructor cu aproape toti parametri
	Masina(int seried, string marcad, char* modeld, int anfabd, int kmd) :serieSasiu(seried)
	{
		if (marcad.length() >= 3)
		{
			this->marca = marcad;
		}
		else
		{
			this->marca = "na";
		}
		if (strlen(modeld) > 1)
		{
			strcpy(this->model, modeld);
		}
		else
		{
			strcpy(this->model, "na");
		}
		if (anfabd > 1990 && anfabd < 2023)
		{
			this->anFabricatie = anfabd;
		}
		else
		{
			this->anFabricatie = 0;
		}
		if (kmd >= 0)
		{
			this->km = kmd;
		}
		else
		{
			this->km = 0;
		}
	}

	// constructor de copiere;
	Masina(const Masina& sursa) :serieSasiu(sursa.serieSasiu)
	{
		this->marca = sursa.marca;
		strcpy(this->model, sursa.model);
		this->anFabricatie = sursa.anFabricatie;
		this->km = sursa.km;
		this->nrRevizii = sursa.nrRevizii;
		this->reviziiKm = new int[sursa.nrRevizii];
		int i;
		for (i = 0; i < sursa.nrRevizii; i++)
		{
			this->reviziiKm[i] = sursa.reviziiKm[i];
		}
	}
	// get si set pt toate atributele
	int getSerieSasiu()
	{
		return this->serieSasiu;
	}
	string getMarca()
	{
		return this->marca;
	}
	void setMarca(string marcad)
	{
		if (marcad.length() >= 3)
		{
			this->marca = marcad;
		}
		else
		{
			this->marca = "na";
		}
	}
	char* getModel()
	{
		return this->model;
	}
	void setModel(char* modeld)
	{
		if (strlen(modeld) > 1)
		{
			strcpy(this->model, modeld);
		}
		else
		{
			strcpy(this->model, "na");
		}
	}
	int getAnFabricatie()
	{
		return this->anFabricatie;
	}
	void setAnFabricatie(int anfabd)
	{
		if (anfabd > 1990 && anfabd < 2023)
		{
			this->anFabricatie = anfabd;
		}
		else
		{
			this->anFabricatie = 0;
		}
	}
	int getKm()
	{
		return this->km;
	}
	void setKm(int kmd)
	{
		if (kmd >= 0)
		{
			this->km = kmd;
		}
		else
		{
			this->km = 0;
		}
	}
	int getNrRevizii()
	{
		return this->nrRevizii;
	}
	int* getReviziikm()
	{
		return this->reviziiKm;
	}
	void setReviziikm(int nrReviziid, int* reviziiKmd)
	{
		if (nrReviziid > 0 && reviziiKmd != NULL)
		{
			delete[] reviziiKm;
			this->nrRevizii = nrReviziid;
			this->reviziiKm = new int[nrReviziid];
			int i;
			for (i = 0; i < nrReviziid; i++)
			{
				this->reviziiKm[i] = reviziiKmd[i];
			}
		}
		else
		{
			this->nrRevizii = 0;
			this->reviziiKm = NULL;
		}
	}

	//apel destructor
	~Masina()
	{
		delete[] this->reviziiKm;
	}

	// operator =
	Masina& operator=(const Masina& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->reviziiKm;
			this->marca = sursa.marca;
			strcpy(this->model, sursa.model);
			this->anFabricatie = sursa.anFabricatie;
			this->km = sursa.km;
			this->nrRevizii = sursa.nrRevizii;
			this->reviziiKm = new int[sursa.nrRevizii];
			int i;
			for (i = 0; i < sursa.nrRevizii; i++)
			{
				this->reviziiKm[i] = sursa.reviziiKm[i];
			}
		}
		return *this;
	}

	// functie de afisare
	void afisare()
	{
		cout << "\n-----------------------";
		cout << "\nSerie sasiu: " << serieSasiu;
		cout << "\nMarca: " << marca;
		cout << "\nModel: " << model;
		cout << "\nAnul fabricatiei: " << anFabricatie;
		cout << "\nNumar kilometri:" << km;
		cout << "\nNumar revizii: " << nrRevizii;
		if (nrRevizii > 0)
		{
			int i;
			for (i = 0; i < nrRevizii; i++)
			{
				cout << "\nKilometrii la intrarea " << i + 1 << " in service sunt:" << reviziiKm[i];
			}
		}
		cout << "\n-----------------------";
	}

	// functie de prelucrare
	void adaugareRevizie(int nrRevizii)
	{
		if (nrRevizii >= 0)
		{
			int nrReviziiaux;
			int* reviziiaux;
			nrReviziiaux = this->nrRevizii + nrRevizii;
			reviziiaux = new int[nrReviziiaux];
			int i;
			for (i = 0; i < this->nrRevizii; i++)
			{
				reviziiaux[i] = this->reviziiKm[i];
			}
			for (i = this->nrRevizii; i < nrReviziiaux; i++)
			{

				cout << "\nIntroduceti noua revizie:";
				cin >> reviziiaux[i];

			}
			this->nrRevizii = nrReviziiaux;
			delete[] this->reviziiKm;
			this->reviziiKm = reviziiaux;
		}
		else
		{
			cout << "\nNu se poate adauga un nr negativ de masini";
		}

	}
	// supraincarcare op <<
	friend ostream& operator<<(ostream& out, Masina sursa)
	{
		out << "\n-----------------------";
		out << "\nSerie sasiu: " << sursa.serieSasiu;
		out << "\nMarca: " << sursa.marca;
		out << "\nModel: " << sursa.model;
		out << "\nAnul fabricatiei: " << sursa.anFabricatie;
		out << "\nNumar kilometri:" << sursa.km;
		out << "\nNumar revizii: " << sursa.nrRevizii;
		if (sursa.nrRevizii > 0)
		{
			int i;
			for (i = 0; i < sursa.nrRevizii; i++)
			{
				out << "\nKilometrii la intrarea " << i + 1 << " in service sunt:" << sursa.reviziiKm[i];
			}
		}
		out << "\n-----------------------";
		return out;
	}

	friend ofstream& operator<<(ofstream& out, Masina sursa)
	{
		out << sursa.marca << endl;
		out << sursa.model << endl;
		out << sursa.anFabricatie << endl;
		out << sursa.km << endl;
		out << sursa.nrRevizii << endl;
		if (sursa.nrRevizii > 0)
		{
			int i;
			for (i = 0; i < sursa.nrRevizii; i++)
			{
				out << sursa.reviziiKm[i] << endl;
			}
		}

		return out;
	}

	// op >>
	friend istream& operator>>(istream& in, Masina& sursa)
	{
		cout << "\nMarca:";
		in >> sursa.marca;
		in.ignore();

		cout << "\nModel :";
		//getline(in, sursa.model);
		in >> sursa.model;
		in.ignore(); // imi sare an fab daca scriu cu spatiu

		cout << "\nAn fabricatie :";
		in >> sursa.anFabricatie;
		in.ignore();
		cout << "\nNumar de kilometrii: ";
		in >> sursa.km;
		cout << "\nNumar de revizii:";
		in >> sursa.nrRevizii;
		delete[] sursa.reviziiKm;
		sursa.reviziiKm = new int[sursa.nrRevizii];
		int i;
		for (i = 0; i < sursa.nrRevizii; i++)
		{
			cout << "\nKilometrii la intrarea " << i + 1 << " in service sunt:";
			in >> sursa.reviziiKm[i];
		}
		return in;
	}

	friend ifstream& operator>>(ifstream& in, Masina& sursa)
	{

		in >> sursa.marca;


		in >> sursa.model;
		in.ignore();

		in >> sursa.anFabricatie;

		in >> sursa.km;

		in >> sursa.nrRevizii;
		delete[] sursa.reviziiKm;
		sursa.reviziiKm = new int[sursa.nrRevizii];
		int i;
		for (i = 0; i < sursa.nrRevizii; i++)
		{
			in >> sursa.reviziiKm[i];
		}
		return in;
	}

	//op +
	Masina operator+(int kmd)
	{
		if (kmd > 0)
		{
			this->km = this->km + kmd;
		}
		else
		{
			cout << "\nNumarul de kilometri nou nu se potriveste cu istoricul service!";
		}
		return *this;
	}

	// op +=
	Masina operator+=(int km)
	{
		return *this + km;
	}

	//op ++ posincrementare
	Masina operator++()
	{
		this->km += 1000;
		return *this;
	}

	//op ++ preincrementare
	Masina operator++(int)
	{
		Masina copie(*this);
		this->km += 1000;
		return copie;
	}

	//op index []
	int& operator[](int i)
	{
		if (i <= this->nrRevizii && i > 0)
		{
			return this->reviziiKm[i - 1];
		}
		else
		{
			cout << "\nNu a fost introdus un index corect";
		}
	}

	//op <
	bool operator<(Masina sursa)
	{
		if (this->km < sursa.km)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// op !
	bool  operator! () {
		if (this->nrRevizii >= 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// op ==
	bool operator==(Masina sursa)
	{
		bool gasit = true;
		if (this->serieSasiu != sursa.serieSasiu)
		{
			gasit = false;
		}
		if (strcmp(this->model, sursa.model) != 0)
		{
			gasit = false;
		}
		if (this->anFabricatie != sursa.anFabricatie)
		{
			gasit = false;
		}
		if (this->km != sursa.km)
		{
			gasit = false;
		}
		if (this->nrRevizii != sursa.nrRevizii)
		{
			gasit = false;
		}
		else
		{
			int i;
			for (i = 0; i < sursa.nrRevizii; i++)
			{
				if (this->reviziiKm != sursa.reviziiKm)
				{
					gasit = false;
				}
			}
		}
		return gasit;

	}

	// op cast
	explicit operator int()
	{
		return this->anFabricatie;
	}
	// pt a putea citi in derivata
	Masina& getMasina()
	{
		return*this;
	}
	void raportMasina(const char* fisier)
	{
		ofstream fout;
		fout.open(fisier, ofstream::out);
		fout << "Masina data este : " << this->getMarca() << ", model: " << this->getModel() << ", din anul: " << this->getAnFabricatie() << endl;
		fout << "\nKilometrii masinii sunt:" << this->getKm() << endl;
		for (int i = 0; i < this->getNrRevizii(); i++)
		{
			fout << "\nRevizia: " << i + 1 << " s a efectuat la: " << this->getReviziikm()[i] << endl;
		}

	}
};

// clasa derivata din masina= MasinaSport

class MasinaSport : public Masina
{
private:
	int capacitate;
	char* tip_motor;

public:

	// constr fara parametri
	MasinaSport()
	{
		this->capacitate = 0;
		this->tip_motor = new char[strlen("na") + 1];
		strcpy(this->tip_motor, "na");
	}

	// constr cu toti parametri
	MasinaSport(int seried, string marcad, char* modeld, int anfabd, int kmd, int nrReviziid, int* reviziiKmd, int capd, char* tipd) : Masina(seried, marcad, modeld, anfabd, kmd, nrReviziid, reviziiKmd)
	{
		if (capd > 1000 && capd <= 6500)
		{
			this->capacitate = capd;
		}
		else
		{
			this->capacitate = 0;
		}

		if (strlen(tipd) >= 2)
		{
			this->tip_motor = new char[strlen(tipd) + 1];
			strcpy(this->tip_motor, tipd);
		}
		else
		{
			this->tip_motor = new char[strlen("na") + 1];
			strcpy(this->tip_motor, "na");;
		}

	}

	// const cu cativa param
	MasinaSport(int seried, string marcad, char* modeld, int anfabd, int kmd, int capd, char* tipd) : Masina(seried, marcad, modeld, anfabd, kmd)
	{
		if (capd > 1000)
		{
			this->capacitate = capd;
		}
		else
		{
			this->capacitate = 0;
		}

		if (strlen(tipd) >= 2)
		{
			this->tip_motor = new char[strlen(tipd) + 1];
			strcpy(this->tip_motor, tipd);
		}
		else
		{
			this->tip_motor = new char[strlen("na") + 1];
			strcpy(this->tip_motor, "na");;
		}
	}

	//get eri
	int getCapacitate()
	{
		return this->capacitate;
	}
	char* getTipMotor()
	{
		return this->tip_motor;
	}

	// set eri

	void setCapacitate(int capd)
	{
		if (capd > 1000)
		{
			this->capacitate = capd;
		}
		else
		{
			this->capacitate = 0;
		}
	}

	void setTipMotor(char* tipd)
	{
		if (strlen(tipd) >= 2)
		{
			this->tip_motor = new char[strlen(tipd) + 1];
			strcpy(this->tip_motor, tipd);
		}
		else
		{
			this->tip_motor = new char[strlen("na") + 1];
			strcpy(this->tip_motor, "na");;
		}
	}


	//destructor
	~MasinaSport()
	{
		delete[] this->tip_motor;
	}

	// constr de copiere
	MasinaSport(const MasinaSport& sursa) : Masina((Masina)sursa)
	{
		this->capacitate = sursa.capacitate;
		this->tip_motor = new char[strlen(sursa.tip_motor) + 1];
		strcpy(this->tip_motor, sursa.tip_motor);
	}

	// op=

	MasinaSport& operator =(const MasinaSport& sursa)
	{
		if (this != &sursa)
		{
			Masina::operator=(sursa);
			delete[]this->tip_motor;
			this->capacitate = sursa.capacitate;
			this->tip_motor = new char[strlen(sursa.tip_motor) + 1];
			strcpy(this->tip_motor, sursa.tip_motor);
		}
		return *this;
	}

	// supraincarcare op <<
	friend ostream& operator<<(ostream& out, MasinaSport sursa)
	{
		out << (Masina)sursa << endl;
		out << "Capacitatea motorului este: " << sursa.capacitate << endl;
		out << "Tipul de motor este: " << sursa.tip_motor << endl;
		return out;
	}

	// op >>
	friend istream& operator>>(istream& in, MasinaSport sursa)
	{
		in >> sursa.getMasina();

		cout << "Capacitatea motorului este: ";
		in >> sursa.capacitate;

		cout << "Tipul de motor este: ";
		char buffer[100];
		in >> buffer;
		delete[] sursa.tip_motor;
		sursa.tip_motor = new char[strlen(buffer) + 1];
		strcpy(sursa.tip_motor, buffer);

		return in;
	}

};

// clasa compusa: fabrica has a masini

class Fabrica
{
private:
	char* nume;
	float cifraAfaceri;
	Masina* masina;

public:
	// constr fara param
	Fabrica()
	{
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");
		this->cifraAfaceri = 1000;
		this->masina = new Masina();
	}

	//constr cu toti param
	Fabrica(char* numed, float cifrad, Masina m)
	{
		if (strlen(numed) > 5)
		{
			this->nume = new char[strlen(numed) + 1];
			strcpy(this->nume, numed);
		}
		else
		{
			this->nume = new char[strlen("na") + 1];
			strcpy(this->nume, "na");
		}

		if (cifrad > 10000)
		{
			this->cifraAfaceri = cifrad;
		}
		else
		{
			this->cifraAfaceri = 1000;
		}
		this->masina = new Masina(m);
	}

	// constr de copiere
	Fabrica(const Fabrica& sursa)
	{
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);
		this->cifraAfaceri = sursa.cifraAfaceri;
		this->masina = new Masina(*sursa.masina);
	}

	//op =
	Fabrica& operator=(const Fabrica& sursa)
	{
		if (this != &sursa)
		{
			delete[]this->nume;
			delete this->masina;
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
			this->cifraAfaceri = sursa.cifraAfaceri;
			this->masina = new Masina(*sursa.masina);
			return *this;
		}
	}
	// destructor
	~Fabrica()
	{
		delete[]this->nume;
		delete this->masina;
	}

	// op <<
	friend ostream& operator<<(ostream& out, Fabrica& sursa)
	{
		out << "Nume: " << sursa.nume << endl;
		out << "Cifra de afaceri: " << sursa.cifraAfaceri << endl;
		out << *sursa.masina << endl;
		return out;
	}


};

class Incasare : public AbsIncasare
{
private:
	char luna[40];
	int an;
	float valoareFaraTva;
	int nrClienti;
	string* clienti;
	static float tva;

public:

	void scriereBinar(ofstream& o)
	{
		// scriere luna
		int lungime3;
		lungime3 = strlen(this->luna) + 1;
		o.write((char*)&lungime3, sizeof(int));
		o.write((char*)&this->luna, lungime3 * sizeof(char));

		// scriere an 
		o.write((char*)&this->an, sizeof(int));

		//scriere valoare fara tva
		o.write((char*)&this->valoareFaraTva, sizeof(float));


		// scriere nr clienti + clienti
		o.write((char*)&this->nrClienti, sizeof(int));
		for (int i = 0; i < this->nrClienti; i++)
		{

			int lungime3 = this->clienti[i].length() + 1;
			o.write((char*)&lungime3, sizeof(int));

			o.write(this->clienti[i].data(), lungime3 * sizeof(char));


		}
	}

	void citireBinar(ifstream& in)
	{
		int lungime4;
		//citire luna
		in.read((char*)&lungime4, sizeof(int));
		char s5[100];
		in.read(s5, lungime4);
		strcpy(this->luna, s5);
		this->setLuna(s5);

		//citire an 
		in.read((char*)&this->an, sizeof(int));

		//citire valoare fara tva
		in.read((char*)&this->valoareFaraTva, sizeof(float));

		// citire nr Clienti + Clienti
		delete[]  this->clienti;
		in.read((char*)&this->nrClienti, sizeof(int));
		this->clienti = new string[this->nrClienti];
		for (int i = 0; i < this->nrClienti; i++)
		{
			in.read((char*)&lungime4, sizeof(int));
			char s3[200];
			in.read(s3, lungime4);
			this->clienti[i] = s3;

		}

	}



	// constructor fara parametri
	Incasare()
	{
		strcpy(this->luna, "na");
		this->an = 0;
		this->valoareFaraTva = 0;
		this->nrClienti = 0;
		this->clienti = NULL;

	}

	// constructor cu toti parametrii
	Incasare(char* lunad, int andat, float valfaraTVAd, int nrclientid, string* clientid)
	{
		if (strlen(lunad) >= 3)
		{
			strcpy(this->luna, lunad);
		}
		else
		{
			strcpy(this->luna, "na");
		}
		if (andat > 2000 && andat <= 2022)
		{
			this->an = andat;
		}
		else
		{
			this->an = 0;
		}
		if (valfaraTVAd > 0)
		{
			this->valoareFaraTva = valfaraTVAd;
		}
		else
		{
			this->valoareFaraTva = 0;
		}
		if (nrclientid > 0 && clientid != NULL)
		{
			this->nrClienti = nrclientid;
			this->clienti = new string[nrclientid];
			int i;
			for (i = 0; i < nrclientid; i++)
			{
				this->clienti[i] = clientid[i];
			}
		}
		else
		{
			this->nrClienti = 0;
			this->clienti = NULL;
		}

	}

	// constructor cu cativa parametri
	Incasare(char* lunad, int andat, float valfaraTVAd)
	{
		if (strlen(lunad) >= 3)
		{
			strcpy(this->luna, lunad);
		}
		else
		{
			strcpy(this->luna, "na");
		}
		if (andat > 2000 && andat <= 2022)
		{
			this->an = andat;
		}
		else
		{
			this->an = 0;
		}
		if (valfaraTVAd > 0)
		{
			this->valoareFaraTva = valfaraTVAd;
		}
		else
		{
			this->valoareFaraTva = 0;
		}
	}

	// apel destructor
	~Incasare()
	{
		delete[] this->clienti;
	}

	// get si set
	char* getLuna()
	{
		return this->luna;
	}
	void setLuna(char* lunad)
	{
		if (strlen(lunad) >= 3)
		{
			strcpy(this->luna, lunad);
		}
		else
		{
			strcpy(this->luna, "na");
		}
	}
	int getAn()
	{
		return this->an;
	}
	void setAn(int andat)
	{
		if (andat > 2000 && andat <= 2022)
		{
			this->an = andat;
		}
		else
		{
			this->an = 0;
		}
	}
	float getValoareFaraTVA()
	{
		return this->valoareFaraTva;
	}
	void setValoareFaraTVA(int valfaraTVAd)
	{
		if (valfaraTVAd > 0)
		{
			this->valoareFaraTva = valfaraTVAd;
		}
		else
		{
			this->valoareFaraTva = 0;
		}
	}
	int getNrClienti()
	{
		return this->nrClienti;
	}
	string* getClienti()
	{
		return this->clienti;
	}
	void setClienti(int nrclientid, string* clientid)
	{
		if (nrclientid > 0 && clientid != NULL)
		{
			delete[] clienti;
			this->nrClienti = nrclientid;
			this->clienti = new string[nrclientid];
			int i;
			for (i = 0; i < nrclientid; i++)
			{
				this->clienti[i] = clientid[i];
			}
		}
		else
		{
			this->nrClienti = 0;
			this->clienti = NULL;
		}
	}
	static float getTva()
	{
		return Incasare::tva;
	}
	static void setTva(float tva)
	{
		if (tva < 0 || tva > 100)
		{
			cout << "\nValoare tva introdusa gresit";
		}
		else
		{
			tva = Incasare::tva;
		}
	}

	// constructor de copiere
	Incasare(const Incasare& sursa)
	{
		strcpy(this->luna, sursa.luna);
		this->an = sursa.an;
		this->valoareFaraTva = sursa.valoareFaraTva;
		this->nrClienti = sursa.nrClienti;
		this->clienti = new string[sursa.nrClienti];
		int i;
		for (i = 0; i < sursa.nrClienti; i++)
		{
			this->clienti[i] = sursa.clienti[i];
		}
	}

	// operator =
	Incasare& operator=(const Incasare& sursa)
	{
		if (this != &sursa)
		{
			delete[] this->clienti;
			strcpy(this->luna, sursa.luna);
			this->an = sursa.an;
			this->valoareFaraTva = sursa.valoareFaraTva;
			this->nrClienti = sursa.nrClienti;
			this->clienti = new string[sursa.nrClienti];
			int i;
			for (i = 0; i < sursa.nrClienti; i++)
			{
				this->clienti[i] = sursa.clienti[i];
			}
		}
		return *this;
	}

	// functie de afisare
	virtual void afisare()
	{
		cout << "\n---------------------";
		cout << "\nLuna:" << luna;
		cout << "\nAnul:" << an;
		cout << "\nValoare fara tva:" << valoareFaraTva;
		cout << "\nTVA:" << tva;
		cout << "\nNumar clienti:" << nrClienti;
		if (nrClienti > 0)
		{
			int i;
			for (i = 0; i < nrClienti; i++)
			{
				cout << "\nClientul " << i + 1 << " este: " << clienti[i];
			}
		}
		cout << "\n---------------------";
	}

	//functie de prelucrare
	virtual float pretcuTVA()
	{
		cout << endl;
		float sumacuTVA = this->valoareFaraTva;
		if (sumacuTVA > 5000)
		{
			sumacuTVA = 0.19 * this->valoareFaraTva + this->valoareFaraTva;
			cout << "Pretul nou cu TVA este de: " << sumacuTVA << endl;
		}
		else
		{
			cout << "pretul nu se modifica cu 19%";
		}
		return 0;
	}

	// operator <<
	friend ostream& operator <<(ostream& out, Incasare sursa)
	{
		out << "\n---------------------";
		out << "\nLuna:" << sursa.luna;
		out << "\nAnul:" << sursa.an;
		out << "\nValoare fara tva:" << sursa.valoareFaraTva;
		out << "\nTVA:" << sursa.tva;
		out << "\nNumar clienti:" << sursa.nrClienti;
		if (sursa.nrClienti > 0)
		{
			int i;
			for (i = 0; i < sursa.nrClienti; i++)
			{
				out << "\nClientul " << i + 1 << " este: " << sursa.clienti[i];
			}
		}
		out << "\n---------------------";
		return out;
	}

	friend ofstream& operator <<(ofstream& out, Incasare sursa)
	{

		out << sursa.luna << endl;
		out << sursa.an << endl;
		out << sursa.valoareFaraTva << endl;
		out << sursa.nrClienti << endl;
		int i;
		for (i = 0; i < sursa.nrClienti; i++)
		{
			out << sursa.clienti[i] << endl;
		}

		return out;
	}

	// operator >>
	friend istream& operator>>(istream& in, Incasare& sursa)
	{
		cout << "\nLuna: ";
		in >> sursa.luna;
		cout << "\nAnul: ";
		in >> sursa.an;
		cout << "\nValoare fara tva:";
		in >> sursa.valoareFaraTva;
		cout << "\nNumar de clienti:";
		in >> sursa.nrClienti;
		delete[]sursa.clienti;
		sursa.clienti = new string[sursa.nrClienti];
		int i;
		for (i = 0; i < sursa.nrClienti; i++)
		{
			cout << "\nClientul " << i + 1 << " este: ";
			in >> sursa.clienti[i];
		}
		return in;
	}

	friend ifstream& operator>>(ifstream& in, Incasare& sursa)
	{
		in >> sursa.luna;

		in >> sursa.an;

		in >> sursa.valoareFaraTva;
		in >> sursa.nrClienti;
		in.ignore();
		delete[]sursa.clienti;
		sursa.clienti = new string[sursa.nrClienti];
		int i;
		for (i = 0; i < sursa.nrClienti; i++)
		{
			in >> sursa.clienti[i];
		}
		return in;
	}

	// operator -
	Incasare& operator-(float valfaraTVAd)
	{
		if (valfaraTVAd > 0)
		{
			this->valoareFaraTva -= valfaraTVAd;
		}
		else
		{
			cout << "\nValoarea introdusa este negativa";
		}
		return *this;
	}

	// op -=
	Incasare& operator-=(float valfaraTvad)
	{
		return*this - valfaraTvad;
	}

	// op []
	string& operator[](int i)
	{
		if (i <= this->nrClienti && i > 0)
		{
			return this->clienti[i - 1];
		}
		else
		{
			cout << "\nNu a fost introdus un index corect!";
		}
	}

	// op ++ postincrementare
	Incasare operator++()
	{
		this->valoareFaraTva += 1200;
		return *this;
	}

	// op ++ preincrementare
	Incasare operator++(int)
	{
		Incasare copie(*this);
		this->valoareFaraTva += 1200;
		return copie;
	}

	// op ==
	bool operator==(Incasare sursa)
	{
		bool gasit = true;
		if (strcmp(this->luna, sursa.luna) != 0)
		{
			gasit = false;
		}
		if (this->an != sursa.an)
		{
			gasit = false;
		}
		if (this->valoareFaraTva != sursa.valoareFaraTva)
		{
			gasit = false;
		}
		if (this->nrClienti != sursa.nrClienti)
		{
			gasit = false;
		}
		else
		{
			int i;
			for (i = 0; i < sursa.nrClienti; i++)
			{
				if (this->clienti != sursa.clienti)
				{
					gasit = false;
				}
			}
		}
		return gasit;
	}

	//op >

	bool operator >(const Incasare& sursa)
	{
		if (valoareFaraTva > sursa.valoareFaraTva)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//op <

	friend bool operator<(const Incasare& i1, const Incasare& i2)
	{
		return i1.an < i2.an;
	}

	// op !
	bool operator! ()
	{
		if (this->an > 2019)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void raportIncasare(const char* fisier)
	{
		ofstream fout;
		fout.open(fisier, ofstream::out);
		fout << "In luna: " << this->getLuna() << ", anul: " << this->getAn() << ",parcul auto a incasat: " << this->getValoareFaraTVA() << " lei,fara TVA" << endl;
		fout << "Clientii de la care s a incasat sunt:";
		for (int i = 0; i < this->getNrClienti(); i++)
		{
			fout << "\nClientul " << i + 1 << " este: " << this->getClienti()[i];
		}

	}

	//op cast
	explicit operator int()
	{
		return this->nrClienti;
	}

	// functie ce ne ajuta sa citim in clasa derivata
	Incasare& getIncasare()
	{
		return*this;
	}

};

// clasa derivata pentru Incasare este Rata;
class Rata : public Incasare
{
private:
	float ratalunara;
	int luniplatite;

public:

	// constr fara param
	Rata()
	{
		this->ratalunara = 0;
		this->luniplatite = 0;
	}

	// constr cu toti param
	Rata(char* lunad, int andat, float valfaraTVAd, int nrclientid, string* clientid, float ratad, int nrlunid) : Incasare(lunad, andat, valfaraTVAd, nrclientid, clientid)
	{
		if (ratad > 200)
		{
			this->ratalunara = ratad;
		}
		else
		{
			this->ratalunara = 0;
		}

		if (nrlunid > 2)
		{
			this->luniplatite = nrlunid;
		}
		else
		{
			this->luniplatite = 0;
		}
	}
	// constr de copiere
	Rata(const Rata& sursa) :Incasare((Incasare)sursa)
	{
		this->ratalunara = sursa.ratalunara;
		this->luniplatite = sursa.luniplatite;
	}

	// op=
	Rata& operator=(const Rata& sursa)
	{
		if (this != &sursa)
		{
			Incasare::operator=(sursa);
			this->ratalunara = sursa.ratalunara;
			this->luniplatite = sursa.luniplatite;
		}
		return *this;
	}

	//op <<
	friend ostream& operator<<(ostream& out, Rata sursa)
	{
		out << Incasare(sursa) << endl;
		out << "Rata lunara are val de: " << sursa.ratalunara << endl;
		out << "Nr de luni pentru care s a platit rata: " << sursa.luniplatite << endl;
		return out;
	}

	// op >>
	friend istream& operator >>(istream& in, Rata sursa)
	{
		in >> sursa.getIncasare();

		cout << "Rata lunara are val de: ";
		in >> sursa.ratalunara;

		cout << "Nr de luni pentru care s a platit rata: ";
		in >> sursa.luniplatite;

		return in;
	}

	//functia virtuala
	float pretcuTVA()
	{
		cout << endl;
		float sumaAchitata;
		sumaAchitata = this->luniplatite * this->ratalunara;
		cout << " Suma achitata pentru cele " << this->luniplatite << " luni este in cuantum de: " << sumaAchitata << endl;
		return 0;
	}

	//functia virtuala
	void afisare()
	{
		cout << "\n---------------------";
		cout << "\nLuna:" << this->getLuna();
		cout << "\nAnul:" << this->getAn();
		cout << "\nValoare fara tva:" << this->getValoareFaraTVA();
		cout << "\nTVA:" << this->getTva();
		cout << "\nNumar clienti:" << this->getNrClienti();
		if (this->getNrClienti() > 0)
		{
			int i;
			for (i = 0; i < this->getNrClienti(); i++)
			{
				cout << "\nClientul " << i + 1 << " este: " << this->getClienti()[i];
			}
		}
		cout << "\nRata lunara este: " << this->ratalunara;
		cout << "\n Nr de luni pentru care s a achitat este: " << this->luniplatite;
		cout << "\n---------------------";
	}
};


enum MetodaPlata
{
	CASH, RATE, ORDINPLATA
};

class Client : public IClient
{
private:
	string nume;
	char prenume[50]{ "na" };
	string nrtel;
	string masinaAchizitionata;
	MetodaPlata metodaPlata;
	int nrRateRamase = 0;
	float* rateRamase = NULL;
	float suma = 0;

public:

	void scriereBinar(ofstream& o)
	{
		// scriere nume
		int lungime = strlen(this->nume.c_str()) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->nume.c_str(), sizeof(char) * lungime);

		// scriere prenume
		lungime = strlen(this->prenume) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write((char*)&this->prenume, lungime * sizeof(char));

		// scriere nrtel
		int lungime3 = strlen(this->nrtel.c_str()) + 1;
		o.write((char*)&lungime3, sizeof(int));
		o.write(this->nrtel.c_str(), sizeof(char) * lungime3);

		// scriere masina Achizitionata
		int lungime4 = strlen(this->masinaAchizitionata.c_str()) + 1;
		o.write((char*)&lungime4, sizeof(int));
		o.write(this->masinaAchizitionata.c_str(), sizeof(char) * lungime4);

		// scriere suma
		o.write((char*)&this->suma, sizeof(this->suma));

		// scriere metoda plata
		o.write((char*)&this->metodaPlata, sizeof(this->metodaPlata));

		// scriere nrRate + rate ramase
		o.write((char*)&this->nrRateRamase, sizeof(this->nrRateRamase));
		for (int i = 0; i < this->nrRateRamase; i++) {

			o.write((char*)&this->rateRamase[i], sizeof(this->rateRamase[i]));
		}
	}

	void citireBinar(ifstream& in)
	{
		// citire nume
		int lungime;
		in.read((char*)&lungime, sizeof(int));
		char s1[200];
		in.read(s1, lungime);
		this->nume = s1;

		//citire prenume
		in.read((char*)&lungime, sizeof(int));
		char s5[100];
		in.read(s5, lungime);
		strcpy(this->prenume, s5);
		this->setPrenume(s5);

		//citire nrtel
		int lungime2;
		in.read((char*)&lungime2, sizeof(int));
		char s2[200];
		in.read(s2, lungime2);
		this->nrtel = s2;

		// citire masina Achizionata
		int lungime3;
		in.read((char*)&lungime3, sizeof(int));
		char s3[200];
		in.read(s3, lungime3);
		this->masinaAchizitionata = s3;

		// citire suma
		in.read((char*)&this->suma, sizeof(this->suma));

		// citire metoda plata
		in.read((char*)&this->metodaPlata, sizeof(this->metodaPlata));

		//citire nrRate + rate ramase
		in.read((char*)&this->nrRateRamase, sizeof(this->nrRateRamase));
		delete[]  this->rateRamase;
		this->rateRamase = new float[this->nrRateRamase];
		for (int i = 0; i < this->nrRateRamase; i++) {
			in.read((char*)&this->rateRamase[i], sizeof(this->rateRamase[i]));

		}


	}

	// constructor fara parametri
	Client()
	{
		this->nume = "na";
		strcpy(this->prenume, "na");
		this->nrtel = "na";
		this->masinaAchizitionata = "na";
		this->metodaPlata = MetodaPlata::CASH;
		this->nrRateRamase = 0;
		this->rateRamase = NULL;
		this->suma = 0;
	}

	// constructor cu toti parametri
	Client(string numed, char* prenumed, string nrteld, string masinad, MetodaPlata metodad, float sumad, int nrrated, float* rateramased)
	{
		if (numed.length() > 3)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
		}
		if (strlen(prenumed) > 3)
		{
			strcpy(this->prenume, prenumed);
		}
		else
		{
			strcpy(this->prenume, "na");
		}

		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
		}
		if (masinad.length() >= 3)
		{
			this->masinaAchizitionata = masinad;
		}
		else
		{
			this->masinaAchizitionata = "na";

		}
		if (metodad >= 0 && metodad <= 2)
		{
			this->metodaPlata = metodad;

			if (nrrated > 0)
			{
				if (metodad == 0)
				{
					if (nrrated == 0 && rateramased == NULL)
					{
						this->nrRateRamase = 0;
						this->rateRamase = NULL;
					}
					else
					{
						cout << "\nMetoda plata este cash dar totusi exista rate?";
					}
				}
				else if (metodad == 1)
				{
					if (nrrated == 0)
					{
						cout << "\nPentru plata in rate trebuie sa existe minim 1 rata!";
					}
					else
					{
						if (rateramased == NULL)
						{
							cout << "\nSe asteptau mai multe rate dar nu a fost transmisa nici una!";
						}
						else
						{
							this->nrRateRamase = nrrated;
							this->rateRamase = new float[nrrated];
							for (int i = 0; i < nrrated; i++)
							{
								this->rateRamase[i] = rateramased[i];
							}
						}
					}
				}
				else
				{
					if (nrrated != 1)
					{
						cout << "\nPentru plata cu ordin de plata ar trebui sa existe o singura rata!";
					}
					else
					{
						if (nrrated == NULL)
						{
							cout << "\nNu s-a transmis nici o rata!";
						}
						else
						{
							this->nrRateRamase = 1;
							this->rateRamase[0] = rateramased[0];
						}
					}
				}
			}
			else
			{
				cout << "\nNumarul de rate nu poate fi negativ";
			}

		}
		else
		{
			cout << "\nMetoda de plata este invalida";
		}
		if (sumad > 0)
		{
			this->suma = sumad;
		}
		else
		{
			cout << "\nSuma introdusa este gresita";
		}
	}
	// constructor cu cativa parametri
	Client(string numed, char* prenumed, string nrteld, string masinad)
	{
		if (numed.length() > 3)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
		}
		if (strlen(prenumed) > 3)
		{
			strcpy(this->prenume, prenumed);
		}
		else
		{
			strcpy(this->prenume, "na");
		}

		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
		}
		if (masinad.length() >= 3)
		{
			this->masinaAchizitionata = masinad;
		}
		else
		{
			this->masinaAchizitionata = "na";

		}
	}
	// apel destructor
	~Client()
	{
		delete[] this->rateRamase;
	}

	// get si set
	string getNume()
	{
		return this->nume;
	}
	void setNume(string numed)
	{
		if (nume.length() >= 3)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
		}
	}
	string getPrenume()
	{
		return this->prenume;
	}
	void setPrenume(char* prenumed)
	{
		if (strlen(prenumed) >= 3)
		{
			strcpy(this->prenume, prenumed);
		}
		else
		{
			strcpy(this->prenume, "na");
		}
	}
	string getNrTel()
	{
		return this->nrtel;
	}
	void setNrTel(string nrteld)
	{
		if (nrtel.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
		}
	}
	string getMasinaAchizionata()
	{
		return this->masinaAchizitionata;
	}
	void setMasinaAchizitionata(string masinad)
	{
		if (masinaAchizitionata.length() >= 3)
		{
			this->masinaAchizitionata = masinad;
		}
		else
		{
			this->masinaAchizitionata = "na";

		}
	}
	MetodaPlata getMetodaplata()
	{
		return this->metodaPlata;
	}
	int getNrRateRamase()
	{
		return this->nrRateRamase;
	}
	float* getRateRamase()
	{

		return this->rateRamase;

	}
	void setRateRamase(int nrrated, float* rateramased)
	{
		if (nrrated != 0 && rateramased == NULL)
		{
			cout << "\nSe asteptau mai multe rate dar nu a fost transmisa nici una!";
		}
		else if (nrrated == 0 && rateramased != NULL)
		{
			cout << "\nS-au primit mai multe rate dar nu s-a primit nici una!";
		}
		else if (nrrated > 0 && rateramased != NULL)
		{
			int i;
			this->nrRateRamase = nrrated;
			delete[] this->rateRamase;
			this->rateRamase = new float[nrrated];
			for (i = 0; i < nrrated; i++)
			{
				this->rateRamase[i] = rateramased[i];
			}
		}

	}
	float getSuma()
	{
		return this->suma;
	}
	void setSuma(float sumad)
	{
		if (sumad > 0)
		{
			this->suma = sumad;
		}
		else
		{
			this->suma = 0;
		}
	}

	// constructor de copiere
	Client(const Client& sursa)
	{
		this->nume = sursa.nume;
		strcpy(this->prenume, sursa.prenume);
		this->nrtel = sursa.nrtel;
		this->masinaAchizitionata = sursa.masinaAchizitionata;
		this->metodaPlata = sursa.metodaPlata;
		this->suma = sursa.suma;
		this->nrRateRamase = sursa.nrRateRamase;
		this->rateRamase = new float[sursa.nrRateRamase];
		for (int i = 0; i < sursa.nrRateRamase; i++)
		{
			this->rateRamase[i] = sursa.rateRamase[i];
		}
	}

	// operator =
	Client& operator=(const Client& sursa)
	{
		if (this != &sursa)
		{
			delete[]this->rateRamase;

			this->nume = sursa.nume;
			strcpy(this->prenume, sursa.prenume);
			this->nrtel = sursa.nrtel;
			this->masinaAchizitionata = sursa.masinaAchizitionata;
			this->metodaPlata = sursa.metodaPlata;
			this->suma = sursa.suma;
			this->nrRateRamase = sursa.nrRateRamase;
			this->rateRamase = new float[sursa.nrRateRamase];
			for (int i = 0; i < sursa.nrRateRamase; i++)
			{
				this->rateRamase[i] = sursa.rateRamase[i];
			}
		}
		return *this;
	}

	// functie de afisare
	void afisare()
	{
		cout << "\n-------------------------------";
		cout << "\nNume client:" << this->nume;
		cout << "\nPrenume:" << this->prenume;
		cout << "\nNr de telefon: " << this->nrtel;
		cout << "\nMasina achizitionata:" << this->masinaAchizitionata;
		cout << "\nSuma de achitat:" << this->suma;
		cout << "\nMetoda de plata: ";
		if (metodaPlata == 0)
		{
			cout << "\nCash";
		}
		else if (metodaPlata == 1)
		{
			cout << "\nRate ";
		}
		else if (metodaPlata == 2)
		{
			cout << "\nOrdin de plata";
		}
		if (metodaPlata >= 1 && metodaPlata <= 2)
		{
			cout << "\nNumarul de rate ramase este:" << nrRateRamase;
		}
		int i;
		for (i = 0; i < nrRateRamase; i++)
		{
			cout << "\nRata " << i + 1 << "este: " << rateRamase[i];
		}
		cout << "\n-------------------------------";
	}

	virtual float sumaMarita()
	{
		this->suma = 0.15 * this->suma + this->suma;
		cout << "\nSuma marita pentru client este : " << this->suma;
		return 0;
	}
	// op <<
	friend ostream& operator<<(ostream& out, Client sursa)
	{
		out << "\n-------------------------------";
		out << "\nNume client:" << sursa.nume;
		out << "\nPrenume:" << sursa.prenume;
		cout << "\nNr de telefon: " << sursa.nrtel;
		out << "\nMasina achizitionata:" << sursa.masinaAchizitionata;
		out << "\nSuma de achitat:" << sursa.suma;
		out << "\nMetoda de plata: ";
		if (sursa.metodaPlata == 0)
		{
			out << "\nCash";
		}
		else if (sursa.metodaPlata == 1)
		{
			out << "\nRate ";
		}
		else if (sursa.metodaPlata == 2)
		{
			out << "\nOrdin de plata";
		}
		if (sursa.metodaPlata >= 1 && sursa.metodaPlata <= 2)
		{
			out << "\nNumarul de rate ramase este:" << sursa.nrRateRamase;
		}
		int i;
		for (i = 0; i < sursa.nrRateRamase; i++)
		{
			out << "\nRata " << i + 1 << "este: " << sursa.rateRamase[i];
		}
		out << "\n-------------------------------";
		return out;
	}

	friend ofstream& operator<<(ofstream& out, Client sursa)
	{

		out << sursa.nume << endl;
		out << sursa.prenume << endl;
		out << sursa.nrtel << endl;
		out << sursa.masinaAchizitionata << endl;
		out << sursa.suma << endl;
		//out << "\nMetoda de plata: ";
		if (sursa.metodaPlata == 0)
		{
			out << sursa.metodaPlata << endl;;
		}
		else if (sursa.metodaPlata == 1)
		{
			out << sursa.metodaPlata << endl;
		}
		else if (sursa.metodaPlata == 2)
		{
			out << sursa.metodaPlata << endl;
		}
		if (sursa.metodaPlata >= 1 && sursa.metodaPlata <= 2)
		{
			out << sursa.nrRateRamase << endl;
		}
		int i;
		for (i = 0; i < sursa.nrRateRamase; i++)
		{
			out << sursa.rateRamase[i] << endl;
		}
		return out;
	}

	// op >>
	friend istream& operator>>(istream& in, Client& sursa)
	{
		cout << "\nNume:";
		in >> sursa.nume;
		in.ignore();

		cout << "\nPrenume:";
		in >> sursa.prenume;

		cout << "\nNr de telefon:";
		in >> sursa.nrtel;

		cout << "\nMasina achizitionata :";
		in >> sursa.masinaAchizitionata;

		cout << "\nSuma de achitat:";
		in >> sursa.suma;
		cout << "\nMetoda de plata este:";
		int mp;
		in >> mp;
		if (mp >= 0 && mp < 1)
		{
			sursa.metodaPlata = (MetodaPlata)0;
		}
		else if (mp >= 1 && mp < 2)
		{
			sursa.metodaPlata = (MetodaPlata)1;
			cout << "\nNumar de rate ramase:";
			in >> sursa.nrRateRamase;

			delete[] sursa.rateRamase;
			sursa.rateRamase = new float[sursa.nrRateRamase];
			int i;
			for (i = 0; i < sursa.nrRateRamase; i++)
			{
				cout << "\nRata " << i + 1 << " este :";
				in >> sursa.rateRamase[i];
			}
		}
		if (mp > 1 && mp <= 2)
		{
			sursa.metodaPlata = (MetodaPlata)2;
		}

		return in;
	}

	friend ifstream& operator>>(ifstream& in, Client& sursa)
	{

		in >> sursa.nume;
		in.ignore();


		in >> sursa.prenume;


		in >> sursa.nrtel;


		in >> sursa.masinaAchizitionata;


		in >> sursa.suma;

		int mp;
		in >> mp;
		if (mp >= 0 && mp < 1)
		{
			sursa.metodaPlata = (MetodaPlata)0;
		}
		else if (mp >= 1 && mp < 2)
		{
			sursa.metodaPlata = (MetodaPlata)1;
		}
		if (mp > 1 && mp <= 2)
		{
			sursa.metodaPlata = (MetodaPlata)2;
		}

		in >> sursa.nrRateRamase;
		delete[] sursa.rateRamase;
		sursa.rateRamase = new float[sursa.nrRateRamase];
		int i;
		for (i = 0; i < sursa.nrRateRamase; i++)
		{

			in >> sursa.rateRamase[i];
		}
		return in;
	}

	// op +
	Client& operator+(int sumad)
	{
		if (sumad > 0)
		{
			this->suma += sumad;
		}
		else
		{
			cout << "\nSuma introdusa este negativa";
		}
		return *this;
	}

	// op +=
	Client& operator+=(int sumad)
	{
		return *this + sumad;
	}

	// op []
	float operator[](int i)
	{
		if (this->metodaPlata == 1)
		{
			return this->rateRamase[i - 1];
		}
		else if (this->metodaPlata == 2)
		{
			if (i != 1)
			{
				cout << "\nPentru ordinul de plata exista o singura rata";
			}
			else
			{
				return this->rateRamase[i - 1];
			}
		}
		else
		{
			cout << "\nPentru plata cash nu exista rate!";
		}
	}

	// op ++ postincrementare
	Client operator++()
	{
		this->suma += 100;
		return *this;
	}

	// op ++ peincrementare
	Client operator++(int)
	{
		Client copie(*this);
		this->suma += 100;
		return copie;
	}

	// op ==
	bool operator==(Client sursa)
	{
		bool gasit = true;
		if (this->nume != sursa.nume)
		{
			gasit = false;
		}
		if (strcmp(this->prenume, sursa.prenume) != 0)
		{
			gasit = false;
		}
		if (this->nrtel != sursa.nrtel)
		{
			gasit = false;
		}
		if (this->masinaAchizitionata != sursa.masinaAchizitionata)
		{
			gasit = false;
		}
		if (this->metodaPlata != sursa.metodaPlata)
		{
			gasit = false;
		}
		if (this->suma != sursa.suma)
		{
			gasit = false;
		}
		if (this->nrRateRamase != sursa.nrRateRamase)
		{
			gasit = false;
		}
		else
		{
			for (int i = 0; i < sursa.nrRateRamase; i++)
			{
				if (this->rateRamase != sursa.rateRamase)
				{
					gasit == false;
				}
			}
		}
		return gasit;
	}

	// op <
	bool operator <(Client sursa)
	{
		if (nrRateRamase < sursa.nrRateRamase)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// op !
	bool operator! ()
	{
		if (this->suma > 1000)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// functie ce ne ajuta sa citim in clasa derivata
	Client& getClient()
	{
		return*this;
	}

	void raportClient(const char* fisier)
	{
		ofstream fout;
		fout.open(fisier, ofstream::out);
		fout << "Clientul: " << this->getNume() << " " << this->getPrenume() << ", a cumparat masina: " << this->getMasinaAchizionata() << endl;
		fout << "Suma de: " << this->getSuma() << " a fost achitata prin: ";
		if (this->getMetodaplata() == 0)
		{
			fout << "Cash";
		}
		else if (this->getMetodaplata() == 1)
		{
			fout << "Rate ";
		}
		else if (this->getMetodaplata() == 2)
		{
			fout << "Ordin de plata";
		}
		if (this->getMetodaplata() >= 1 && this->getMetodaplata() <= 2)
		{
			for (int i = 0; i < this->getNrRateRamase(); i++)
			{
				fout << "\nRata " << i + 1 << " este in valoare de: " << this->getRateRamase()[i];
			}
		}


	}

	// op cast
	explicit operator float() {
		return this->suma;
	}

};

// clasa derivata: PersoanaJuridica

class PersoanaJuridica : public Client
{

private:
	int codCUI;
	char* numefirma;

public:

	// constr fara param
	PersoanaJuridica()
	{
		this->codCUI = 0;
		this->numefirma = new char[strlen("na") + 1];
		strcpy(this->numefirma, "na");
	}
	/*class Client
	{
	private:
		string nume;
		char prenume[50]{ "na" };
		string nrtel;
		string masinaAchizitionata;
		MetodaPlata metodaPlata;
		int nrRateRamase = 0;
		float* rateRamase = NULL;
		float suma = 0;*/

		// const cu toti param
	PersoanaJuridica(string numed, char* prenumed, string nrteld, string masinad, MetodaPlata metodad, float sumad, int nrrated, float* rateramased, int CUId, char* numefirmad) :Client(numed, prenumed, nrteld, masinad, metodad, sumad, nrrated, rateramased)
	{
		this->codCUI = CUId;

		if (strlen(numefirmad) > 4)
		{
			this->numefirma = new char[strlen(numefirmad) + 1];
			strcpy(this->numefirma, numefirmad);
		}
		else
		{
			this->numefirma = new char[strlen("na") + 1];
			strcpy(this->numefirma, "na");
		}
	}

	// destructor
	~PersoanaJuridica()
	{
		delete[] this->numefirma;
	}

	// constr de copiere
	PersoanaJuridica(const PersoanaJuridica& sursa) : Client((Client)sursa)
	{
		this->codCUI = sursa.codCUI;
		this->numefirma = new char[strlen(sursa.numefirma) + 1];
		strcpy(this->numefirma, sursa.numefirma);
	}

	// op =
	PersoanaJuridica& operator=(const PersoanaJuridica& sursa)
	{
		if (this != &sursa)
		{
			Client::operator=(sursa);
			delete[] this->numefirma;
			this->codCUI = sursa.codCUI;
			this->numefirma = new char[strlen(sursa.numefirma) + 1];
			strcpy(this->numefirma, sursa.numefirma);
		}
		return *this;
	}

	// supraincarcare op <<
	friend ostream& operator<<(ostream& out, PersoanaJuridica& sursa)
	{
		out << (Client)sursa << endl;
		out << "Codul CUI al firmei este: " << sursa.codCUI << endl;
		out << "Numele firmei este: " << sursa.numefirma << endl;
		return out;
	}

	//op >>
	friend istream& operator>>(istream& in, PersoanaJuridica& sursa)
	{
		in >> sursa.getClient();

		cout << "Codul CUI al firmei este: ";
		in >> sursa.codCUI;

		cout << "Numele firmei este: ";
		char buffer[200];
		in >> buffer;
		delete[] sursa.numefirma;
		sursa.numefirma = new char[strlen(buffer) + 1];
		strcpy(sursa.numefirma, buffer);

		return in;
	}
	// functia virtuala 
	float sumaMarita()
	{
		float sumanoua;
		sumanoua = 0.30 * this->getSuma() + this->getSuma();
		cout << "\nSuma marita pentru persoana juridica este: " << sumanoua;
		return 0;
	}
};

class Angajat
{
private:
	string nume;
	char* prenume = NULL;
	char adresa[100] = { "na" };
	string nrtel;
	float salariul = 0;
	int anVechime = 0;

public:

	void scriereBinar(ofstream& o)
	{
		// scriere nume
		int lungime = strlen(this->nume.c_str()) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->nume.c_str(), sizeof(char) * lungime);

		// scriere prenume
		lungime = strlen(this->prenume) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->prenume, sizeof(char) * lungime);

		// scriere adresa
		lungime = strlen(this->adresa) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write((char*)&this->adresa, lungime * sizeof(char));

		// scriere nrtel
		lungime = strlen(this->nrtel.c_str()) + 1;
		o.write((char*)&lungime, sizeof(int));
		o.write(this->nrtel.c_str(), sizeof(char) * lungime);

		// scriere salariul
		o.write((char*)&this->salariul, sizeof(this->salariul));

		// scriere an vechime
		o.write((char*)&this->anVechime, sizeof(this->anVechime));

	}

	void citireBinar(ifstream& in)
	{
		// citire nume
		int lungime;
		in.read((char*)&lungime, sizeof(int));
		char s1[200];
		in.read(s1, lungime);
		this->nume = s1;

		// citire prenume
		lungime;
		in.read((char*)&lungime, sizeof(int));
		char s[2300];
		in.read(s, lungime);
		this->setPrenume(s);

		//citire adresa
		lungime;
		in.read((char*)&lungime, sizeof(int));
		char s3[2300];
		in.read(s3, lungime);
		this->setAdresa(s3);

		//citire nrtel
		in.read((char*)&lungime, sizeof(int));
		char s2[200];
		in.read(s2, lungime);
		this->nrtel = s2;

		// citire salariul
		in.read((char*)&this->salariul, sizeof(this->salariul));

		// citire an vechime
		in.read((char*)&this->anVechime, sizeof(this->anVechime));

	}

	// constructor fara parametri
	Angajat()
	{
		this->nume = "na";;
		this->prenume = new char[strlen("na") + 1];
		strcpy(this->prenume, "na");
		strcpy(this->adresa, "na");
		this->nrtel = "na";
		this->salariul = 0;
		this->anVechime = 0;
	}

	// constructor cu toti parametri
	Angajat(string numed, const  char* prenumed, char* adresad, string nrteld, float salariuld, int anvechimed)
	{
		if (numed.length() >= 3)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
		}
		if (strlen(prenumed) >= 3)
		{
			this->prenume = new char[strlen(prenumed) + 1];
			strcpy(this->prenume, prenumed);
		}
		else
		{
			this->prenume = new char[strlen("na") + 1];
			strcpy(this->prenume, "na");
		}
		if (strlen(adresad) > 5)
		{
			strcpy(this->adresa, adresad);
		}
		else
		{
			strcpy(this->adresa, "na");
		}
		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
		}
		if (salariuld > 1000)
		{
			this->salariul = salariuld;
		}
		else
		{
			this->salariul = 0;
		}
		if (anvechimed >= 1)
		{
			this->anVechime = anvechimed;
		}
		else
		{
			this->anVechime = 0;
		}

	}

	// constructor cu cativa parametri
	Angajat(string numed, const char* prenumed, char* adresad, string nrteld)
	{
		if (numed.length() >= 3)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
		}
		if (strlen(prenumed) >= 3)
		{
			this->prenume = new char[strlen(prenumed) + 1];
			strcpy(this->prenume, prenumed);
		}
		else
		{
			this->prenume = new char[strlen("na") + 1];
			strcpy(this->prenume, "na");

		}
		if (strlen(adresad) > 5)
		{
			strcpy(this->adresa, adresad);
		}
		else
		{
			strcpy(this->adresa, "na");
		}
		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
		}
	}

	// apel destructor
	~Angajat()
	{
		delete[] this->prenume;
	}

	// get si set 
	string getNume()
	{
		return this->nume;
	}
	void setNume(string numed)
	{
		if (numed.length() >= 3)
		{
			this->nume = numed;
		}
		else
		{
			this->nume = "na";
		}
	}
	char* getPrenume()
	{
		return this->prenume;
	}
	void setPrenume(const char* prenumed)
	{
		if (strlen(prenumed) >= 3)
		{
			delete[]prenume;
			this->prenume = new char[strlen(prenumed) + 1];
			strcpy(this->prenume, prenumed);
		}

	}
	char* getAdresa()
	{
		return this->adresa;
	}
	void setAdresa(char* adresad)
	{
		if (strlen(adresad) > 5)
		{
			strcpy(this->adresa, adresad);
		}
		else
		{
			strcpy(this->adresa, "na");
		}
	}
	string getNrTelefon()
	{
		return this->nrtel;
	}
	void setNrTelefon(string nrteld)
	{
		if (nrteld.length() == 10)
		{
			this->nrtel = nrteld;
		}
		else
		{
			this->nrtel = "na";
		}
	}
	float getSalariul()
	{
		return this->salariul;
	}
	void setSalariul(float salariuld)
	{
		if (salariuld > 1000)
		{
			this->salariul = salariuld;
		}
		else
		{
			this->salariul = 0;
		}
	}
	int getAnVechime()
	{
		return this->anVechime;
	}
	void setAnVechime(int anvechimed)
	{
		if (anvechimed >= 1)
		{
			this->anVechime = anvechimed;
		}
		else
		{
			this->anVechime = 0;
		}
	}

	// constructor de copiere
	Angajat(const Angajat& sursa)
	{
		this->nume = sursa.nume;
		this->prenume = new char[strlen(sursa.prenume) + 1];
		strcpy(this->prenume, sursa.prenume);
		strcpy(this->adresa, sursa.adresa);
		this->nrtel = sursa.nrtel;
		this->salariul = sursa.salariul;
		this->anVechime = sursa.anVechime;

	}

	// op =
	Angajat& operator=(const Angajat& sursa)
	{
		if (this != &sursa)
		{
			delete[]this->prenume;;
			this->nume = sursa.nume;
			this->prenume = new char[strlen(sursa.prenume) + 1];
			strcpy(this->prenume, sursa.prenume);
			strcpy(this->adresa, sursa.adresa);
			this->nrtel = sursa.nrtel;
			this->salariul = sursa.salariul;
			this->anVechime = sursa.anVechime;
		}
		return *this;
	}

	// functie de afisare
	virtual void afisare()
	{
		cout << "\n--------------------";
		cout << "\nNumele este:" << nume;
		cout << "\nPrenumele este:" << prenume;
		cout << "\nAdresa este:" << adresa;
		cout << "\nNumarul de telefon este:" << nrtel;
		cout << "\nSalariul este:" << salariul;
		cout << "\nAn/ani vechime :" << anVechime;
		cout << "\n--------------------";
	}

	virtual void mariresalariu()
	{
		if (this->anVechime > 2)
		{
			this->salariul = 0.25 * this->salariul + this->salariul;
		}
		else
		{
			this->salariul = 0.1 * this->salariul + this->salariul;
		}
		cout << " Salariul cu noua marire pentru angajat este: " << this->salariul << endl;
	}
	// op <<
	friend ostream& operator<<(ostream& out, Angajat sursa)
	{
		out << "\n--------------------";
		out << "\nNumele este:" << sursa.nume;
		out << "\nPrenumele este:" << sursa.prenume;
		out << "\nAdresa este:" << sursa.adresa;
		out << "\nNumarul de telefon este:" << sursa.nrtel;
		out << "\nSalariul este:" << sursa.salariul;
		out << "\nAn/ani vechime :" << sursa.anVechime;
		out << "\n--------------------";
		return out;
	}

	friend ofstream& operator<<(ofstream& out, Angajat sursa)
	{

		out << sursa.nume << endl;
		out << sursa.prenume << endl;
		out << sursa.adresa << endl;
		out << sursa.nrtel << endl;
		out << sursa.salariul << endl;
		out << sursa.anVechime << endl;
		return out;
	}

	// op >>
	friend istream& operator >>(istream& in, Angajat& sursa)
	{

		cout << "\nNumele:";
		in >> sursa.nume;
		in.ignore();
		cout << "\nPrenumele este:";
		char buffer[200];
		in.getline(buffer, 200);
		delete[] sursa.prenume;
		sursa.prenume = new char[strlen(buffer) + 1];
		strcpy(sursa.prenume, buffer);

		cout << "\nAdresa: ";
		in.getline(buffer, 200);
		strcpy(sursa.adresa, buffer);
		cout << "\nNumar de telefon:";
		in >> sursa.nrtel;
		cout << "\nSalariul:";
		in >> sursa.salariul;
		cout << "\nAn/ani vechime:";
		in >> sursa.anVechime;
		return in;

	}

	friend ifstream& operator >>(ifstream& in, Angajat& sursa)
	{


		in >> sursa.nume;
		in.ignore();

		char buffer[200];
		in.getline(buffer, 200);
		delete[] sursa.prenume;
		sursa.prenume = new char[strlen(buffer) + 1];
		strcpy(sursa.prenume, buffer);

		in.getline(buffer, 200);
		strcpy(sursa.adresa, buffer);
		in >> sursa.nrtel;

		in >> sursa.salariul;

		in >> sursa.anVechime;
		return in;

	}

	// op + 
	Angajat& operator+(float salariuld)
	{
		if (salariuld >= 50)
		{
			this->salariul += salariuld;
		}
		else
		{
			cout << "\nSuma introdusa este gresita";
		}
		return *this;
	}

	// op +=
	Angajat& operator+=(float salariuld)
	{
		return *this + salariuld;
	}

	// op ++ postincrementare
	Angajat operator++()
	{
		this->salariul += 100;
		return *this;
	}

	// op ++ preincrementare
	Angajat operator++(int)
	{
		Angajat copie(*this);
		this->salariul += 100;
		return copie;
	}

	// op == 
	bool operator==(Angajat sursa)
	{
		bool gasit = true;
		if (this->nume != sursa.nume &&
			strcmp(this->prenume, sursa.prenume) != 0 &&
			strcmp(this->adresa, sursa.adresa) != 0 &&
			this->nrtel != sursa.nrtel &&
			this->salariul != sursa.salariul &&
			this->anVechime != sursa.anVechime)
		{
			return gasit = false;
		}
		return gasit;
	}

	// op >
	bool operator >(Angajat sursa)
	{
		if (salariul > sursa.salariul)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// op !
	bool operator !()
	{
		if (this->anVechime >= 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// op cast
	explicit operator int()
	{
		return this->anVechime;
	}
	// ne ajuta la citire in clasa derivata
	Angajat& getAngajat()
	{
		return*this;
	}

};

class Secretara : public Angajat
{
private:
	int nrOre;
	int nrzileConcediu;

public:

	// constr fara param
	Secretara()
	{
		this->nrOre = 0;
		this->nrzileConcediu = 0;

	}

	// constr cu toti param
	Secretara(string numed, const  char* prenumed, char* adresad, string nrteld, float salariuld, int anvechimed, int nrored, int nrzilecond) :Angajat(numed, prenumed, adresad, nrteld, salariuld, anvechimed)
	{
		if (nrored > 20)
		{
			this->nrOre = nrored;
		}
		else
		{
			this->nrOre = 0;
		}

		if (nrzilecond > 30)
		{
			this->nrzileConcediu = nrzilecond;
		}
		else
		{
			this->nrzileConcediu = 0;
		}

	}

	// constr de copiere
	Secretara(const Secretara& sursa) : Angajat((Angajat)sursa)
	{
		this->nrOre = sursa.nrOre;
		this->nrzileConcediu = sursa.nrzileConcediu;
	}

	// op=
	Secretara& operator=(const Secretara& sursa)
	{
		if (this != &sursa)
		{
			Angajat::operator=(sursa);
			this->nrOre = sursa.nrOre;
			this->nrzileConcediu = sursa.nrzileConcediu;
		}
		return *this;
	}

	// functia virtuala 1
	void mariresalariu()
	{
		float salariulnou = 0;
		if (this->nrOre > 30)
		{
			salariulnou = 0.32 * this->getSalariul() + this->getSalariul();
		}
		else
		{
			salariulnou = 0.1 * this->getSalariul() + this->getSalariul();
		}
		cout << "Salariul marit pentru secretara  este:" << salariulnou << endl;

	}

	// functia virtuala 2
	void afisare()
	{
		cout << "\n--------------------";
		cout << "\nNumele este:" << this->getNume();
		cout << "\nPrenumele este:" << this->getPrenume();
		cout << "\nAdresa este:" << this->getAdresa();
		cout << "\nNumarul de telefon este:" << this->getNrTelefon();
		cout << "\nSalariul este:" << this->getSalariul();
		cout << "\nAn/ani vechime :" << this->getAnVechime();
		cout << "\nNr de ore lucrate:" << this->nrOre;
		cout << "\nNr de zile de concediu: " << this->nrzileConcediu;
		cout << "\n--------------------";
	}
	// op <<
	friend ostream& operator<<(ostream& out, Secretara& sursa)
	{
		out << Angajat(sursa) << endl;
		out << "Nr de ore lucrate este: " << sursa.nrOre << endl;
		out << "Nr de zile de concediu: " << sursa.nrzileConcediu << endl;
		return out;
	}

	// op >>
	friend istream& operator>>(istream& in, Secretara& sursa)
	{
		in >> sursa.getAngajat();

		cout << "Nr de ore lucrate este: ";
		in >> sursa.nrOre;
		cout << " Nr de zile de concediu este: ";
		in >> sursa.nrzileConcediu;
		return in;
	}
};

float Incasare::tva = 19;

class OperareFisier {

public:

	void scriereBinar(ofstream& fout, Dealer sursa) {

		sursa.scriereBinar(fout);

	}
	void citireBinar(ifstream& fin, Dealer& sursa) {

		sursa.citireBinar(fin);
	}

	void scriereBinar(ofstream& fout, Masina sursa)
	{
		sursa.scriereBinar(fout);
	}

	void citireBinar(ifstream& fin, Masina& sursa)
	{
		sursa.citireBinar(fin);
	}

	void scriereBinar(ofstream& fout, Incasare sursa)
	{
		sursa.scriereBinar(fout);
	}

	void citireBinar(ifstream& fin, Incasare& sursa)
	{
		sursa.citireBinar(fin);
	}

	void scriereBinar(ofstream& fout, Client sursa)
	{
		sursa.scriereBinar(fout);
	}

	void citireBinar(ifstream& fin, Client& sursa)
	{
		sursa.citireBinar(fin);
	}

	void scriereBinar(ofstream& fout, Angajat sursa)
	{
		sursa.scriereBinar(fout);
	}

	void citireBinar(ifstream& fin, Angajat& sursa)
	{
		sursa.citireBinar(fin);
	}
};

class Meniu {
public:
	static void afisareMeniuPrincipal() {
		cout << "\n1)Afiseaza dealer/dealerii" << endl;
		cout << "2)Genereaza raport dealer" << endl;
		cout << "3)Setam noile masini pentru dealer" << endl;
		cout << "4)Citire si scriere fisier binar" << endl;
		cout << "5)Citire si scriere fisier text" << endl;
		cout << "6)Adaugare valoare la suma de achitat de catre client" << endl;
		cout << "7)Operator == pentru angajat" << endl;
		cout << "8)Operator de negatie pentru angajat" << endl;
		cout << "9)Setam noile revizii pentru masina" << endl;
		cout << "10)Setam noii clienti de la care s a incasat" << endl;
		cout << "11) Verificare functii faza 1 clasa Dealer " << endl;
		cout << "12) Verificare functii faza 1 clasa Masina " << endl;
		cout << "13) Verificare functii faza 1 clasa Incasare  " << endl;
		cout << "14) Verificare functii faza 1 clasa Client " << endl;
		cout << "15) Verificare functii faza 1 clasa Angajat " << endl;

		cout << "0)Iesire" << endl;
		cout << "Alege optiunea:";
	}
};
int main()
{

	bool startMeniuActivat = true;
	while (startMeniuActivat)
	{
		int optiune;
		Meniu::afisareMeniuPrincipal();
		cin >> optiune;
		switch (optiune) {
		case 0: {
			startMeniuActivat = false;
			system("cls");
			cout << "Aplicatia a fost inchisa" << endl;
			break;
		}
		case 1: {
			system("cls");
			string masini[] = { "AUDI","BMW","Mercedes" };
			char adresa1[] = "Strada Trandafir";
			Dealer d1("Mobile.de", adresa1, "0746260281", 3, masini);
			cout << d1;
			char adresa2[] = "Bd Dorobanti";
			Dealer d2("Autovit", adresa2, "0746263281");
			cout << d2;
			cout << "\nDealerii au fost afisati" << endl;
			break;
		}
		case 2: {
			system("cls");
			string masini[] = { "AUDI","BMW","Mercedes" };
			char adresa1[] = "Strada Trandafir";
			Dealer d1("Mobile.de", adresa1, "0746260281", 3, masini);
			d1.raportDealer("raportdealer.txt");
			cout << "Raportul a fost generat in folder";
			break;
		}
		case 3: {
			system("cls");
			string masini[] = { "AUDI","BMW","Mercedes" };
			char adresa1[] = "Strada Trandafir";
			Dealer d1("Mobile.de", adresa1, "0746260281", 3, masini);
			string masini2[] = { "Kia","Dacia","Mazda" };
			d1.setMasiniStoc(3, masini2);
			for (int i = 0; i < d1.getNrMasini(); i++)
			{
				cout << d1.getMasiniStoc()[i] << " ";
			}
			cout << "\nAm setat si afisat noile masini din stoc ale dealer ului" << endl;
			break;
		}
		case 4: {
			system("cls");

			OperareFisier opfisier;
			ofstream fout5;
			char luna1[] = "Aprilie";
			string clienti1[] = { "Andrei","Maria","Alin" };
			Incasare i2(luna1, 2021, 1287.5, 3, clienti1);
			fout5.open("incasare1.bin", ofstream::binary);
			if (fout5.is_open()) {
				opfisier.scriereBinar(fout5, i2);
				fout5.close();
			}

			Incasare i4;
			ifstream fin5;
			fin5.open("incasare1.bin", ifstream::binary);
			if (fin5.is_open()) {
				opfisier.citireBinar(fin5, i4);
				fin5.close();
			}
			cout << i2;
			cout << i4;
			cout << "\nDatele obiectului i2 au fost salvate in fisier binar;";
			cout << "\nObiectul i4 a fost creat pe baza citirii de informatii din fisierul binar;" << endl;
			break;
		}
		case 5: {
			system("cls");
			char prenume1[] = "Pavel";
			float rateramase1[] = { 1300,1320,1390 };
			Client c1("Marinescu", prenume1, "0746260281", "Audi", RATE, 4010, 3, rateramase1);
			ofstream fout8;
			fout8.open("client2.txt", ofstream::out);
			if (fout8.is_open()) {
				fout8 << c1;
				fout8.close();
			}


			Client c6;

			ifstream fin8;
			fin8.open("client2.txt", ifstream::in);
			if (fin8.is_open()) {
				fin8 >> c6;
				fin8.close();
			}
			cout << c1;
			cout << c6;
			cout << "\nDatele obiectului c1 au fost salvate in fisier binar;";
			cout << "\nS-au scris datele din c1 in fisierul txt,iar pe baza fisierului s a creat obiectul c6." << endl;
			break;
		}
		case 6:
		{
			system("cls");
			char prenume1[] = "Pavel";
			float rateramase1[] = { 1300,1320,1390 };
			Client c1("Marinescu", prenume1, "0746260281", "Audi", RATE, 4010, 3, rateramase1);
			cout << c1 + (100) << endl;
			cout << "S-a adaugat valoarea 100 la suma de plata" << endl;
			break;
		}
		case 7:
		{

			system("cls");
			Angajat a3;
			Angajat a;
			if (a3 == a)
			{
				cout << "\nSunt aceleasi obiecte";
			}
			else
			{
				cout << "\nSunt obiecte diferite";
			}
			cout << endl;
			break;
		}
		case 8:
		{
			system("cls");
			char adresaa[] = { "bd unirii" };
			char prenumee[] = { "Anghel  Damian" };
			Angajat a1("Iacob", prenumee, adresaa, "0739850581", 3000, 2);
			if (!a1)
			{
				cout << "\nSalariul este mai mare ca 2000";
			}
			else
			{
				cout << "\nSalariul este mai mic ca 2000";
			}
			cout << endl;
			break;
		}
		case 9:
		{
			system("cls");
			char model1[] = { "a4" };
			int revizii1[] = { 25000,80000,138000 };
			Masina m1(723490413, "audi", model1, 2003, 176000, 3, revizii1);
			int revizii2[] = { 34500, 96320, 134900,190280 };
			m1.setReviziikm(4, revizii2);
			cout << m1;
			break;
		}
		case 10:
		{
			system("cls");
			string clienti2[] = { "Marius","Marian" };
			char luna[] = { "Februarie" };
			string clienti[] = { "Ioan Alexandru", "Popescu Daniela" };
			Incasare i1(luna, 2019, 80000, 2, clienti);
			i1.setClienti(2, clienti2);
			cout << i1 << endl;
			break;
		}

		case 11:
		{
			system("cls");
			//constructor fara parametri si op <<
			Dealer d;
			cout << d;
			// constructor cu toti parametri;
			string masini[] = { "AUDI","BMW","Mercedes" };
			char adresa1[] = "Strada Trandafir";
			Dealer d1("Mobile.de", adresa1, "0746260281", 3, masini);
			cout << d1;
			// constructor cu cativa parametri
			char adresa2[] = "Bd Dorobanti";
			Dealer d2("Autovit", adresa2, "0746263281");
			cout << d2;
			// raport dealer
			d1.raportDealer("raportdealer.txt");
			// constructor de copiere
			Dealer d5(d1);
			cout << d5;

			OperareFisier opfisier;
			ofstream fout;
			fout.open("dealer1.bin", ofstream::binary);
			if (fout.is_open())
			{
				opfisier.scriereBinar(fout, d1);
				fout.close();
			}
			Dealer d6;
			ifstream fin;
			fin.open("dealer1.bin", ifstream::binary);
			if (fin.is_open()) {
				opfisier.citireBinar(fin, d6);
				fin.close();
			}

			//scriere si citire fisier txt
			ofstream fout2;
			fout2.open("dealer2.txt", ofstream::out);
			if (fout2.is_open()) {
				fout2 << d1;
				fout2.close();
			}

			Dealer d7;
			ifstream fin2;
			fin2.open("dealer2.txt", ifstream::in);
			if (fin2.is_open()) {
				fin2 >> d7;
				fin2.close();
			}
			// functia get
			cout << d1.getNume() << endl;
			cout << d1.getAdresa() << endl;
			cout << d1.getNrTel() << endl;
			cout << d1.getNrMasini() << endl;
			for (int i = 0; i < d1.getNrMasini(); i++)
			{
				cout << d1.getMasiniStoc()[i] << " ";
			}

			// functia set
			d1.setNume("Autovit");
			cout << d1.getNume() << endl;

			char adresa3[] = "bd Mihai Bravu";
			d1.setAdresa(adresa3);
			cout << d1.getAdresa() << endl;

			d1.setNrTel("0739206346");
			cout << d1.getNrTel() << endl;

			string masini2[] = { "Kia","Dacia","Mazda" };
			d1.setMasiniStoc(3, masini2);
			for (int i = 0; i < d1.getNrMasini(); i++)
			{
				cout << d1.getMasiniStoc()[i] << " ";
			}
			// functia afisare
			d.afisare();
			//op =
			d5 = d;
			cout << d5;
			// op >>
			cin >> d5;
			// op +
			cout << d1 + 1;
			//op ++
			cout << (++d1);
			//op +=
			cout << (d1 += (2));
			//op==
			if (d1 == d5)
			{
				cout << "\nSunt aceleasi obiecte";
			}
			else
			{
				cout << "\nSunt obiecte diferite";
			}
			cout << endl;
			// op <
			if (d1 < d5)
			{
				cout << "\nNumarul de masini este mai mic fata de d5";
			}
			else
			{
				cout << "\nNumarul de masini este mai nare fata de d5";
			}
			cout << endl;
			//op !
			if (!d1)
			{
				cout << "\nNr de masini nu este mai mare ca 0";
			}
			else
			{
				cout << "\nNr de masini este mai mare ca 0";
			}
			cout << endl;
			//op cast
			int nrMasinid1;
			nrMasinid1 = (int)d1;
			// op []
			cout << d1[2] << endl;
			cout << "\n----------------------";
			cout << endl;
			break;
		}

		case 12:
		{
			system("cls");
			//constructor fara param si op<<;
			Masina m;
			cout << m;
			//constructor cu toti parametri
			char model1[] = { "a4" };
			int revizii1[] = { 25000,80000,138000 };
			Masina m1(723490413, "audi", model1, 2003, 176000, 3, revizii1);
			cout << m1;
			//constructor cu cativa parametri
			char model2[] = { "a6" };
			Masina m2(12, "audi", model2, 2009, 256000);
			cout << m2 << endl;
			cout << m1[2] << endl;

			// raport masina
			m1.raportMasina("raport Masina.txt");

			//scriere si citire in binar
			OperareFisier opfisier;
			ofstream fout3;
			fout3.open("masina1.bin", ofstream::binary);
			if (fout3.is_open()) {
				opfisier.scriereBinar(fout3, m1);
				fout3.close();
			}

			Masina m4;

			ifstream fin3;
			fin3.open("masina1.bin", ifstream::binary);
			if (fin3.is_open()) {
				opfisier.citireBinar(fin3, m4);
				fin3.close();
			}

			// scriere si citire fisier txt
			ofstream fout4;
			fout4.open("masina2.txt", ofstream::out);
			if (fout4.is_open()) {
				fout4 << m1;
				fout4.close();
			}

			Masina m5;
			ifstream fin4;
			fin4.open("masina2.txt", ifstream::in);
			if (fin4.is_open()) {
				fin4 >> m5;
				fin4.close();
			}
			//get
			cout << m1.getModel() << endl;
			cout << m1.getMarca() << endl;
			cout << m1.getAnFabricatie() << endl;
			cout << m1.getKm() << endl;
			cout << m1.getNrRevizii() << endl;
			for (int i = 0; i < m1.getNrRevizii(); i++)
			{
				cout << m1.getReviziikm()[i] << " ";
			}
			// set
			m1.setMarca("bmw");
			char model3[] = "seria 3";
			m1.setModel(model3);
			m1.setAnFabricatie(2012);
			m1.setKm(196400);
			int revizii2[] = { 34500, 96320, 134900,190280 };
			m1.setReviziikm(4, revizii2);
			cout << m1 << endl;
			// constructor de copiere;
			Masina m3(m);
			cout << m3 << endl;
			// op =
			m2 = m;
			cout << m3 << endl;
			// functie afisare
			m.afisare();
			cout << endl;
			// op >>
			cin >> m1;
			//op+
			cout << m1 + (100);
			//op ++ posincrementare;
			cout << m1++ << endl;
			// op ++ preincrementare;
			cout << ++m1 << endl;
			// op ==
			if (m3 == m)
			{
				cout << "\nSunt aceleasi obiecte";
			}
			else
			{
				cout << "\nSunt obiecte diferite";
			}
			cout << endl;
			//op !
			if (!m)
			{
				cout << "\nNr de revizii este mai mic decat 0";
			}
			else
			{
				cout << "\nNr de revizii este mai mare decat 0";
			}
			cout << endl;
			//op <
			if (m1 < m2)
			{
				cout << "\nNr de km este mai mic fata de m2";
			}
			else
			{
				cout << "\nNr de km este mai mare fata de m2";
			}
			cout << endl;
			//op [];
			cout << "Valoarea de pe pozitia 1 este:" << m1[1] << endl;
			//op cast
			int nrKMm1;
			nrKMm1 = (int)m1;
			cout << "\n--------------------";
			break;
		}
		case 13:
		{
			system("cls");
			// constructor fara param si op <<
			Incasare i;
			cout << i;
			// constructor cu toti parametri;
			char luna[] = { "Februarie" };
			string clienti[] = { "Ioan Alexandru", "Popescu Daniela" };
			Incasare i1(luna, 2019, 80000, 2, clienti);
			cout << i1;
			// constructor cu cativa param
			char luna1[] = "Aprilie";
			string clienti1[] = { "Andrei","Maria","Alin" };
			Incasare i2(luna1, 2021, 1287.5, 3, clienti1);
			cout << i2 << endl;

			//raport incasare
			i1.raportIncasare("raportIncasare.txt");

			//scriere si citire fisier binar
			OperareFisier opfisier;
			ofstream fout5;
			fout5.open("incasare1.bin", ofstream::binary);
			if (fout5.is_open()) {
				opfisier.scriereBinar(fout5, i2);
				fout5.close();
			}

			Incasare i4;
			ifstream fin5;
			fin5.open("incasare1.bin", ifstream::binary);
			if (fin5.is_open()) {
				opfisier.citireBinar(fin5, i4);
				fin5.close();
			}
			//cout<<i4;ca sa verificam daca facem citirea bine;

		   // scriere si citire fisier txt
			ofstream fout6;
			fout6.open("incasare2.txt", ofstream::out);
			if (fout6.is_open()) {
				fout6 << i1;
				fout6.close();
			}

			Incasare i5;
			ifstream fin6;
			fin6.open("incasare2.txt", ifstream::in);
			if (fin6.is_open()) {
				fin6 >> i5;
				fin6.close();
			}


			// functia de afisare
			i.afisare();
			//get
			cout << i1.getLuna() << endl;
			cout << i1.getAn() << endl;
			cout << i1.getValoareFaraTVA() << endl;
			cout << i1.getNrClienti() << endl;
			cout << i1.getTva() << endl;
			for (int i = 0; i < i2.getNrClienti(); i++)
			{
				cout << i2.getClienti()[i] << " ";
			}
			cout << endl;
			//set
			char luna2[] = "Iunie";
			i1.setLuna(luna2);
			i1.setAn(2021);
			i1.setValoareFaraTVA(9230);
			string clienti2[] = { "Marius","Marian" };
			i1.setClienti(2, clienti2);
			cout << i1 << endl;
			// constructor de copiere
			Incasare i3(i1);
			cout << i3 << endl;
			//op =;
			i3 = i;
			cout << i3 << endl;
			//op >>
			cin >> i3;
			cout << endl;
			//op-
			cout << i1 - (100) << endl;
			//op -=
			cout << (i1 -= (100)) << endl;
			//op++ preincrementare
			cout << ++i1 << endl;
			//op++ postincrementare;
			cout << i1++;
			//op [];
			cout << i1[2] << endl;
			//op==
			if (i3 == i)
			{
				cout << "\nSunt acelasi obiecte";
			}
			else
			{
				cout << "\nSunt obiecte diferite";
			}
			//op >
			if (i3 > i1)
			{
				cout << "\nValoarea din i3 este mai mare";
			}
			else
			{
				cout << "\nValoarea din i3 este mai mica";
			}
			cout << endl;
			//op!
			if (!i)
			{
				cout << "\nAnul este mai mic ca 2019";
			}
			else
			{
				cout << "\nAnul este mai mare ca 2019";
			}
			cout << endl;
			//op cast
			int nrclientIi1;
			nrclientIi1 = (int)i1;
			break;
		}
		case 14:
		{
			system("cls");
			// constructor fara param si op <<
			Client c;
			cout << c;
			// constructor cu toti parametri
			char prenume1[] = "Pavel";
			float rateramase1[] = { 1300,1320,1390 };
			Client c1("Marinescu", prenume1, "0746260281", "Audi", RATE, 4010, 3, rateramase1);
			//constructor cu cativa param
			char prenume2[] = "Samuel";
			Client c2("Zimbas", prenume2, "0745299273", "BMW");
			cout << c2;

			// raport Client
			c1.raportClient("raport Client.txt");

			//scriere si citire in binar
			OperareFisier opfisier;
			ofstream fout7;
			fout7.open("client.bin", ofstream::binary);
			if (fout7.is_open())
			{
				opfisier.scriereBinar(fout7, c1);
				fout7.close();
			}

			Client c5;

			ifstream fin7;
			fin7.open("client.bin", ifstream::binary);
			if (fin7.is_open()) {
				opfisier.citireBinar(fin7, c5);
				fin7.close();
			}

			// scriere si citire fisier txt
			ofstream fout8;
			fout8.open("client2.txt", ofstream::out);
			if (fout8.is_open()) {
				fout8 << c1;
				fout8.close();
			}


			Client c6;

			ifstream fin8;
			fin8.open("client2.txt", ifstream::in);
			if (fin8.is_open()) {
				fin8 >> c6;
				fin8.close();
			}


			//functia de afisare
			c.afisare();
			// get
			cout << c1.getNume() << endl;
			cout << c1.getPrenume() << endl;
			cout << c1.getNrTel() << endl;
			cout << c1.getMasinaAchizionata() << endl;
			cout << c1.getMetodaplata() << endl;
			cout << c1.getSuma() << endl;
			cout << c1.getNrRateRamase() << endl;
			cout << c1.getRateRamase() << endl;
			//set
			c1.setNume("Antohe");
			char prenume3[] = "Alex";
			c1.setPrenume(prenume3);
			c1.setNrTel("0782539123");
			c1.setMasinaAchizitionata("Skoda");
			c1.setSuma(5300);
			float rateramase2[] = { 2000,3300 };
			c1.setRateRamase(2, rateramase2);
			cout << c1;
			// contructor de copiere
			Client c3(c1);
			cout << c3 << endl;
			// op=
			c3 = c2;
			cout << c3 << endl;
			// op>>
			cin >> c3;
			cout << endl;
			//op+
			cout << c1 + (100) << endl;
			//op +=
			cout << (c1 += (1000)) << endl;
			//op[]
			cout << c1[2];
			// op ++ preincrementare;
			cout << ++c1;
			//op ++ posincrementare
			cout << c1++;
			// op ==
			if (c3 == c2)
			{
				cout << "\nObiectele sunt egale";
			}
			else
			{
				cout << "\nObiectele sunt diferite";
			}
			cout << endl;
			//op !
			if (!c2)
			{
				cout << "\n Suma este mai mica ca 1000";
			}
			else
			{
				cout << "\nSuma este mai mare ca 1000";
			}
			cout << endl;
			// op<
			if (c3 < c1)
			{
				cout << "\nC3 are mai putine rate fata de c1";
			}
			else
			{
				cout << "\n C3 are mai multe rate fata de c1";
			}
			cout << endl;
			//op cast
			float sumac1;
			sumac1 = (float)c1;
			break;
		}

		case 15:
		{
			system("cls");
			// contructor fara parametri si op <<
			Angajat a;
			cout << a << endl;
			// constructor cu toti parametri
			char adresaa[] = { "bd unirii" };
			char prenumee[] = { "Anghel  Damian" };
			Angajat a1("Iacob", prenumee, adresaa, "0739850581", 3250, 2);
			cout << a1;
			// constructor cu cativa parametri
			char adresaa1[] = " bd Nicolae Grigorescu";
			char prenumee1[] = "Aurelian";
			Angajat a2("Nicolai", prenumee1, adresaa1, "0738268109");
			cout << a2 << endl;

			OperareFisier opfisier1;
			ofstream foutbin1;
			foutbin1.open("angajat1.bin", ofstream::binary);
			if (foutbin1.is_open())
			{
				opfisier1.scriereBinar(foutbin1, a1);
				foutbin1.close();
			}

			Angajat a4;
			ifstream finbin1;
			finbin1.open("angajat1.bin", ifstream::binary);
			if (finbin1.is_open()) {
				opfisier1.citireBinar(finbin1, a4);
				finbin1.close();
			}
			//scriere si citire fisier txt
			ofstream fout10;
			fout10.open("angajata1.txt", ofstream::out);
			if (fout10.is_open()) {
				fout10 << a1;
				fout10.close();
			}
			Angajat a5;
			ifstream finbin11;
			finbin11.open("angajata1.txt", ifstream::in);
			if (finbin11.is_open())
			{
				finbin11 >> a5;
				finbin11.close();
			}
			//get
			cout << a1.getNume() << endl;
			cout << a1.getPrenume() << endl;
			cout << a1.getAdresa() << endl;
			cout << a1.getNrTelefon() << endl;
			cout << a1.getSalariul() << endl;
			cout << a1.getAnVechime() << endl;
			//set
			a1.setNume("Ion");
			char prenumee2[] = "Victor";
			a1.setPrenume(prenumee2);
			char adresaa2[] = "Strada Aurel Vlaicu";
			a1.setAdresa(adresaa2);
			a1.setNrTelefon("0783957299");
			a1.setSalariul(4500);
			a1.setAnVechime(5);
			cout << a1 << endl;
			// constructor de copiere
			Angajat a3(a);
			cout << a3 << endl;
			// op =
			a3 = a1;
			cout << a3 << endl;
			// functia afisare
			a.afisare();
			// op >>
			cin >> a1;
			//op+
			cout << a1 + 1500 << endl;
			// op++ postincrementare
			cout << a1++;
			//op ++ preincrementare
			cout << ++a1;
			//op +=
			cout << (a1 += (200));
			//op==
			if (a3 == a)
			{
				cout << "\nSunt aceleasi obiecte";
			}
			else
			{
				cout << "\nSunt obiecte diferite";
			}
			cout << endl;
			// op !
			if (!a1)
			{
				cout << "\nSalariul este mai mare ca 2000";
			}
			else
			{
				cout << "\nSalariul este mai mic ca 2000";
			}
			cout << endl;
			// op<
			if (a1 > a2)
			{
				cout << "\nSalariul a1 este mai mare fata de salariul a2";
			}
			else
			{
				cout << "\nSalariul a1 este mai mic fata de salariul a2";
			}
			//op cast
			int nrAnia1;
			nrAnia1 = (int)a1;
			break;
		}

		default: {
			system("cls");
			cout << "Optiune invaida" << endl << endl;
			break;
		}
		}
	}

	Dealer d;
	// constructor cu toti parametri;
	string masini[] = { "AUDI","BMW","Mercedes" };
	char adresa1[] = "Strada Trandafir";
	Dealer d1("Mobile.de", adresa1, "0746260281", 3, masini);

	// constructor cu cativa parametri
	char adresa2[] = "Bd Dorobanti";
	Dealer d2("Autovit", adresa2, "0746263281");


	//constructor fara param si op<<;
	Masina m;

	// constructor cu toti parametri
	char model1[] = { "a4" };
	int revizii1[] = { 25000,80000,138000 };
	Masina m1(723490413, "audi", model1, 2003, 176000, 3, revizii1);
	//cout << m1;
	// constructor cu cativa parametri
	char model2[] = { "a6" };
	Masina m2(12, "audi", model2, 2009, 256000);
	Masina m5;




	// constructor fara param si op <<
	Incasare i;

	// constructor cu toti parametri;
	char luna[] = { "Februarie" };
	string clienti[] = { "Ioan Alexandru", "Popescu Daniela" };
	Incasare i1(luna, 2019, 80000, 2, clienti);

	// constructor cu cativa param
	char luna1[] = "Aprilie";
	string clienti1[] = { "Andrei","Maria","Alin" };
	Incasare i2(luna1, 2021, 1287.5, 3, clienti1);



	// constructor fara param si op <<
	Client c;

	// constructor cu toti parametri
	char prenume1[] = "Pavel";
	float rateramase1[] = { 1300,1320,1390 };
	Client c1("Marinescu", prenume1, "0746260281", "Audi", RATE, 4010, 3, rateramase1);
	//constructor cu cativa param
	char prenume2[] = "Samuel";
	Client c2("Zimbas", prenume2, "0745299273", "BMW");



	// contructor fara parametri si op <<
	Angajat a;

	// constructor cu toti parametri
	char adresaa[] = { "bd unirii" };
	char prenumee[] = { "Anghel  Damian" };
	Angajat a1("Iacob", prenumee, adresaa, "0739850581", 3000, 2);
	//cout << a1;
	// constructor cu cativa parametri
	char adresaa1[] = " bd Nicolae Grigorescu";
	char prenumee1[] = "Aurelian";
	Angajat a2("Nicolai", prenumee1, adresaa1, "0738268109");

	// clasa derivata masinaSport
	MasinaSport ms;
	char tip_motor[] = "V6";
	MasinaSport ms1(34572, "audi", model1, 2009, 180000, 3, revizii1, 1968, tip_motor);


	MasinaSport ms2(ms1);
	ms2 = ms;

	//clasa derivata persoanaJuridica
	PersoanaJuridica pj;
	char numefirma1[] = "S.R.L BANG ";
	PersoanaJuridica pj2("Marin", prenume1, "0746260281", "Audi", RATE, 4010, 3, rateramase1, 2671924, numefirma1);
	PersoanaJuridica pj3(pj2);
	pj3 = pj;

	//clasa compusa fabrica
	Fabrica f;
	char numef1[] = "S.C HOMEBAG ";
	Fabrica f1(numef1, 26000, ms1);
	f1 = f;

	//clasa derivata secretara
	Secretara s;
	Secretara s1("Iacob", prenumee, adresaa, "0739850581", 3000, 2, 40, 32);

	//clasa derivata rata
	Rata r;
	Rata r1(luna, 2019, 80000, 2, clienti, 700, 4);


	// in clasa angajat am implementat 2 metode virtuale: mariresalariu si afisare;
	Angajat* ang[100] = { &a1,&s1 };
	for (int i = 0; i < 2; i++)
	{
		/*ang[i]->afisare();
		cout << endl;
		ang[i]->mariresalariu();*/
	}
	// am testat pentru ierarhie;
	IClient* client[100] = { &c1,&pj2 };
	for (int i = 0; i < 2; i++)
	{
		client[i]->sumaMarita();
	}
	AbsIncasare* vect[100] = { &i1,&r1 };
	for (int i = 0; i < 2; i++)
	{
		/*vect[i]->afisare();
		vect[i]->pretcuTVA();*/
	}


	// rapoartele de la data mining
	ofstream fout;
	fout.open("raportObiecte.txt", ofstream::out);
	dm.raportNrObiecte(fout);
	fout.close();

	ofstream fout1;
	fout1.open("raportAfisari.txt", ofstream::out);
	dm.raportAfisari(fout1);
	fout1.close();

	// STL: am creat o lista care afiseaza obiectele create din clasa Angajat
	// si apoi calculam suma salariilor acelor obiecte
	//cout<<"---------STL-LISTA-------------";
	float suma_salarii = 0;
	list<Angajat>lista_angajati;
	lista_angajati.push_back(a1);
	lista_angajati.push_back(a1);
	lista_angajati.push_back(a2);
	list<Angajat>::iterator it;
	for (it = lista_angajati.begin(); it != lista_angajati.end(); it++)
	{
		/*suma_salarii += it->getSalariul();
		cout << *it;*/
	}
	//cout << "\nsuma salariilor este " << suma_salarii;
	//cout << endl;

	//STL: am creat vectorul_masina in care stochez obiecte de tip masina si le afisez
	//cout<<"---------STL-VECTOR-------------";

	vector <Masina>vector_masina;
	vector_masina.push_back(m1);
	vector_masina.push_back(m2);
	for (int i = 0; i < vector_masina.size(); i++)
	{
		/*cout << vector_masina[i];*/
	}

	// STL map:

	//cout<<"---------STL-VECTOR-------------";
	map< int, Client  > mapare;
	mapare.insert(pair<int, Client>(2, c1));
	mapare.insert(pair<int, Client>(1, c2));
	mapare.insert(pair<int, Client>(3, c));
	map <int, Client>::iterator it1;
	for (it1 = mapare.begin(); it1 != mapare.end(); it1++)
	{
		/*cout << endl;
		cout << "La cheia " << it1->first << " este:";
		cout<< it1->second;*/
	}

	////cout<<"---------STL-SET-------------";

	set <Incasare> setIncasare;
	setIncasare.insert(i1);
	setIncasare.insert(i2);

	set <Incasare>::iterator it3;
	for (it3 = setIncasare.begin(); it3 != setIncasare.end(); it3++)
	{
		//cout << *it3 << " ";
	}

	return 0;
}
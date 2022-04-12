#include "Firma.h"

using namespace std;
Firma::Firma()
{
	cout << "Firma() \n";
}
Firma::~Firma()
{
	cout << "~Firma()\n";
}
void Firma::PodajDateZ()
{
	cout << "Podaj date powstania firmy : "; ///sparwdza czy podana warosæ jest liczb¹, jesli nie to zamyka program
	if (!(cin >> (this)->DataZ))
	{
		cerr << "To nie jest liczba!";
		exit(0);
	}
	
}

void Firma::PodajWartosc()
{
	int w;
	cout << "Wpisz wartosc firmy: ";
	if (!(cin >> (this)->Wartosc))
	{
		cerr << "To nie jest liczba!";
		exit(0);
	}
	
}

int Firma::DajDate()
{
	return DataZ;
}

int Firma::DajWartosc()
{
	return Wartosc;
}

void Firma::Info()
{
	cout << "To jakas tam firma \n";
}

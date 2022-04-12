#include "Sklep.h"

using namespace std;
Sklep::Sklep()
{
	cout << "Sklep() \n";
}
Sklep::Sklep(int data, int wartosc, int kasy)
{
	cout << "Sklep(int,int,int)\n";
	this->DataZ = data;
	this->Wartosc = wartosc;
	this->iloscKas = kasy;
}
Sklep::~Sklep()
{
	cout << "~Sklep() \n";
}
void Sklep::Info()
{
	cout << "Jestem sklepem \n";
}

void Sklep::IleKas()
{
	cout << "Podaj ilosc kas: ";
	if (!(cin >> (this)->iloscKas))
	{
		cerr << "To nie jest liczba!";
		exit(0);
	}
}

int Sklep::DajIleKas()
{
	return iloscKas;
}

std::ostream& operator<<(std::ostream& s, Sklep& a)
{
	return s << "Wartosci/Rok zalozenia/Liczba kas       " << a.Wartosc << "/" << a.DataZ << "/" << a.iloscKas << endl;
}
std::istream& operator>>(std::istream& s, Sklep& a)
{
	string d;
	string b;
	string c;

	char prz = '/';
	s >> d >> prz >> b >> prz >> c >>  a.Wartosc >> prz >> a.DataZ >> prz >> a.iloscKas ;
	return s;
}

bool operator==(Sklep& p1, Sklep& p2)
{

	if (p1.DajDate() != p2.DajDate())
		return false;
	if (p1.DajIleKas() != p2.DajIleKas() )
		return false;
	if (p1.DajWartosc() != p2.DajWartosc() )
		return false;

	return true;
}

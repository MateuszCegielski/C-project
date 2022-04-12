#include "Osiedlowy.h"
#include <string>


using namespace std;

Osiedlowy::Osiedlowy()
{
	cout << "Osiedlowy() \n";
}

Osiedlowy::Osiedlowy(int a, int b, int c, int d)
{
	cout << "Osiedlowy(int a, int b, int c, int d)\n";
	this->Wartosc = b;
	this->DataZ = a;
	this->iloscKas = c;
	this->dziennyUtarg = d;
}

Osiedlowy::~Osiedlowy()
{
	cout << "~Osiedlowy() \n";
}

void Osiedlowy::Info()
{
	cout << "Jestem sklepem osiedlowym\n";
}

void Osiedlowy::PodajUtrag()
{
	cout << "Podaj sredni dzienny utarg: ";
	if (!(cin >> (this)->dziennyUtarg))
	{
		cerr << "To nie jest liczba!";
		exit(0);
	}
}

int Osiedlowy::DajUtrag()
{
	return this->dziennyUtarg;
}

std::ostream& operator<<(std::ostream& s, Osiedlowy& a)
{
	return s << "Wartosci/Rok zalozenia/Liczba kas/Dzienny utarg       " << a.Wartosc << "/"<< a.DataZ <<"/" << a.iloscKas << "/" << a.dziennyUtarg << endl;

}

std::istream& operator>>(std::istream& s, Osiedlowy& a)
{
	string d;
	string b;
	string c;
	string e;
	char prz='/';
	s >> d >> prz>> b>>prz >> c>>prz >>d>> a.Wartosc >> prz>> a.DataZ >>prz>> a.iloscKas>>prz>> a.dziennyUtarg;
	return s;
}

bool operator==(Osiedlowy& p1, Osiedlowy& p2)
{

	if (p1.DajDate() != p2.DajDate())
		return false;
	if (p1.DajIleKas() != p2.DajIleKas())
		return false;
	if (p1.DajWartosc() != p2.DajWartosc())
		return false;
	if (p1.DajUtrag() != p2.DajUtrag())
		return false;

	return true;
}
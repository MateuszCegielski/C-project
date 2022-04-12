#include <iostream>
#include "Pracownik.h"

Pracownik::Pracownik()
{
#ifdef _DEBUG
//	cout << "Dodano nowego pracownika" << endl;
#endif // DEBUG

}

Pracownik::Pracownik(string i, int w, int s)//to konstruktor automatyczy z podaniem parametrów 
{
#ifdef _DEBUG
	//cout << "Dodano nowego pracownika" << endl;
#endif // DEBUG
	this->imie = i;
	this->wiek = w;
	this->staz = s;
	cout << "Hej mam na imie " << imie << " mam " << wiek << " lat i pracuje tu od " << staz << " lat \n \n";


}  

Pracownik::Pracownik(const Pracownik& a) //to konstruktor kopiujacy 
{
#ifdef _DEBUG
	//cout << "Dodano nowego pracownika " << endl;
#endif // DEBUG
	this->imie = a.imie;
	this->wiek = a.wiek;
	this->staz = a.staz;
}

bool operator==(Pracownik& p1, Pracownik&p2)
{
	if (p1.imie != p2.imie)
		return false;
	if (p1.wiek != p2.wiek)
		return false;
	if (p1.staz != p2.staz)
		return false;

	return true;
}

Pracownik::~Pracownik()
{	
#ifdef _DEBUG
	//cout << "Zegnam sie\n";
#endif // DEBUG
}

void Pracownik::DodajPracownik()
{
	int wiek, staz;
	string imie;
	cout << "Podaj imie, wiek i staz pracownika \n";
	cin >> this->imie;
	cin >> this->wiek;
	cin >> this->staz;
	//cout << "Hej mam na imie " << this->imie << " mam " << this->wiek << " lat i pracuje tu od " << this->staz << " lat \n Witaj w naszym warsztacie \n";
}


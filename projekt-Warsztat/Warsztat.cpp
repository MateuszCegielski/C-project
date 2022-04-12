#include <iostream>
#include <vector>
#include "warsztat.h"
#include "Pracownik.h"
#include<stdio.h>
#include <string>
using namespace std;

///kontruktor domyœlny 
Warsztat::Warsztat()
{
	
#ifdef _DEBUG
	//cout << "Otwieramy Warsztat!\n";
#endif
}
///kontruktor z wpisywaniem parametrów
Warsztat::Warsztat(int data, int wartosc,int ile_na)
{
	this->DataZ = data;
	this->Wartosc = wartosc;
	this->ile_napraw = ile_na;
}
void Warsztat::DodajNarzedzia(int ile_na)
{	this->ileNarzedzi = ile_na;
	//n = new Narzedzia[ileNarzedzi];
	

	for (int i = 0; i < ileNarzedzi; i++)
	{
		string na;
		float wa;
		cout << "Nazwa narzedzia: ";
		cin >> na;
		cout << "Waga: ";
		cin >> wa;

		n.push_back(Narzedzia (na,wa));

	}
	cout << "Mamy tyle narzedzi: " << Narzedzia::LiczNarzedzia()<<endl;
}

void Warsztat::Info()
{
	//cout << "Jestem warsztatem \n";
}

void Warsztat::PodajIleNa()
{
	cout << "Podaj liczbe dokonanych napraw: ";
	if (!(cin >> (this)->ile_napraw))
	{
		cerr << "To nie jest liczba!";
		exit(0);
	}
}


int Warsztat::DajIleNa()
{
	return this->ileNarzedzi;
}


/*Warsztat& Warsztat::operator<<=(const Warsztat& w) //operator przypisania
{
	ileNarzedzi = w.ileNarzedzi;
	pracownik = w.pracownik;
	if (n)
	{
		delete[]n;
	}
	if (w.n)
	{
		this->n = new Narzedzia[ileNarzedzi];
		for (int i = 0; i< ileNarzedzi; i++)
		{
			n[i] = w.n[i];
		}
	}
	else
		this->n = 0;


	return *this;
}

*/


Warsztat::~Warsztat()
{
#ifdef _DEBUG
	//cout << "Zamykamy warsztat" << endl;
#endif	
	//delete[]n;
}


Narzedzia Warsztat::operator[](int i) //def operatora indeksowego 
{
	if (i >= ileNarzedzi)
		throw "Nie mamy tylu narzedzi";
	return n[i];  //w przypadku gdy i=1 w czasie kompilacji wyskakuje jakiœ nieos³ugiwany wyj¹tek a ja chce tylko dostaæ pierwszy wyraz 
}

Warsztat::operator string()
{
		return " Imie: "+ pracownik.imie +"\nLat: "+ to_string(pracownik.wiek) + " lat \nStaz: " + to_string(pracownik.staz) + " lat \n\n";
}


std::ostream& operator<<(std::ostream& s, Warsztat& a)
{
	return s << "Wartosci/Rok zalozenia/Liczba napraw       " << a.Wartosc << "/" << a.DataZ << "/" << a.ile_napraw <<endl;

}

std::istream& operator>>(std::istream& s, Warsztat& a)
{
	string d;
	string b;
	string c;

	char prz = '/';
	s >> d >> prz >> b >> prz >> c >> a.DataZ>> prz >> a.Wartosc >> prz >> a.ile_napraw;
	return s;
}

bool operator==(Warsztat& p1, Warsztat& p2)
{

	if (p1.DajDate() != p2.DajDate())
		return false;
	if (p1.DajIleNa() != p2.DajIleNa())
		return false;
	if (p1.DajWartosc() != p2.DajWartosc())
		return false;

	return true;
}

bool operator!=(Warsztat& p1, Warsztat& p2)
{
	if (p1.DajDate() != p2.DajDate())
		return true;
	if (p1.DajIleNa() != p2.DajIleNa())
		return true;
	if (p1.DajWartosc() != p2.DajWartosc())
		return true;

	
	return false;
}

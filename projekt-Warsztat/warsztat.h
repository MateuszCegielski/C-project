#pragma once
#include <iostream>
#include <string>
#include "Narzedzia.h"
#include "Pracownik.h"
#include "Firma.h"
#include <vector>

class Warsztat : public Firma
{
private:
	int ileNarzedzi;
	int ile_napraw=0;
public:
	///kontruktor domyœlny 
	Warsztat();

	Warsztat(int, int,int);
	~Warsztat();
	void DodajNarzedzia(int ile_narzedzi);
	void Info();
	void PodajIleNa();

	int DajIleNa();
	vector<Narzedzia> n;

	Pracownik pracownik;
	
	///operator indeksowy
	Narzedzia operator[](int i);
	
	operator string();

	/// to operatory strumieniowe 
	friend  std::ostream& operator <<(std::ostream& s, Warsztat& a);
	friend  std::istream& operator >>(std::istream& s, Warsztat& a);
};
bool operator==(Warsztat& p1, Warsztat& p2);
bool operator != (Warsztat& p1, Warsztat& p2);

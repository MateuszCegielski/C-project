#pragma once
#include <iostream>
#include <string>
#include "Narzedzia.h"

using namespace std; 
class Pracownik
{
public:
	string imie;
	int wiek;
	int staz;
	Pracownik(); //kontruktor podstawowy 
	Pracownik(string i, int w, int s);//kontruktor z podaniem juz danych
	Pracownik(const Pracownik& a);//kontruktor kopiujacy 
	~Pracownik();

	void DodajPracownik();
};

bool operator==(Pracownik& p1, Pracownik& p2);
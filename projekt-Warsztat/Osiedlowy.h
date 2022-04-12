#pragma once
#include <iostream>
#include "Firma.h"
#include "Sklep.h"

class Osiedlowy : public Sklep
{
public:
	///kontruktor domyœlny 
	Osiedlowy();
	///kontruktor z wpisywaniem parametrów
	Osiedlowy(int a, int b, int c, int d);
	~Osiedlowy();

	void Info();

	void PodajUtrag();
	int DajUtrag();

protected:
	int dziennyUtarg = 0; ///<kolejne pole funkcji pochodnej 

	/// to operatory strumieniowe 
	friend  std::ostream& operator <<(std::ostream& s, Osiedlowy& a);
	friend  std::istream& operator >>(std::istream& s, Osiedlowy& a);
};

bool operator==(Osiedlowy& p1, Osiedlowy& p2);
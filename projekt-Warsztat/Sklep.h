#pragma once
#include <iostream>
#include "Firma.h"

class Sklep : public Firma
{
public:
	///kontruktor domy�lny 
	Sklep();
	///kontruktor z wpisywaniem parametr�w
	Sklep(int data, int wartosc,int kasy);
	virtual ~Sklep();
	void Info();

	
	virtual void IleKas();
	virtual int DajIleKas();

	

protected:
	
	int iloscKas =0; ///<kolejne pole funkcji pochodnej 


	/// to operatory strumieniowe 
	friend  std::ostream& operator <<(std::ostream& s, Sklep& a);
	friend  std::istream& operator >>(std::istream& s, Sklep& a);
};


bool operator==(Sklep& p1, Sklep& p2);
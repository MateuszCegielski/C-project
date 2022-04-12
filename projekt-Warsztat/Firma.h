#pragma once
#include <iostream>


///To bedzie klasa abstrakcyjna 
class Firma 
{
public:
	Firma();
	virtual ~Firma();

	void PodajDateZ();
	void PodajWartosc();

	int DajDate();
	int DajWartosc();

	///to swiadczy o klasie abstrakcyjnej 
	virtual void Info()=0;  
	

protected: 
	int DataZ = 0;
	int Wartosc = 0;

};
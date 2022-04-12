#pragma once
#include <iostream>
#include <string>

using namespace std;

class Narzedzia
{
	static int liczbaNarzedzi; ///<tutaj deklaracja  pola statycznego 
public:
	float wagaNarz;
	string nazwaNarz;
	///deklaracja kontruktora i destruktora
	Narzedzia();  
	Narzedzia(string n, float w);
	Narzedzia(const Narzedzia& a);
	~Narzedzia();

	void ZdefiniujNarz();
	
	static int LiczNarzedzia();

	Narzedzia& operator++();   //operator preinkrementacji 
};

std::ostream& operator<<(std::ostream& s, Narzedzia& n);//operator strumieniowy

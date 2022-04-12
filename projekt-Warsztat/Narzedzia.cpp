#include <iostream>
#include "Narzedzia.h"


using namespace std;
int Narzedzia::liczbaNarzedzi = 0; //ustalam pole statyczne na 0


Narzedzia::Narzedzia()
{
#ifdef _DEBUG //wyœwietli mi cout tylko jesli u¿yje DEBUGA

	//cout << "Jestem konstruktorem narzedzi \n ";

#endif // _DEBUG
	
	this->nazwaNarz = " "; // standardowo ustawiam wszysttko na 0
	this->wagaNarz = 0;

	liczbaNarzedzi++;
	//cout<<LiczNarzedzia();
}
Narzedzia::Narzedzia(string n, float w)
{
	cout << "Narzedzia(string n, float w) \n ";
	this->nazwaNarz = n; 
	this->wagaNarz = w;

	liczbaNarzedzi++;
}
Narzedzia::Narzedzia(const Narzedzia& a)
{
	this->nazwaNarz = a.nazwaNarz;
	this->wagaNarz = a.wagaNarz;
	liczbaNarzedzi++;
}
Narzedzia::~Narzedzia() //definiuje destruktor 
{
#ifdef _DEBUG //wyœwietli mi cout tylko jesli u¿yje DEBUGA
	//cout << "Jestem destruktorem narzedzi \n ";
	
#endif // _DEBUG
	liczbaNarzedzi--;
	cout << "Mamy tyle narzedzi: " << Narzedzia::LiczNarzedzia() << endl;
		
	
}

void Narzedzia::ZdefiniujNarz()
{
	cout << "Podaj nazwe narzedzia: ";
	cin >> this->nazwaNarz;
	cout << "Podaj jego wage: ";
	cin >> this->wagaNarz;
}

/// ta funkcja zwroci mi ile mam narzedzi jak j¹ wywo³am w main
int Narzedzia::LiczNarzedzia() 
{
	return liczbaNarzedzi;
}
///operator preinkrementacji 
Narzedzia& Narzedzia::operator++()
{
	wagaNarz++;

	return *this;
}
///operator strumieniowy
std::ostream& operator<<(std::ostream& s, Narzedzia& n) 
{
	return s << n.nazwaNarz << " o wadze " << n.wagaNarz<<"kg ";
}

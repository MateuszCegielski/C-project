#pragma once
#include <iostream>


using namespace std;

template <class T>
class wezel
{
public:
	wezel(){};
	wezel(wezel& w);
	~wezel();

	T el;
	wezel * na;
	wezel* po;
};

template <class T>
class lista
{
public:

	lista() {};
	lista(lista& l);
	~lista();

	void dodaj(T& a);
	void dodaj(T& a, int e);

	void usun_o();
	void usun_p();
	void usun(int k);

	void wyczysc();
	int rozmiar();
	void zamien(int w1, int w2);

	bool contains(T& a)
	{
		wezel<T>* tmp;
		tmp = this->pierwszy;
		for (int i = 0; i < this->rozmiar(); i++)
		{
			if (a == tmp->el)
				return true;

			tmp = tmp->na;
		}

		return false;
	}
	lista<T>& operator=(const lista& l);
	lista<T>& operator+(const lista& l);

	bool operator==( lista& l);


	friend ostream & operator<<(ostream& a, lista& l)
	{
		wezel<T>* tmp = l.pierwszy;

		while (tmp != nullptr)
		{
			a << tmp->el;
			tmp = tmp->na;
		}

		return a;
	}
	
	friend istream& operator>>(istream& a, lista& l)
	{
		 wezel<T>* tmp = l.pierwszy;

		while (tmp != nullptr)
		{
			a >> tmp->el;
			tmp = tmp->na;
		}
		return a;
	}

	wezel<T>* pierwszy= nullptr;
	wezel<T>* ostatni = nullptr;
};

template<class T>
inline wezel<T>::wezel(wezel& w)
{
	this->el = w.el;
	this->na = w.na;
	this->po = w.po;
}

template<class T>
inline wezel<T>::~wezel()
{
	cout << "Jestem destruktorem wezla\n";
	if (this->na == nullptr || this->po == nullptr)
	{
		
	}

	else
	{
		std::cout << "Zmiana \n";
		this->po->na = this->na;
		this->na->po = this->po;
		
	}
}



template<class T>
inline lista<T>::lista(lista& l)
{
	wezel* tmp = l->pierwszy;
	while (tmp != nullptr)
	{
		this->dodaj(tmp->el);
		tmp = tmp->na;
	}
}

template<class T>
inline lista<T>::~lista()
{
	this->wyczysc();
		cout << this->rozmiar();
}

template<class T>
inline void lista<T>::dodaj(T& a)
{
	wezel<T> *nw=new wezel<T>();
	nw->el = a;
	nw->na = nullptr;
	nw->po = nullptr;

	if (this->pierwszy == 0)
	{
		this->pierwszy = nw;
	}

	else
	{
		wezel<T>* tmp = this->pierwszy;

		while (tmp->na != nullptr)
		{
			tmp = tmp->na;
		}
		
		tmp->na = nw;
		nw->po = tmp;
		this->ostatni = nw;

	}
}

template<class T>
inline void lista<T>::dodaj(T& a1, int e)
{
	string a = "Liczba spoza zakresu \n";
	int o = this->rozmiar();

	if ((e < 1) || o + 1 < e)
		throw a;
	
	if ((o+1) == e)
	{
		cout << "Uzywam metody dodaj(T& a)\n";
		
		this->dodaj(a1);
		
	}
	
	wezel<T>* nw = new wezel<T>();
	nw->el = a1;
	if (e == 1)
	{
		nw->na = this->pierwszy;
		this->pierwszy= nw;
		nw->po = nullptr;
	}

	if((e !=1) && (o+1 !=e))
	{
		wezel<T>* tmp;
		tmp = this->pierwszy;
		for (int i = 1; i < e-1 ; i++)
		{
			tmp = tmp->na;
		}
		nw->na = tmp->na;
		tmp->na->po= nw;
		tmp->na = nw;
		nw->po = tmp;

	}
}

template<class T>
inline void lista<T>::usun_o()
{
	cout << "Usuwam ostatni element\n";
	wezel<T> * tmp = this->ostatni;
	tmp->po->na = nullptr;
	this->ostatni = tmp->po;
	delete tmp;
}
template<class T>
inline void lista<T>::usun_p()
{
	cout << "Usuwam pierwszy element\n";
	wezel<T>* tmp = this->pierwszy;
	tmp->na->po = nullptr;
	this->pierwszy = tmp->na;
	delete tmp;
}
template <class T>
inline void lista<T> ::usun(int k)
{
	string z = "Nie ma takiego elementu";
	if ( (k< 1) || (k > this->rozmiar() ) )
			throw z;

	if (k==1 || k==this->rozmiar() )
	{
		if (k == 1)
			this->usun_p();

		if (k == this->rozmiar())
			this->usun_o();
	
	}
	else
	{
		wezel<T>* tmp = this->pierwszy;
		for (int i = 1; i < k; i++)
		{
			
			tmp = tmp->na;
		}
		delete tmp;
	}
}

template<class T>
inline void lista<T>::wyczysc()
{
	if (this->pierwszy == nullptr)
		cout << "Lista jest pusta\n";

	else
	{
		wezel<T>* tmp= pierwszy;
		while (tmp!=nullptr)
		{
			this->pierwszy = tmp->na;
			delete tmp;
			tmp = this->pierwszy;
		}
		
	}
}

template<class T>
inline int lista<T>::rozmiar()
{
	int ile = 0; 
	wezel<T> *w = this->pierwszy;
	while (w != nullptr)
	{
		w = w->na;
		ile++;
	}

	return ile;
}

template<class T>
inline void lista<T>::zamien(int w1, int w2)
{
	string c = "Nie ma takiej pozycji na liscie \n";
	if ((w1  < 1) || (w2<1) || (w1>this->rozmiar() ) || (w2 > this->rozmiar() ) )
		throw c;

	wezel<T>* we1 = this->pierwszy;
	for (int i = 1; i < w1; i++)
	{
		we1 = we1->na;
	}

	wezel<T>* we2 = this->pierwszy;
	for (int i = 1; i < w2; i++)
	{
		we2 = we2->na;
	}

	
	wezel<T>* tmp = new wezel<T>();

	tmp->el = we1->el;
	we1->el = we2->el;
	we2->el = tmp->el;

	delete tmp;

}


template<class T>
inline lista<T>& lista<T>::operator=(const lista& l)
{
	this->wyczysc();
	wezel<T>* tmp = l.pierwszy;
	while (tmp != nullptr)
	{
		this->dodaj(tmp->el);
		tmp = tmp->na;
	}
	return *this;
}

template<class T>
inline lista<T>& lista<T>::operator+(const lista& l)
{
	lista<T>* list = new lista<T>();

	wezel<T>* tmp = this->pierwszy;

	while (tmp != nullptr)
	{
		list->dodaj(tmp->el);

		tmp = tmp->na;

	}
	tmp = l.pierwszy;

	while (tmp != nullptr)
	{
		list->dodaj(tmp->el);

		tmp = tmp->na;

	}

	return *list;
}

template<class T>
inline bool lista<T>::operator==( lista &l)
{
	if (this->rozmiar()!=l.rozmiar()) ;
	return false;

	wezel<T>* tmp1;
	wezel<T>* tmp2;
	tmp1 = l.pierwszy;
	tmp2 = this->pierwszy;
	while (tmp2 != nullptr)
	{
		if (tmp1->el != tmp2->el)
			return false;

		tmp2 = tmp2->na;
		tmp1 = tmp1->na;
		
	}

	return true;
}


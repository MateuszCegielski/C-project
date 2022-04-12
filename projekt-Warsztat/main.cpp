#include <iostream>
#include <vector>
#include <fstream>
#include "narzedzia.h"
#include "Pracownik.h"
#include "warsztat.h"
#include "Firma.h"
#include "Sklep.h"
#include "Osiedlowy.h"
#include "Kontener.h"
#include <conio.h>

using namespace std;


///Funkcja testuj¹ca program
void Test();

/// ZapisDoPliku
void ZapisDoPliku(lista<Warsztat>& l);

/// OdczytZPliku
void OdczytZPliku();

/// Zamiana
void Zamiana(lista<Warsztat>& l);

void UsuwanieWy(lista<Warsztat>& l);

void DodawanieWy(lista<Warsztat>& l);

void CzyOJestNaLiscie(lista<Warsztat>& l);

void DodawanieList(lista<Warsztat>& l, lista<Warsztat>& l2);

void PorownanieList(lista<Warsztat>& l, lista<Warsztat>& l2);

int main()
{
    Test();
    

}
void PorownanieList(lista<Warsztat>& l, lista<Warsztat>& l2)
{
    cout <<"Sparwdzimy czy te dwie listy sa takie same  \n" << l << endl;
    cout << l2 << endl;

    cout << "Sprawdzamy czy listy sa takie same: " << (l == l2) << endl;

    cout << "Teraz porownamy te sama liste  : " << (l == l) << endl;


}

void DodawanieList(lista<Warsztat>& l, lista<Warsztat>& l2)
{
    cout << "Nasza lista \n" << l;
    cout << "Lista ktora dodamy \n" << l2;

    lista<Warsztat> l3;
    l3 = l + l2;  /// tutaj testujemy operator+ i operator=
    cout << "To jest nowa lista \n"<< l3<<endl;
}
void CzyOJestNaLiscie(lista<Warsztat>& l)
{
    Warsztat s1;
    cout << "Jakiego obiketu szukasz: "<<endl;
    s1.PodajDateZ();
    s1.PodajWartosc();
    s1.PodajIleNa();

    cout << "Sprawdzam czy obiekt jest w liscie:  " << l.contains(s1) << endl << endl;
    cout << l << endl;
}

void DodawanieWy(lista<Warsztat>& l)
{
    int w1, w2;
    Warsztat s10;
    s10.PodajDateZ();
    s10.PodajWartosc();
    s10.PodajIleNa();

    cout << l <<endl <<"Na jaka pozycje chcesz dodac ten obiket? \n";
    cin >> w2;

    try
    {
        l.dodaj(s10, w2);
    }
    catch (string a)
    {
        cout << a << endl;
    }
    cout << l << endl;
}


    void UsuwanieWy(lista<Warsztat> & l)
    {
        int w;
        cout << "Liczba elementow: " << l.rozmiar() << endl;
        cout << l << endl << endl <<"Ktora pozycje chcesz usunac ? \n" ;
        cin >> w;
        try
        {
            l.usun(w);
        }
        catch (string z)
        {
            cout << z << endl;
        }
        cout << "Liczba elementow: " << l.rozmiar() << endl;
        cout << l << endl << endl;
    }
    
// Zamiana
void Zamiana(lista<Warsztat>& l)
{
    int w1, w2;
    cout << l;
    cout << "Ktore pozycje chcesz zamienic ? (int/int)" << endl;
    cin >> w1;
    cin >> w2;
    try
    {
        l.zamien(w1, w2);
    }
    catch (string c)
    {
        cout << c << endl;
    }

    cout << "Liczba elementow: " << l.rozmiar() << endl;
    cout << l;
}

void OdczytZPliku(lista<Warsztat>& l)
{
    ifstream ifs;
    ifs.open("plik.txt", ios_base::in);

    
    ifs >> l;

    cout << "Lista wczytana z pliku "<< endl << l << endl;
}

    void ZapisDoPliku(lista<Warsztat>& l)
    {
        cout << endl << "ZapisDoPliku() " << endl;
        ofstream ofs;
        ofs.open("plik.txt", ios_base::out);
        
        ofs << l;
        ofs.close();
    }




void Test()
{
    lista<Warsztat> l;
    Warsztat s1(1, 1, 1);
    Warsztat s2(2, 2, 2);
    Warsztat s3(3, 3, 3);

    lista<Warsztat> l2;
    Warsztat s4(4, 4, 4);
    Warsztat s5(5, 5, 5);
    Warsztat s6(6, 6, 6);

    l.dodaj(s1);
    l.dodaj(s2);
    l.dodaj(s3);
    l.dodaj(s4);

    l2.dodaj(s5);
    l2.dodaj(s6);


    cout << "To bedzie nasza bazowa lista \n" << l << endl;
    cout << "Liczba elementow: " << l.rozmiar() << endl;

    cout << "To druga lista \n" << l2 << endl;
    cout << "Liczba elementow: " << l2.rozmiar() << endl;


    for (;;)
    {
        cout << "TEST PROGRAMU\n\n__________________________________________\n";
        cout << "1. Dodawanie elementu do listy." << endl;
        cout << "2. Usuwanie elelmentu z listy." << endl;
        cout << "3. Zamiana elementu na liscie." << endl;
        cout << "4. Sprawdz czy taki obiekt jest na liscie." << endl;
        cout << "5. Dodawanie list do siebie" << endl;
        cout << "6. Porownywanie list ." << endl;
        cout << "7. Zapis do pliku." << endl;
        cout << "8. Odczyt z pliku." << endl;
        cout << "9. Zakonczenie pracy programu." << endl << endl << endl;
        int wybor;
        cout << "Wybierz jaka operacje chcesz wykonac: ";
        wybor= _getch();
        switch (wybor)
        {
        case('1'): DodawanieWy(l);
            
            break;

        case('2'): UsuwanieWy(l);
            
            break;

        case('3'): Zamiana(l);
            
            break;

        case('4'): CzyOJestNaLiscie(l);
            
            break;
        case('5'): DodawanieList(l, l2);
            
            break;
        case('6'): PorownanieList(l, l2);
            
            break;
        case('7'): ZapisDoPliku(l);
            
            break;
        case('8'): OdczytZPliku(l);
             
            break;

        case('9'):
            exit(0);
            break;

        default:
            cout << "Nie ma takiej mozliwosci w opcjach" << endl;
            break;
        }
        getchar(); getchar();
        system("cls");

    }




}

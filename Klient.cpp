#include "stdafx.h"

using namespace std;

Klient::Klient()
{
	cout << "Wpowadz dane na temat klienta" << endl << endl;
	cout << "Imie: ";
	cin >> this->imie;
	cout << endl << endl;
	cout << "Nazwisko: ";
	cin >> this->nazwisko;
	cout << endl << endl;
	cout << "Nazwa ulicy domu/mieszkania: ";
	cin >> this->nazwa_ulicy;
	cout << endl << endl;
	cout << "Numer ulicy: ";
	cin >> this->nr_ulicy;
	cout << endl << endl;
	wyb:
	cout << "W jakim budynku mieszka ta osoba?" << endl;
	cout << "1. Dom wolno stojacy" << endl;
	cout << "2. Blok mieszkalny/Hotel" << endl;
	cout << "Wybrana opcja: ";
	cin >> this->dom;
	cout << endl << endl;
	if (this->dom == 2)
	{
		cout << "Numer mieszkania/pokoju: ";
		cin >> this->nr_mieszkania;
		cout << endl << endl;
	}
	else if (this->dom != 1 && this->dom != 0)
	{
		cout << "Wybrano niepoprawna opcje. Prosze dokonac wyboru jeszcze raz." << endl << endl;
		goto wyb;
	}
	cout << "Login: ";
	cin >> this->login;
	cout << endl << endl;
	cout << "Haslo: ";
	cin >> this->haslo;
	cout << endl << endl;
}

void Klient::wyswietl()
{
	cout << "Imie: " << this->imie << endl;
	cout << "Nazwisko: " << this->nazwisko << endl;
	if (this->dom == 1)
	{
		cout << "Adres: " << this->nazwa_ulicy << " " << this->nr_ulicy << endl;
	}
	if (this->dom == 2)
	{
		cout << "Adres: " << this->nazwa_ulicy << " " << this->nr_ulicy << "/" << this->nr_mieszkania << endl;
	}
	cout << "Login: " << this->login << endl;
	cout << "Haslo: " << this->haslo << endl;
}

void Klient::edytuj()
{
	cout << "Wpowadz nowe dane klienta" << endl << endl;
	cout << "Imie: ";
	cin >> this->imie;
	cout << endl << endl;
	cout << "Nazwisko: ";
	cin >> this->nazwisko;
	cout << endl << endl;
	cout << "Nazwa ulicy domu/mieszkania: ";
	cin >> this->nazwa_ulicy;
	cout << endl << endl;
	cout << "Numer ulicy: ";
	cin >> this->nr_ulicy;
	cout << endl << endl;
	wyb1:
	cout << "W jakim budynku mieszka ta osoba?" << endl;
	cout << "1. Dom wolno stojacy" << endl;
	cout << "2. Blok mieszkalny/Hotel" << endl;
	cout << "Wybrana opcja: ";
	cin >> this->dom;
	cout << endl << endl;
	if (this->dom == 2)
	{
		cout << "Numer mieszkania/pokoju: ";
		cin >> this->nr_mieszkania;
		cout << endl << endl;
	}
	else if (this->dom != 1 && this->dom != 0)
	{
		cout << "Wybrano niepoprawna opcje. Prosze dokonac wyboru jeszcze raz." << endl << endl;
		goto wyb1;
	}
	cout << "Login: ";
	cin >> this->login;
	cout << endl << endl;
	cout << "Haslo: ";
	cin >> this->haslo;
	cout << endl << endl;
}

void Klient::pokaz()
{
	cout << this->imie << " " << this->nazwisko << endl;
}

void Klient::dodajzam(IloscZamowien & k)
{
	dodaj(k);
}
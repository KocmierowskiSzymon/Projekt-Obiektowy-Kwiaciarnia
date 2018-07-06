#include "stdafx.h"

using namespace std;

class Klient
{
private:
	string imie;
	string nazwisko;
	string nazwa_ulicy;
	string nr_ulicy;
	int nr_mieszkania;
	int dom;

public:
	string login;
	string haslo;
	Klient();
	void wyswietl();
	void edytuj();
	void pokaz();
	void dodajzam(IloscZamowien & k);
};
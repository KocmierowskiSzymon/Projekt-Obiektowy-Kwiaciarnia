#include "stdafx.h"

using namespace std;

IloscZamowien::IloscZamowien()
{
	this->liczba_zamowien = 0;
}

void dodaj(IloscZamowien & k)
{
	k.liczba_zamowien++;
}

void IloscZamowien::wyswietl()
{
	cout << "Liczba zlozonych zamowien: " << this->liczba_zamowien << endl << endl;
}

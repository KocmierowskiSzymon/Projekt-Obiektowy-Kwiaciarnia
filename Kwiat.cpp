#include "stdafx.h"

using namespace std;

Kwiat::Kwiat()
{
}

void Kwiat::wyswietlk()
{
	cout << "Nazwa: " << this->nazwa << endl;
	cout << "Cena: " << this->cena << endl;
	cout << "Ilosc: " << this->ilosc << endl;
}

void Kwiat::edytujk()
{
	cout << "Wprowadz dane na temat kwiata." << endl << endl;
	cout << "Nazwa: ";
	cin >> this->nazwa;
	cout << endl << endl;
	cout << "Cena: ";
	cin >> this->cena;
	this->ilosc = 0;
}

void Kwiat::pokazk()
{
	cout << this->nazwa;
}
#include "stdafx.h"

using namespace std;

class IloscZamowien
{
public:
	friend class Klient;
	friend void dodaj(IloscZamowien & k);
	IloscZamowien();
	void wyswietl();
private:
	int liczba_zamowien;
};
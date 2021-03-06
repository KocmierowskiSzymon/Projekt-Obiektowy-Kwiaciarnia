#include "stdafx.h"

using namespace std;

typedef int zmienna;

typedef struct kwiatlist
{
	Kwiat kwiatek;
	kwiatlist* next = NULL;
	kwiatlist* prev = NULL;
}kwiatlist;

typedef struct listklientow
{
	Klient kliencik;
	IloscZamowien zmow;
	listklientow* next = NULL;
	listklientow* prev = NULL;
}listklientow;

kwiatlist* glowakwia = NULL;
kwiatlist* tempkwia1 = NULL;
kwiatlist* tempkwia2 = NULL;
kwiatlist* tempkwia3 = NULL;
kwiatlist* konieckwia = NULL;
listklientow* glowakli = NULL;
listklientow* tempkli1 = NULL;
listklientow* tempkli2 = NULL;
listklientow* tempkli3 = NULL;
listklientow* konieckli = NULL;

void dodaj_kwiat()
{
	kwiatlist* nowy = new kwiatlist;
	cout << "Wprowadz dane na temat kwiata." << endl << endl;
	cout << "Nazwa: ";
	cin >> nowy->kwiatek.nazwa;
	cout << endl;
	cout << "Cena: ";
	cin >> nowy->kwiatek.cena;
	cout << endl;
	nowy->kwiatek.ilosc = 0;
	if (glowakwia == NULL)
	{
		glowakwia = nowy;
		konieckwia = nowy;
	}
	else
	{
		konieckwia->next = nowy;
		nowy->prev = konieckwia;
		konieckwia = nowy;
	}
};

void edytuj_kwiat()
{
	tempkwia1 = glowakwia;
	zmienna liczba = 1;
	zmienna wy;
	wro:
	cout << "Informacje na temat ktorego kwiata chcesz edytowac?" << endl << endl;
	while (tempkwia1 != NULL)
	{
		cout << liczba << ". ";
		tempkwia1->kwiatek.pokazk();
		cout << endl;
		tempkwia1 = tempkwia1->next;
		liczba++;
	}
	cout << endl;
	cout << "Wybrana opcja: ";
	cin >> wy;
	cout << endl << endl;
	tempkwia1 = glowakwia;
	if (wy >= 1 && wy <= liczba)
	{
		for (int i = 1; i < wy; i++)
		{
			tempkwia1 = tempkwia1->next;
		}
		tempkwia1->kwiatek.edytujk();
	}
	else
	{
		cout << "Wybrano niepoprawna opcje. Prosze dokonac wyboru jeszcze raz." << endl << endl;
		goto wro;
	}
};

void wyswietl_kwiat()
{
	zmienna liczba = 1;
	tempkwia1 = glowakwia;
	while (tempkwia1 != NULL)
	{
		cout << liczba << ". ";
		tempkwia1->kwiatek.wyswietlk();
		cout << endl;
		liczba++;
		tempkwia1 = tempkwia1->next;
	}
	system("pause");
};

void usun_kwiat()
{
	zmienna liczba = 1;
	zmienna wy;
	tempkwia1 = glowakwia;
	wro1:
	cout << "Ktory kwiat chcesz usunac z kwiaciarnii?" << endl << endl;
	while (tempkwia1 != NULL)
	{
		cout << liczba << ". ";
		tempkwia1->kwiatek.pokazk();
		cout << endl;
		tempkwia1 = tempkwia1->next;
		liczba++;
	}
	cout << endl << endl;
	cout << "Wybrana opcja: ";
	cin >> wy;
	cout << endl << endl;
	tempkwia1 = glowakwia;
	if (wy >= 1 && wy <= liczba)
	{
		for (int i = 1; i < wy; i++)
		{
			tempkwia1 = tempkwia1->next;
		}
		if (glowakwia == konieckwia)
		{
			delete glowakwia;
			glowakwia = NULL;
			konieckwia = NULL;
		}
		else if (tempkwia1 == konieckwia)
		{
			konieckwia = konieckwia->prev;
			delete tempkwia1;
			konieckwia->next = NULL;
			
		}
		else if (tempkwia1 == glowakwia)
		{
			glowakwia = glowakwia->next;
			delete tempkwia1;
			glowakwia->prev = NULL;
		}
		else
		{
			tempkwia2 = tempkwia1->next;
			tempkwia3 = tempkwia1->prev;
			tempkwia2->prev = tempkwia3;
			tempkwia3->next = tempkwia2;
			delete tempkwia1;
		}
	}
	else
	{
		cout << "Wybrano niepoprawna opcje. Prosze dokonac wyboru jeszcze raz." << endl << endl;
		goto wro1;
	}
};

void dodaj_klient()
{
	listklientow* nowy = new listklientow;
	if (glowakli == NULL)
	{
		glowakli = nowy;
		konieckli = nowy;
	}
	else
	{
		konieckli->next = nowy;
		nowy->prev = konieckli;
		konieckli = nowy;
	}
};

void edytuj_klient()
{
	zmienna liczba = 1;
	zmienna wy;
	tempkli1 = glowakli;
	wro2:
	cout << "Ktore dane klienta chcesz edytowac?" << endl << endl;
	while (tempkli1 != NULL)
	{
		cout << liczba << ". ";
		tempkli1->kliencik.pokaz();
		cout << endl;
		liczba++;
		tempkli1 = tempkli1->next;
	}
	cout << endl;
	cout << "Wybrana opcja: ";
	cin >> wy;
	cout << endl << endl;
	tempkli1 = glowakli;
	if (wy >= 1 && wy <= liczba)
	{
		for (int i = 1; i < wy; i++)
		{
			tempkli1 = tempkli1->next;
		}
		tempkli1->kliencik.edytuj();
	}
	else
	{
		cout << "Wybrano niepoprawna opcje. Prosze dokonac wyboru jeszcze raz." << endl << endl;
		goto wro2;
	}
};

void wyswietl_klient()
{
	zmienna liczba = 1;
	tempkli1 = glowakli;
	while (tempkli1 != NULL)
	{
		cout << liczba << ". ";
		tempkli1->kliencik.wyswietl();
		tempkli1->zmow.wyswietl();
		cout << endl;
		liczba++;
		tempkli1 = tempkli1->next;
	}
	system("pause");
};

void usun_klient()
{
	zmienna wy;
	tempkli1 = glowakli;
	wro3:
	cout << "Ktorego klienta chcesz usunac z spisu klientow?" << endl << endl;
	zmienna liczba = 1;
	while (tempkli1 != NULL)
	{
		cout << liczba << ". ";
		tempkli1->kliencik.pokaz();
		cout << endl;
		tempkli1 = tempkli1->next;
		liczba++;
	}
	cout << endl << endl;
	cout << "Wybrana opcja: ";
	cin >> wy;
	cout << endl << endl;
	tempkli1 = glowakli;
	if (wy >= 1 && wy <= liczba)
	{
		for (int i = 1; i < wy; i++)
		{
			tempkli1 = tempkli1->next;
		}
		if (glowakli == konieckli)
		{
			delete glowakli;
			glowakli = NULL;
			konieckli = NULL;
		}
		else if (tempkli1 == konieckli)
		{
			konieckli = konieckli->prev;
			delete tempkli1;
			konieckli->next = NULL;

		}
		else if (tempkli1 == glowakli)
		{
			glowakli = glowakli->next;
			delete tempkli1;
			glowakli->prev = NULL;
		}
		else
		{
			tempkli2 = tempkli1->next;
			tempkli3 = tempkli1->prev;
			tempkli2->prev = tempkli3;
			tempkli3->next = tempkli2;
			delete tempkli1;
		}
	}
	else
	{
		cout << "Wybrano niepoprawna opcje. Prosze dokonac wyboru jeszcze raz." << endl << endl;
		goto wro3;
	}
};

void dostawa()
{
	zmienna liczba = 0, wyb, il;
	tempkwia1 = glowakwia;
	while (tempkwia1 != NULL)
	{
		liczba++;
		tempkwia1 = tempkwia1->next;
	}
	dos:
	cout << "Jakie kwiaty chcesz zamowic?" << endl << endl;
	wyswietl_kwiat();
	cout << "Wybrana opcja: ";
	cin >> wyb;
	if (wyb<0 || wyb>liczba)
	{
		cout << "Wybrano niepoprawna operacje. Prosze wybrac operacje jeszcze raz." << endl;
		system("pause");
		goto dos;
	}
	else
	{
		tempkwia1 = glowakwia;
		for (int i = 1; i < wyb; i++)
		{
			tempkwia1 = tempkwia1->next;
		}
		cout << "W jakiej ilosci chcesz, aby dostarczono te kwiaty?" << endl;
		cout << "Ilosc: ";
		cin >> il;
		cout << endl << endl;
		if (il < 1)
		{
			cout << "Trzeba zamowic przynajmniej jedna sztuke kwiatka. Powrot do wyboru zamawiania kwiatow." << endl;
			system("pause");
			goto dos;
		}
		else
		{
			tempkwia1->kwiatek.ilosc = tempkwia1->kwiatek.ilosc + il;
			cout << "Dostarczono " << il << " kwiatow o nazwie: " << tempkwia1->kwiatek.nazwa << " do kwiaciarnii." << endl;
		}
		system("pause");
	}
};

void zakup_na_miejscu()
{
	zmienna liczba = 0, wyb, ilo, prz = 0, zero = 0;
	float suma = 0, skl;
	tempkwia1 = glowakwia;
	tempkwia2 = NULL;
	tempkwia3 = NULL;
	if (glowakwia == NULL)
	{
		cout << "W kwiaciarni nie ma zadnych kwiatow. Prosze wrocic, jak kwiaty beda dostarczone do kwiaciarni." << endl;
		goto bak1;
	}
	while (tempkwia1!=NULL)
	{
		liczba++;
		if (tempkwia1->kwiatek.ilosc != 0)
		{
			zero = 1;
		}
		tempkwia1=tempkwia1->next;
	}
	if (zero == 0)
	{
		cout << "W kwiaciarni nie ma zadnych kwiatow. Prosze wrocic, jak kwiaty beda dostarczone do kwiaciarni." << endl;
		goto bak1;
	}
	while (1)
	{
		zaku:
		system("cls");
		cout << "Ktory chcesz kwiat kupic?" << endl << endl;
		wyswietl_kwiat();
		cout << "0. Zakoncz zakupy" << endl << endl;
		cout << "Wybrana opcja: ";
		cin >> wyb;
		if (wyb == 0)
		{
			cout << "Skonczono zakupy. Kliknij enter, aby przejsc do wyswietlenia paragonu." << endl;
			system("pause");
			break;
		}
		else if (wyb < 0 || wyb > liczba)
		{
			cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
			system("pause");
			goto zaku;
		}
		else
		{
			tempkwia1 = glowakwia;
			for (int i = 1; i < wyb; i++)
			{
				tempkwia1 = tempkwia1->next;
			}
			cout << "W jakiej ilosc chcesz kupic ten kwiat?" << endl;
			cout << "Ilosc: ";
			cin >> ilo;
			cout << endl << endl;
			if (ilo > tempkwia1->kwiatek.ilosc)
			{
				cout << "Nie ma takiej ilosci tego kwiatka w kwiaciarni. Powrot do opcji wybrania kwiatka." << endl;
				cout << "Obecna ilosc tego kwiatka w kwiaciarni: " << tempkwia1->kwiatek.ilosc << endl;
				system("pause");
				goto zaku;
			}
			else if (ilo < 0)
			{
				cout << "Nie mozna kupic ujemnej ilosci kwiatow. Powrot do opcji wybrania kwiatka." << endl;
				cout << "Obecna ilosc tego kwiatka w kwiaciarni: " << tempkwia1->kwiatek.ilosc << endl;
				system("pause");
				goto zaku;
			}
			else
			{
				prz++;
				kwiatlist* nowy = new kwiatlist;
				if (tempkwia2 == NULL)
				{
					nowy->kwiatek.nazwa = tempkwia1->kwiatek.nazwa;
					nowy->kwiatek.cena = tempkwia1->kwiatek.cena;
					nowy->kwiatek.ilosc = ilo;
					tempkwia2 = nowy;
					tempkwia3 = nowy;
				}
				else
				{
					nowy->kwiatek.nazwa = tempkwia1->kwiatek.nazwa;
					nowy->kwiatek.cena = tempkwia1->kwiatek.cena;
					nowy->kwiatek.ilosc = ilo;
					tempkwia3->next = nowy;
					nowy->prev = tempkwia3;
					tempkwia3 = nowy;
				}
				tempkwia1 = glowakwia;
				while (tempkwia1->kwiatek.nazwa != tempkwia3->kwiatek.nazwa && tempkwia1->kwiatek.cena != tempkwia3->kwiatek.cena)\
				{
					tempkwia1 = tempkwia1->next;
				}
				tempkwia1->kwiatek.ilosc = tempkwia1->kwiatek.ilosc - tempkwia3->kwiatek.ilosc;
			}
		}
	}
	system("cls");
	cout << "Twoj paragon:" << endl << endl;
	while (tempkwia2 != NULL)
	{
		skl = tempkwia2->kwiatek.cena*tempkwia2->kwiatek.ilosc;
		if (skl != 0)
		{
			cout << tempkwia2->kwiatek.nazwa << "			" << tempkwia2->kwiatek.ilosc << " * " << tempkwia2->kwiatek.cena << "		" << skl << endl;
			suma = suma + skl;
		}
		tempkwia2 = tempkwia2->next;
	}
	tempkwia2 = tempkwia3;
	for (int i = 1; i <= prz; i++)
	{
		tempkwia2 = tempkwia2->prev;
		delete tempkwia3;
		tempkwia3 = tempkwia2;
	}
	cout << endl;
	cout << "						SUMA: " << suma << endl << endl;
	bak1:
	cout << endl;
}

int main()
{
	zmienna wybor, n = 1;
	string log, pass;
	while (n)
	{
		system("cls");
		cout << "Menu programu obslugi kwiaciarni" << endl;
		cout << "Prosze wybrac jedna z podanych operacji." << endl;
		cout << "1. Zaloguj sie" << endl;
		cout << "2. Dokonaj zakupu w kwiaciarni" << endl;
		cout << "3. Zakoncz dzialanie programu" << endl << endl;
		cout << "Wybrana operacja: ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			zmienna a = 1, komuni = 0, b = 1;
			loggo:
			system("cls");
			cout << "Prosze sie zalogowac" << endl << endl;
			cout << "Login: ";
			cin >> log;
			cout << endl;
			cout << "Haslo: ";
			cin >> pass;
			cout << endl;
			if (log == "admin" && pass == "admin")
			{
				while (a)
				{
					system("cls");
					cout << "Jestes zalogowany jako: administrator" << endl << endl;
					cout << "----Menu----" << endl;
					cout << "1. Zarzadzaj klientami" << endl;
					cout << "2. Zarzadzaj Kwiatami" << endl;
					cout << "3. Zamow dostawe kwiatow do kwiaciarni" << endl;
					cout << "4. Wyloguj sie" << endl << endl;
					cout << "Wybrana operacja: ";
					cin >> wybor;
					switch (wybor)
					{
					case 1:
					{
						men:
						system("cls");
						cout << "Ktora z wymienionych operacji chcesz przeprowadzic?" << endl;
						cout << "1. Dodaj klienta" << endl;
						cout << "2. Usun klienta" << endl;
						cout << "3. Edytuj klienta" << endl;
						cout << "4. Wyswietl liste klientow" << endl;
						cout << "5. Powrot do menu" << endl << endl;
						cout << "Wybrana opcja: ";
						cin >> wybor;
						switch (wybor)
						{
						case 1:
						{
							dodaj_klient();
							break;
						}
						case 2 :
						{
							usun_klient();
							break;
						}
						case 3:
						{
							edytuj_klient();
							break;
						}
						case 4:
						{
							wyswietl_klient();
							break;
						}
						case 5:
						{
							break;
						}
						default:
						{
							cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
							system("pause");
							goto men;
						}
						}
						break;
					}
					case 2:
					{
						men1:
						system("cls");
						cout << "Ktora z wymienionych operacji chcesz przeprowadzic?" << endl;
						cout << "1. Dodaj kwiat" << endl;
						cout << "2. Usun kwiat" << endl;
						cout << "3. Edytuj kwiat" << endl;
						cout << "4. Wyswietl liste kwiatow" << endl;
						cout << "5. Powrot do menu" << endl << endl;
						cin >> wybor;
						switch (wybor)
						{
						case 1:
						{
							dodaj_kwiat();
							break;
						}
						case 2:
						{
							usun_kwiat();
							break;
						}
						case 3:
						{
							edytuj_kwiat();
							break;
						}
						case 4:
						{
							wyswietl_kwiat();
							break;
						}
						case 5:
						{
							break;
						}
						default:
						{
							cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
							system("pause");
							goto men1;
						}
						}
						break;
					}
					case 3:
					{
						dostawa();
						break;
					}
					case 4:
					{
						a = 0;
						break;
					}
					default:
					{
						cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
						system("pause");
						break;
					}
					}
				}
				
			}
			else
			{
				if (glowakli == NULL)
				{
					cout << "Administrator nie wprowadzil do systemu zadnego klienta. Prosze najpierw zalogowac sie na konto administratora." << endl;
					goto kon;
				}
				else
				{
					tempkli1 = glowakli;
					while (tempkli1 != NULL)
					{
						if (tempkli1->kliencik.login == log && tempkli1->kliencik.haslo == pass)
						{
							komuni = 1;
							break;
						}
						else
						{
							tempkli1 = tempkli1->next;
						}
					}
					if (komuni == 0)
					{
						cout << "Wprowadzone dame logowania sa niepoprawne. Prosze sprobowac sie zalogowac jeszcze raz." << endl;
						system("pause");
						goto loggo;
					}
					else
					{
						while (b)
						{
							bak:
							system("cls");
							cout << "Jestes zalogowany jako: ";
							tempkli1->kliencik.pokaz();
							cout << "----Menu----" << endl;
							cout << "1. Zamow kwiaty online" << endl;
							cout << "2. Sprawdz swoje dane" << endl;
							cout << "3. Wyloguj sie" << endl << endl;
							cout << "Wybrana operacja: ";
							cin >> wybor;
							switch (wybor)
							{
							case 1:
							{
								zmienna liczba = 0, wyb, ilo, prz = 0, zero = 0;
								float suma = 0, skl;
								tempkwia1 = glowakwia;
								tempkwia2 = NULL;
								tempkwia3 = NULL;
								if (glowakwia == NULL)
								{
									cout << "W kwiaciarni nie ma zadnych kwiatow. Prosze wrocic, jak kwiaty beda dostarczone do kwiaciarni." << endl;
									system("pause");
									goto bak;
								}
								while (tempkwia1 != NULL)
								{
									liczba++;
									if (tempkwia1->kwiatek.ilosc != 0)
									{
										zero = 1;
									}
									tempkwia1 = tempkwia1->next;
								}
								if (zero == 0)
								{
									cout << "W kwiaciarni nie ma zadnych kwiatow. Prosze wrocic, jak kwiaty beda dostarczone do kwiaciarni." << endl;
									system("pause");
									goto bak;
								}
								while (1)
								{
									zaku:
									system("cls");
									cout << "Ktory chcesz kwiat kupic?" << endl << endl;
									wyswietl_kwiat();
									cout << "0. Zakoncz zakupy" << endl << endl;
									cout << "Wybrana opcja: ";
									cin >> wyb;
									if (wyb == 0)
									{
										cout << "Skonczono zakupy. Kliknij enter, aby przejsc do wyswietlenia paragonu." << endl;
										system("pause");
										break;
									}
									else if (wyb < 0 || wyb > liczba)
									{
										cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
										system("pause");
										goto zaku;
									}
									else
									{
										tempkwia1 = glowakwia;
										for (int i = 1; i < wyb; i++)
										{
											tempkwia1 = tempkwia1->next;
										}
										cout << "W jakiej ilosc chcesz kupic ten kwiat?" << endl;
										cout << "Ilosc: ";
										cin >> ilo;
										cout << endl << endl;
										if (ilo > tempkwia1->kwiatek.ilosc)
										{
											cout << "Nie ma takiej ilosci tego kwiatka w kwiaciarni. Powrot do opcji wybrania kwiatka." << endl;
											cout << "Obecna ilosc tego kwiatka w kwiaciarni: " << tempkwia1->kwiatek.ilosc << endl;
											system("pause");
											goto zaku;
										}
										else if (ilo < 0)
										{
											cout << "Nie mozna kupic ujemnej ilosci kwiatow. Powrot do opcji wybrania kwiatka." << endl;
											cout << "Obecna ilosc tego kwiatka w kwiaciarni: " << tempkwia1->kwiatek.ilosc << endl;
											system("pause");
											goto zaku;
										}
										else
										{
											prz++;
											kwiatlist* nowy = new kwiatlist;
											if (tempkwia2 == NULL)
											{
												nowy->kwiatek.nazwa = tempkwia1->kwiatek.nazwa;
												nowy->kwiatek.cena = tempkwia1->kwiatek.cena;
												nowy->kwiatek.ilosc = ilo;
												tempkwia2 = nowy;
												tempkwia3 = nowy;
											}
											else
											{
												nowy->kwiatek.nazwa = tempkwia1->kwiatek.nazwa;
												nowy->kwiatek.cena = tempkwia1->kwiatek.cena;
												nowy->kwiatek.ilosc = ilo;
												tempkwia3->next = nowy;
												nowy->prev = tempkwia3;
												tempkwia3 = nowy;
											}
											tempkwia1 = glowakwia;
											while (tempkwia1->kwiatek.nazwa != tempkwia3->kwiatek.nazwa && tempkwia1->kwiatek.cena != tempkwia3->kwiatek.cena)\
											{
												tempkwia1 = tempkwia1->next;
											}
											tempkwia1->kwiatek.ilosc = tempkwia1->kwiatek.ilosc - tempkwia3->kwiatek.ilosc;
										}
									}
								}
								system("cls");
								cout << "Twoj paragon:" << endl << endl;
								cout << "Dane osoby zamawiajacej: " << endl << endl;
								tempkli1->kliencik.wyswietl();
								cout << "Pozycje na paragonie:" << endl << endl;
								while (tempkwia2 != NULL)
								{
									skl = tempkwia2->kwiatek.cena*tempkwia2->kwiatek.ilosc;
									if (skl != 0)
									{
										cout << tempkwia2->kwiatek.nazwa << "			" << tempkwia2->kwiatek.ilosc << " * " << tempkwia2->kwiatek.cena << "		" << skl << endl;
										suma = suma + skl;
									}
									tempkwia2 = tempkwia2->next;
								}
								tempkwia2 = tempkwia3;
								for (int i = 1; i <= prz; i++)
								{
									tempkwia2 = tempkwia2->prev;
									delete tempkwia3;
									tempkwia3 = tempkwia2;
								}
								cout << endl;
								cout << "						SUMA: " << suma << endl << endl;
								system("pause");
								if (suma != 0)
								{
									tempkli1->kliencik.dodajzam(tempkli1->zmow);
								}
								break;
							}
							case 2:
							{
								tempkli1->kliencik.wyswietl();
								system("pause");
								break;
							}
							case 3:
							{
								b = 0;
								break;
							}
							default:
							{
								cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
								system("pause");
								break;
							}
							}
						}
					}
				}
			}
			cout << "Wylogowano pomyslnie" << endl;
		kon:
			system("pause");
			break;
		}
		case 2:
		{
			zakup_na_miejscu();
			system("pause");
			break;
		}
		case 3:
		{
			n = 0;
			break;
		}
		default:
		{
			cout << "Wybrano niepoprawna operacje. Prosze dokonac wyboru jeszcze raz." << endl;
			system("pause");
			break;
		}
		}
	}
	cout << "Dziekujemy za skorzystanie z oprogramowania do oblugi kwiaciarni. Zyczymy milego dnia :)" << endl;
	system("pause");
	return 0;
}
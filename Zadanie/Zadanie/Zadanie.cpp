#include "pch.h"

using namespace std;

void Quick_Sort(double tab[],int poczatek,int koniec)
{
	int i = poczatek;
	int j = koniec;
	int srodek = tab[(poczatek + koniec) / 2];

	do
	{
		while (tab[i] < srodek)
			i++;
		while (tab[j] > srodek)
			j--;

		if (i <= j)
		{
			swap(tab[i],tab[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (poczatek < j) Quick_Sort(tab, poczatek, j);
	if (koniec > i) Quick_Sort(tab, i, koniec);
}

void Scalanie(double)
{

}

void Introspekcja(double)
{

}

int main()
{

	srand(time(NULL));

	int rozmiar;
	cout << "Podaj rozmiar tablicy" << endl;
	cin >> rozmiar;

	Tablica tablica;


	/*// 1 SPOSOB ///////////////////////////////////////////////////////
	tablica.Tworz_Tablice(rozmiar);
	
	for (int i = 0; i < rozmiar; i++)
	{
		cout << *(tablica.tab + i) << " ";
	}
	cout << "KOLEJNE TESTY" << endl;

	cout << tablica.tab[0] << " " << tablica.tab[1]<<endl;

	tablica.Usun_Tablice(tablica.tab, tablica.tab_rand);
	cout << "Usunalem tablice" << endl;

	cout << "UWAGA!!!!!" << endl;*/

	// 2 SPOSOB /////////////////////////////////////////////////////////

	tablica.Tworz_Tablice2(rozmiar);
	cout << endl << endl;
	
	//tablica.Przepisz_wiersz(tablica.tab2, tablica.tab, rozmiar, 0);
	

	/*
	int *tab;
	tab = new int[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = rand();
		cout << tab[i] << " ";
	}
	cout << endl;

	Quick_Sort(tab, 0, rozmiar - 1);

	for (int i = 0; i < rozmiar; i++)
	{
		cout << tab[i] << " ";
	}
	*/ // dzialajacy algorytm quicsort
}

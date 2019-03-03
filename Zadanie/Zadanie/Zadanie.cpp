#include "pch.h"

using namespace std;

double* pom;

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

void Scalanie(double tab[], int poczatek, int srodek, int koniec)
{
	//double* pom;
	//pom = new double[koniec + 1];

	for (int i = poczatek; i <= koniec; i++)
	{
		pom[i] = tab[i];
	}

	int k = srodek + 1;
	int j = poczatek;

	for (int i = poczatek; i <= koniec; i++)
	{
		if (j <= srodek)
		{
			if (k <= koniec)
			{
				if (pom[k] < pom[j])
				{
					tab[i] = pom[k++];
				}
				else
				{
					tab[i] = pom[j++];
				}
			}
			else
			{
				tab[i] = pom[j++];
			}
		}
		else
		{
			tab[i] = pom[k++];
		}
	}
}

void Dzielenie(double tab[], int poczatek, int koniec)
{
	int srodek = (poczatek + koniec) / 2;

	if (tab[poczatek] != tab[koniec])
	{
		Dzielenie(tab, poczatek, srodek);
		Dzielenie(tab, srodek + 1, koniec);
	}

	Scalanie(tab, poczatek, srodek, koniec);
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
	pom = new double[rozmiar];

	Tablica tablica;
	double* tab1 = new double[rozmiar];
	double* tab2 = new double[rozmiar];
	double* tab3 = new double[rozmiar];

	tablica.Tworz_Tablice_Wiktor(rozmiar);
	tablica.Przepisz_wiersz(tab1, tablica.tab, rozmiar);
	tablica.Przepisz_wiersz(tab2, tablica.tab, rozmiar); // Tworzenie kopi tablicy ktore beda uzywane do testow
	tablica.Przepisz_wiersz(tab3, tablica.tab, rozmiar);
	   	  
	clock_t start;
	double dlugosc;
	start = clock();

	for (int k = 0; k < 100; k++)
	{
		Quick_Sort(tab1, 0, rozmiar - 1);
	}

	tablica.Usun_Tablice(tab1); // Zwolnienie pamięci

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

	start = clock();

	for (int k = 0; k < 100; k++)
	{
		Dzielenie(tab2, 0, rozmiar - 1);

	}
	tablica.Usun_Tablice(tab2); // Zwolnienie pamięci

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;


}

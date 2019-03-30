#include <iostream>
#include "sortowanie.h"
#include "pch.h"
#include <ctime>

using namespace std;

template<typename T>
void Sortowanie<T>::Quick_Sort(T tab[], int poczatek, int koniec)
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
			swap(tab[i], tab[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (poczatek < j) Quick_Sort(tab, poczatek, j);
	if (koniec > i) Quick_Sort(tab, i, koniec);
}

template<typename T>
void Sortowanie<T>::Scalanie(T tab[],T pom[], int poczatek, int srodek, int koniec)
{
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

template<typename T>
void Sortowanie<T>::Dzielenie(T tab[],T pom[], int poczatek, int koniec)
{
	int srodek = (poczatek + koniec) / 2;

	if (tab[poczatek] != tab[koniec])
	{
		Dzielenie(tab,pom, poczatek, srodek);
		Dzielenie(tab,pom, srodek + 1, koniec);
	}

	Scalanie(tab,pom, poczatek, srodek, koniec);
}

template<typename T>
void Sortowanie<T>::Shell(T tab[], int rozmiar)
{
	for (int k = rozmiar / 2; k > 0; k /= 2)
	{
		for (int i = k; i < rozmiar; i += 1)
		{
			T pom = tab[i];

			int j;
			for (j = i; j >= k && tab[j - k] > pom; j -= k)
			{
				tab[j] = tab[j - k];
			}
			tab[j] = pom;
		}
	}
}

template<typename T>
void Sortowanie<T>::Odwracanie(T tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar / 2; i++)
	{
		swap(tab[i], tab[rozmiar - 1 - i]);
	}
}

template<typename T>
void Sortowanie<T>::ZapisQuick(T tab[], int rozmiar)
{
	string tekst;
	fstream plik;

	plik.open("Liczby_Quick.txt", ios::out | ios::app);
	if (plik.good())
	{
		for (int i = 0; i < rozmiar; i++)
		{
			plik << tab[i] << " ";
		}

		plik << endl << " Nastepna tablica" << endl;
		plik.close();
	}


}

template<typename T>
void Sortowanie<T>::ZapisMerge(T tab[], int rozmiar)
{
	string tekst;
	fstream plik;

	plik.open("Liczby_Merge.txt", ios::out | ios::app);
	if (plik.good())
	{
		for (int i = 0; i < rozmiar; i++)
		{
			plik << tab[i] << " ";
		}

		plik << endl << " Nastepna tablica" << endl;
		plik.close();
	}


}

template<typename T>
void Sortowanie<T>::ZapisShell(T tab[], int rozmiar)
{
	string tekst;
	fstream plik;

	plik.open("Liczby_Shell.txt", ios::out | ios::app);
	if (plik.good())
	{
		for (int i = 0; i < rozmiar; i++)
		{
			plik << tab[i] << " ";
		}

		plik << endl << " Nastepna tablica" << endl;
		plik.close();
	}


}

template class Sortowanie<int>;
template class Sortowanie<double>;
template class Sortowanie<float>;

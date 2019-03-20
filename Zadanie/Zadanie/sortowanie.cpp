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
	
//	pom = new T[koniec + 1];

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
{/*
	for (int gap = rozmiar / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < rozmiar; i += 1)
		{
			T pom = new T[rozmiar];
			pom = tab[i];

			int j;
			for (j = i; j >= gap && tab[j - gap] > pom; j -= gap)
			{
				tab[j] = tab[j - gap];
			}
			tab[j] = pom;
		}
	}*/
}

template class Sortowanie<int>;
template class Sortowanie<double>;
template class Sortowanie<float>;

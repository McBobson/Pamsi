#include <iostream>
#include "Tablica.h"
#include "pch.h"
#include <ctime>

using namespace std;

template<typename T>
void Tablica<T>::Usun_Tablice(T* tab)
{
	delete[] tab;
}

template<typename T>
void Tablica<T>::Przepisz_wiersz(T *tab,T* tab2,int roz)
{
	for (int j = 0; j < roz; j++)
	{
		tab[j] = tab2[j];
	}
	
}

template<typename T>
void Tablica<T>::Tworz_Tablice(int rozmiar)
{
	tab = new T[rozmiar];


	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = rand() % rozmiar + 1;
	}
}

template<typename T>
void Tablica<T>::Tworz_Tablice_Pom(int rozmiar)
{
	tab1 = new T[rozmiar];
}

template<typename T>
void Tablica<T>::Tworz_Tablice_PomTest(int rozmiar)
{
	tabpom = new T[rozmiar];
}

template<typename T>
void Tablica<T>::Wypelnij_Tablice(T *tab)
{
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = rand() % rozmiar + 1;
	}
}

template class Tablica<int>;
template class Tablica<double>;
template class Tablica<float>;

#include <iostream>
#include "Tablica.h"
#include "pch.h"
#include <ctime>

using namespace std;

void Tablica::Usun_Tablice(double* tab)
{
	delete[] tab;
}

void Tablica::Przepisz_wiersz(double *tab,double* tab2,int roz)
{
	for (int j = 0; j < roz; j++)
	{
		tab[j] = tab2[j];
	}
	
}

void Tablica::Tworz_Tablice_Wiktor(int rozmiar)
{
	tab = new double[rozmiar];


	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = rand() % rozmiar + 1;
	}
}

void Tablica::Wypelnij_Tablice(double *tab)
{
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = rand() % rozmiar + 1;
	}
}


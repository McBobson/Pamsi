#include <iostream>
#include "Tablica.h"
#include "pch.h"
#include <ctime>

using namespace std;

/*
void Tablica::Tworz_Tablice(int rozmiar)
{
	tab = new double[rozmiar];
	//tab_rand = new double[rozmiar];

	for (int i = 0; i < 100; i++)
	{
		tab_rand = new double[rozmiar];
		for (int j = 0; j < rozmiar; j++)
		{
			tab_rand[j] = rand();
			cout << tab_rand[j]<<" ";
		}
		cout << endl;
		//cout << "TETSTST" << "    ";
		//cout << *tab_rand;
		tab[i] = *tab_rand;
	}
}*/

void Tablica::Tworz_Tablice2(int rozmiar)
{
	licznik = 0;
	tab2 = new double *[100];

	for (int i = 0; i < 100; i++)
	{
		tab2[i] = new double[rozmiar];
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			tab2[i][j] = rand()%rozmiar+1;
			cout << tab2[i][j]<<" ";
		}
		cout << endl;
		licznik++;
	}
}

void Tablica::Usun_Tablice(double* tab, double* tab_rand)
{
	delete[] tab;
	delete[] tab_rand;
}

void Tablica::Usun_Tablice2(double** tab)
{
	for (int i = 0; i < 100; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}

void Tablica::Przepisz_wiersz(double** tab2,double* tab,int roz,int wiersz)
{
	for (int j = 0; j < roz; j++)
	{
		tab[j] = tab2[wiersz][j];
	}
	
}
#ifndef MACIERZ_H
#define MACIERZ_H

#include "pch.h"

using namespace std;

class Macierz {

	int Wierzcholki = 0 , krawedzie = 0, Gestosc = 0;

public:

	int *cena;
	int *droga;
	bool *spt;

	int **tablica;

	Macierz(int, float);

	int Zwroc_Wierz()
	{
		return Wierzcholki;
	}

	int Zwroc_Kraw()
	{
		return krawedzie;
	}

	void polacz();

	void Usun();

};


Macierz::Macierz(int W, float G)
{
	Wierzcholki = W;
	krawedzie = (G*W*(W - 1)) / 200;
	Gestosc = G;

	tablica = new int *[W];

	for (int i = 0; i < W; i++)
	{
		tablica[i] = new int[W];
	}

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < W; j++)
		{
			tablica[i][j] = 0;
		}
	}
}

void Macierz::polacz() {
	
	int pom = krawedzie;

	if (Gestosc < 100) 
	{
		while (pom) 
		{
			int i = rand() % Wierzcholki;
			int j = rand() % Wierzcholki;

			if (j > i && !tablica[i][j]) 
			{
				pom--;
				tablica[i][j] = 1 + rand() % 10;
			}
			else if (i > j && !tablica[j][i]) 
			{
				pom--;
				tablica[j][i] = 1 + rand() % 10;
			}
		}
	}
	else {
		for (int i = 0; i < Wierzcholki; i++)
		{
			for (int j = 0; j < Wierzcholki; j++)
			{
				if (j > i)
				{
					tablica[i][j] = 1 + rand() % 10;
				}
			}
		}
	}
}

void Macierz::Usun()
{
	for (int i = 0; i < Wierzcholki; i++)
	{
		delete[] tablica[i];
	}

	delete[] tablica;
}

int minDyst_M_K(Macierz& M, int W)
{
	int min = INF;
	int min_index;

	for (int i = 0; i < W; i++)
	{
		if (M.spt[i] == false && M.cena[i] <= min)
		{
			min = M.cena[i];
			min_index = i;
		}
	}

	return min_index;
}

void Djikstra_Macierz_K(Macierz& M, int W, int Wst)
{
	M.cena = new int[W];
	M.droga = new int[W];
	M.spt = new bool[W];

	for (int i = 0; i < W; i++)
	{
		M.cena[i] = INF;
		M.spt[i] = false;
		M.droga[i] = -1;
	}

	M.cena[Wst] = 0;

	for (int i = 0; i < W - 1; i++)
	{
		int u = minDyst_M_K(M, W);
		M.spt[u] = true;

		for (int j = 0; j < W; j++)
		{
			if (!M.spt[j] && M.tablica[u][j] && M.cena[u] != INF && M.cena[u] + M.tablica[u][j] < M.cena[j])
			{
				M.cena[j] = M.cena[u] + M.tablica[u][j];
				M.droga[j] = u;
			}
		}
	}

	delete M.cena;
	delete M.droga;

	//Wyswietl_Macierz(M, W);
}

ostream& operator << (ostream& wyjscie, Macierz& M) {
	wyjscie << endl << "    ";
	for (int i = 0; i < M.Zwroc_Wierz(); i++)
		wyjscie << setw(3) << i;

	wyjscie << endl;
	wyjscie << "  ";
	for (int i = 0; i < M.Zwroc_Wierz() + 1; i++)
		wyjscie << setw(3) << "_";

	wyjscie << endl;
	for (int i = 0; i < M.Zwroc_Wierz(); i++) {
		wyjscie << setw(3) << i << "|";
		for (int j = 0; j < M.Zwroc_Wierz(); j++)
			wyjscie << setw(3) << M.tablica[i][j];
		wyjscie << endl;
	}
	return wyjscie;
}










#endif 


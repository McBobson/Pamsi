#ifndef MACIERZ_H
#define MACIERZ_H

#include "pch.h"

using namespace std;

class Macierz {

	int Wierzcholki = 0 , krawedzie = 0;

	//int **tablica;

public:

	Macierz(int, int);
	int Zwroc_Wierz()
	{
		return Wierzcholki;
	}

	int Zwroc_Kraw()
	{
		return krawedzie;
	}

	int **tablica;

	void polacz();
	

};


Macierz::Macierz(int W, int G)
{
	Wierzcholki = W;
	krawedzie = (G*W*(W - 1)) / 200;

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

	/*	for (int i = 0; i < krawedzie; i++)
	{
		int x = rand() % W;
		int y = rand() % W;

		int waga = rand() % 10 + 1;

		if (tablica[x][y] == 0)
		{
			tablica[x][y] = waga;
		}

		if (tablica[y][x] == 0)
		{
			tablica[y][x] = waga;
		}
	
	}
	*/
}


void Macierz::polacz() {
	for (int i = 0; i < krawedzie; i++)
	{
		int x = rand() % Wierzcholki;
		int y = rand() % Wierzcholki;

		int waga = rand() % 10 + 1;

		if (tablica[x][y] == 0)
		{
			tablica[x][y] = waga;
		}

		if (tablica[y][x] == 0)
		{
			tablica[y][x] = waga;
		}

	}
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


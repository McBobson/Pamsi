#ifndef DJIKSTRA_H
#define DJIKSTRA_H
#include "pch.h"
#include "Lista.h"
#include "Macierz.h"

using namespace std;

class Djikstra
{
public:

	Lista *p;

	void Wyswietl_Lista(Lista&, int);
	void Wyswietl_Macierz(Macierz&, int);
	int minDyst_M(Macierz&, int);
	int minDyst_L(Lista&, int);

	void Djikstra_Lista(Lista&, int, int);
	void Djikstra_Macierz(Macierz&, int, int);

	float Czas_Macierz(Macierz&, int, int);


};

void Djikstra::Djikstra_Lista(Lista& L, int W, int Wst)
{
	L.cena = new int[W];
	L.droga = new int[W];
	L.spt = new bool[W];

	for (int i = 0; i < W; i++)
	{
		L.cena[i] = INF;
		L.spt[i] = false;
		L.droga[i] = -1;
	}

	L.cena[Wst] = 0;

	for (int i = 0; i < W - 1; i++)
	{
		int u = minDyst_L(L, W);
		L.spt[u] = true;

		for (p = L.A[u]; p; p=p->next)
		{
			if (!L.spt[p->v] && p->weight && L.cena[u] != INF && L.cena[u] + p->weight < L.cena[p->v])
			{
				L.cena[p->v] = L.cena[u] + p->weight;
				L.droga[p->v] = u;
			}
		}
	}

	delete[] L.cena;
	delete[] L.droga;
	delete[] L.spt;

	//Wyswietl_Lista(L, W);
}

int Djikstra::minDyst_L(Lista& L, int W)
{
	int min = INF;
	int min_index;

	for (int i = 0; i < W; i++)
	{
		if (L.spt[i] == false && L.cena[i] <= min)
		{
			min = L.cena[i];
			min_index = i;
		}
	}

	return min_index;
}

int Djikstra::minDyst_M(Macierz& M, int W)
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

void Djikstra::Djikstra_Macierz(Macierz& M, int W, int Wst)
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
		int u = minDyst_M(M, W);
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
	//Wyswietl_Macierz(M, W);

	delete[] M.cena;
	delete[] M.droga;
	delete[] M.spt;
}

void Djikstra::Wyswietl_Lista(Lista& L, int W)
{
	int *S;
	S = new int[W];

	int pom = 0;

	for (int i = 0; i < W; i++)
	{
		cout << i << ": ";
		for (int j = i; j != -1; j = L.droga[j])
		{
			S[pom++] = j;
		}

		while (pom)
		{
			cout << S[--pom] << " ";
		}
		cout << "$" << L.cena[i] << endl;
	}

	delete[] S;

}

void Djikstra::Wyswietl_Macierz(Macierz& M,int W)
{
	int *S;
	S = new int[W];

	int pom = 0;

	for (int i = 0; i < W; i++)
	{
		cout << i << ": ";
		for (int j = i; j!=-1; j = M.droga[j])
		{
			S[pom++] = j;
		}

		while (pom)
		{
			cout << S[--pom] << " ";
		}
		cout << "$" << M.cena[i] << endl;
	}

	delete[] S;
}

float Djikstra::Czas_Macierz(Macierz& M, int W, int Wst)
{
	clock_t start, stop;
	float czas;
	start = clock();
	Djikstra_Macierz(M, W, Wst);
	stop = clock();
	czas = (float)(stop - start) / CLOCKS_PER_SEC;
	return czas;

}




#endif // !DJIKSTRA_H
#pragma once

#ifndef LISTA_H
#define LISTA_H

#include "pch.h"

using namespace std;

class Lista{

public:

	Lista * next;
	int v;
	int weight;

	// KONIEC STRUKTUR W KLASIE

	int rozmiar=0; 
	
	int n, m, i, v1, v2;

	Lista **A;
	Lista *p, *r;

	int *cena; //usuwamy na koncu
	int *droga; //usuwamy na koncu
	bool *spt; // usuwamy na koncu

	int **Tablica_Flag; // usuwamy na koncu

	int W = 0, K = 0;

	void Usun_Liste(); // OK 

	void Tworz_Liste(int, float);	// OK

	void Wypisz(); // OK 

	int Rozmiar(int); // OK 

};

int Lista::Rozmiar(int WSt)
{
	p = A[WSt];

	rozmiar = 0;

	while (p)
	{
		rozmiar++;
		p = p->next;
	}
	//rozmiar--;

	return rozmiar;
}

void Lista::Tworz_Liste(int Wierzcholki, float G)
{
	W = Wierzcholki;
	K = (G*W*(W - 1)) / 200;

	A = new Lista *[Wierzcholki];

	for (int i = 0; i < Wierzcholki; i++)
	{
		A[i] = NULL;
	}

	Tablica_Flag = new int *[W];

	for (int i = 0; i < W; i++)
	{
		Tablica_Flag[i] = new int[W];
	}

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < W; j++)
		{
			Tablica_Flag[i][j] = 0;
		}
	}

	int pom = K;
	int waga;
		
		if (G < 100)
		{
			while (pom)
			{
				v1 = rand() % W;
				v2 = rand() % W;
				waga = rand() % 10 + 1;

				if (v1 > v2 && !Tablica_Flag[v2][v1])
				{
					p = new Lista;
					p->v = v1;
					p->weight = waga;
					p->next = A[v2];
					A[v2] = p;
					Tablica_Flag[v2][v1] = 1;
					pom--;
				}

				if (v2 > v1 && !Tablica_Flag[v1][v2])
				{
					p = new Lista;
					p->v = v2;
					p->weight = waga;
					p->next = A[v1];
					A[v1] = p;
					Tablica_Flag[v1][v2] = 1;
					pom--;
				}
			}
		}
		else
		{
			for (int i = 0; i < W; i++)
			{
				for (int j = 0; j < W; j++)
				{
					if (j > i)
					{
						waga = rand() % 10 + 1;
						p = new Lista;
						p->v = j;
						p->weight = waga;
						p->next = A[i];
						A[i] = p;
						Tablica_Flag[i][j] = 1;
					}
				}
			}
		}
}

void Lista::Wypisz()
{
	for (i = 0; i < W; i++)
	{
		cout << "A[" << i << "] =";
		p = A[i];
		while (p)
		{
			cout << setw(3) << p->v;
			p = p->next;
		}
		cout << endl;
	}

	cout << endl << "WAGI" << endl;
	for (i = 0; i < W; i++)
	{
		cout << "A[" << i << "] =";
		p = A[i];
		while (p)
		{
			cout << setw(3) << p->weight;
			p = p->next;
		}
		cout << endl;
	}
}

void Lista::Usun_Liste()
{
	for (int i = 0; i < W; i++)
	{
		p = A[i];
		while (p)
		{
			r = p;
			p = p->next;
			delete r;
		}
	}
	delete[] A;
	

	for (int i = 0; i < W; i++)
	{
		delete[] Tablica_Flag[i];
	}

	delete[] Tablica_Flag;
}



#endif

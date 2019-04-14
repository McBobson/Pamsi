#ifndef LISTA_H
#define LISTA_H

#include "pch.h"

using namespace std;


class Lista{

public:
	Lista * next;
	int v;

	int n, m, i, v1, v2;
	Lista ** A;
	Lista *p, *r;
	int W, K;

	void Tworz_Liste(int Wierzcholki, int Krawedzie)
	{
		W = Wierzcholki;
		K = Krawedzie;

		A = new Lista *[Wierzcholki];

		for (int i = 0; i < Wierzcholki; i++)
		{
			A[i] = 0;
		}

		for (int i = 0; i < Krawedzie; i++)
		{
			v1 = rand() % Wierzcholki;
			v2 = rand() % Wierzcholki;

			p = new Lista;
			p->v = v2;
			p->next = A[v1];
			A[v1] = p;

			p = new Lista;    
			p->v = v1;
			p->next = A[v2];
			A[v2] = p;
		}
	}

	void Wypisz()
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
	}

};

#endif

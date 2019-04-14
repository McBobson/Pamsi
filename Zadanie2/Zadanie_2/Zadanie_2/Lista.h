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
	int W = 0, K = 0;

	void Usun_Liste();

	void Tworz_Liste(int, float);	

	void Wypisz();
	


};

void Lista::Tworz_Liste(int Wierzcholki, float G)
{
	W = Wierzcholki;
	K = (G*W*(W - 1)) / 200;

	A = new Lista *[Wierzcholki];

	for (int i = 0; i < Wierzcholki; i++)
	{
		A[i] = 0;
	}

	/*
	for (int i = 0; i < Krawedzie; i++)
	{
		v1 = rand() % Wierzcholki;
		v2 = rand() % Wierzcholki;

		p = new Lista;
		p->v = v2;
		p->next = A[v1];
		A[v1] = p;

		/*
		p = new Lista;
		p->v = v1;
		p->next = A[v2];
		A[v2] = p;
	}*/

	int pom = K;
	cout << endl << pom << endl;

	if (G < 100)
	{

		while (pom)
		{
			int v1 = rand() % W;
			int v2 = rand() % W;

			//cout << "SZUKAM KRAWEDZI" << endl;

			if (v2 > v1 && !A[v1])
			{
				pom--;


				int waga = 1 + rand() % 10;
				p = new Lista;
				p->v = waga;
				p->next = A[v1];
				A[v1] = p;

				p = new Lista;
				p->v = v2;
				p->next = A[v1];
				A[v1] = p;

				cout << "PIERWSZY IFFF" << endl;

			}

			else if (v1 > v2 && !A[v2])
			{
				pom--;


				int waga = 1 + rand() % 10;
				p = new Lista;
				p->v = waga;
				p->next = A[v2];
				A[v2] = p;


				p = new Lista;
				p->v = v1;
				p->next = A[v2];
				A[v2] = p;

				cout << "DRUGI IFFFF" << endl;
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

					int waga = 1 + rand() % 10;
					p = new Lista;
					p->v = waga;
					p->next = A[i];
					A[i] = p;

					p = new Lista;
					p->v = j;
					p->next = A[i];
					A[i] = p;

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
}

void Lista::Usun_Liste()
{
	for (int i = 0; i < W; i++)
	{
		p = A[i];
		while (p)
		{
			r = p;
			p->next;
			delete r;
		}
	}
	delete[] A;
}

#endif

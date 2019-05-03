#include "pch.h"
#include "Macierz.h"
#include "Lista.h"
#include "Djikstra.h"

using namespace std;

void Test(int W, float G) 
{
	int rozmiar = 100;

	float *tab_czas = new float[rozmiar];
	clock_t start;
	float czas;
	Djikstra D;

	for (int i = 0; i < rozmiar; i++) 
	{
		Macierz M(W, G);
		M.polacz();

		start = clock();
		D.Djikstra_Macierz(M, W, 0);
		czas = (clock() - start) / (double)CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << czas<<endl;
		//cout << tab_czas[i] << endl;

		M.Usun();
	}

	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	//cout << "(M) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Sredni czas: " << tab_czas[rozmiar/2] << endl;
	//cout << "(M) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar-1] << endl;

	//cout << endl;
	
	
	for (int i = 0; i < rozmiar; i++)
	{
		Lista L;
		L.Tworz_Liste(W, G);

		start = clock();
		D.Djikstra_Lista(L, W, 0);
		czas = (clock() - start) / (double)CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << czas << endl;
		//cout << tab_czas[i] << endl;

		L.Usun_Liste();

	}
	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	//cout << "(L) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(L) W: " << W << " Gestosc: " << G << " Sredni czas: " << tab_czas[rozmiar / 2] << endl;
	//cout << "(L) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar - 1] << endl;
	
	delete[] tab_czas;
	

}

int main()
{
	srand(time(NULL));	

	cout << "ALGORYTM DJIKSTRY ZNAJDUJACY NAJKROTSZE DROGI DO WSZYSTKICH WIERZCHOLKOW" << endl;

	int gestosc;
	gestosc = 25;

	for (int i = 0; i < 4; i++)
	{
		Test(500, gestosc);
		gestosc += 25;
	}

	gestosc = 25;

	for (int i = 0; i < 4; i++)
	{
		Test(1000, gestosc);
		gestosc += 25;
	}

	gestosc = 25;

	for (int i = 0; i < 4; i++)
	{
		Test(2000, gestosc);
		gestosc += 25;
	}

	gestosc = 25;

	for (int i = 0; i < 4; i++)
	{
		Test(3000, gestosc);
		gestosc += 25;
	}
	
	gestosc = 25;

	for (int i = 0; i < 4; i++)
	{
		Test(5000, gestosc);
		gestosc += 25;
	}

	return 0;

}

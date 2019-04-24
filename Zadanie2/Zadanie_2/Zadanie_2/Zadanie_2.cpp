#include "pch.h"
#include "Macierz.h"
#include "Lista.h"
#include "Djikstra.h"

using namespace std;

void Test(int W, float G) 
{
	 int rozmiar = 100;

	float *tab_czas = new float[rozmiar];
	clock_t start,stop,start1,stop1;
	float czas;

	start1 = clock();

	for (int i = 0; i < rozmiar; i++) 
	{
		Macierz M(W, G);
		Djikstra D;
		M.polacz();

		start = clock();
		D.Djikstra_Macierz(M, W, 0);
		czas = (clock() - start) / (double)CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << tab_czas[i] << endl;

		M.Usun();
	}
	cout << (clock() - start1) / (double)CLOCKS_PER_SEC << endl;;

	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	//cout << "(M) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Sredni czas: " << tab_czas[rozmiar/2] << endl;
	//cout << "(M) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar-1] << endl;

	//cout << endl;

	start1 = clock();

	for (int i = 0; i < rozmiar; i++)
	{
		Lista L;
		L.Tworz_Liste(W, G);
		Djikstra D;

		start = clock();
		D.Djikstra_Lista(L, W, 0);
		stop = clock();
		czas = (float)(stop - start) / CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << tab_czas[i] << endl;

		L.Usun_Liste();

	}

	cout << (clock() - start1) / (double)CLOCKS_PER_SEC << endl;;
	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	//cout << "(L) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(L) W: " << W << " Gestosc: " << G << " Sredni czas: " << tab_czas[rozmiar / 2] << endl;
	//cout << "(L) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar - 1] << endl;

	delete[] tab_czas;
	

}

void Test_Bez_Klas(int W, int G)
{
	const int rozmiar = 100;

	float tab_czas[rozmiar];
	clock_t start;
	float czas;

	start = clock();
	for (int i = 0; i < rozmiar; i++)
	{
		Macierz M(W, G);
		//Djikstra D;
		M.polacz();

		start = clock();
		//D.Djikstra_Macierz(M, W, 0);

		Djikstra_Macierz_K(M, W, 0);
		czas = (clock() - start) / (double)CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << tab_czas[i] << endl;

		M.Usun();
	}

	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Średni czas: " << tab_czas[rozmiar / 2] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar - 1] << endl;

	cout << endl << endl;

	/*

	for (int i = 0; i < rozmiar; i++)
	{
		Lista L;
		L.Tworz_Liste(W, G);
		Djikstra D;

		start = clock();
		D.Djikstra_Lista(L, W, 0);
		stop = clock();
		czas = (float)(stop - start) / CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << tab_czas[i] << endl;

		L.Usun_Liste();

	}

	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Średni czas: " << tab_czas[rozmiar / 2] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar - 1] << endl;
	*/
}


int main()
{
	srand(time(NULL));	

	cout << "ALGORYTM DJIKSTRY ZNAJDUJACY NAJKROTSZE DROGI DO WSZYSTKICH WIERZCHOLKOW" << endl;

	int gestosc, LWierzcholkow;
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
		Test(5000, gestosc);
		gestosc += 25;
	}
	
	gestosc = 25;

	for (int i = 0; i < 4; i++)
	{
		Test(10000, gestosc);
		gestosc += 25;
	}

	


	return 0;

}

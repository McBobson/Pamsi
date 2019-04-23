#include "pch.h"
#include "Macierz.h"
#include "Lista.h"
#include "Djikstra.h"

using namespace std;

void Test(int W, float G) 
{
	const int rozmiar = 100;

	float tab_czas[rozmiar];
	clock_t start,stop;
	float czas;

	for (int i = 0; i < rozmiar; i++) 
	{
		Macierz M(W, G);
		Djikstra D;
		M.polacz();

		start = clock();
		D.Djikstra_Macierz(M, W, 0);
		stop = clock();
		czas = (float)(stop - start) / CLOCKS_PER_SEC;
		tab_czas[i] = czas;
		//cout << tab_czas[i] << endl;

		M.Usun();
	}

	sort(tab_czas, tab_czas + rozmiar);
	cout << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Min czas: " << tab_czas[0] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Średni czas: " << tab_czas[rozmiar/2] << endl;
	cout << "(M) W: " << W << " Gestosc: " << G << " Max czas: " << tab_czas[rozmiar-1] << endl;

	cout << endl << endl;

	

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
	

}


int main()
{
	srand(time(NULL));	

	Test(500,80);


	return 0;

}

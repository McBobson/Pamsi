#include "pch.h"
#include "Macierz.h"
#include "Lista.h"
#include "Djikstra.h"

using namespace std;

const int maxn = 4;

int main()
{

	srand(time(NULL));	

	/*
	Lista L;
	L.Tworz_Liste(3,100);
	L.Wypisz();

	cout << endl << endl << endl;

	cout << "DJIKSTRA" << endl;

	Djikstra D(3);
	D.Djikstra_Lista(L);
	D.Wyswietl();
	*/

	Macierz M(4, 75);
	M.polacz();
	cout << M;

	Djikstra D;

	D.Djikstra_Macierz(M, 4, 0);

	cout << endl << "KURWNIE" << endl << endl;

	Lista L;
	L.Tworz_Liste(4, 75);
	L.Wypisz();
	cout << endl;
	D.Djikstra_Lista(L, 4, 0);
	
	/*
	Lista L2;
	L2.Tworz_Liste(3, 3);
	L2.Wypisz();

	Lista L3;
	L3.Tworz_Liste(3, 3);
	L3.Wypisz();

	Lista L4;
	L4.Tworz_Liste(3, 3);
	L4.Wypisz();
	*/
	


	//M.Usun();
	//L.Usun_Liste();

	return 0;

}

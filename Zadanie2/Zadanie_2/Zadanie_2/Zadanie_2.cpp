#include "pch.h"
#include "Macierz.h"
#include "Lista.h"

using namespace std;

const int maxn = 4;

int main()
{

	srand(time(NULL));
		
	Macierz M(4,50);
	M.polacz();

	cout << M;

	cout << endl << endl;

	cout << M.Zwroc_Kraw()<<endl;
	

	
	Lista L;
	L.Tworz_Liste(4,50);
	L.Wypisz();
	
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

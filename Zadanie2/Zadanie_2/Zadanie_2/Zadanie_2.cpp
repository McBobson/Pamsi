#include "pch.h"
#include "Macierz.h"
#include "Lista.h"

using namespace std;

const int maxn = 4;

int main()
{

	srand(time(NULL));
	/*
	int A[maxn][maxn];

	int x,y;
	
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			A[i][j] = 0;
		}
	}

	int krawedz;

	cout << "Wprowadz ilosc krawedzi" << endl;
	cin >> krawedz;
	int waga;

	for (int i = 0; i < krawedz; i++)
	{
		cout << "Wprowadz elementy do polaczenia:" << endl;
		cin >> x >> y;
		cout << "Wrowadz wage połaczenia:" << endl;
		cin >> waga;
		A[x][y] = waga;
		A[y][x] = waga;
		
	}

	*/

	/*
	Macierz M(3,100);

	cout << M;

	//cout << "Macierz" << endl;
	//cout << "    ";

	cout << endl << endl;

	cout << M.Zwroc_Kraw();
	*/

	Lista L;
	L.Tworz_Liste(3, 3);
	L.Wypisz();

	Lista L2;
	L2.Tworz_Liste(3, 3);
	L2.Wypisz();

	Lista L3;
	L3.Tworz_Liste(3, 3);
	L3.Wypisz();

	Lista L4;
	L4.Tworz_Liste(3, 3);
	L4.Wypisz();

	

	return 0;

}

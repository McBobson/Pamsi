#include "pch.h"

using namespace std;

void Quick_Sort(double)
{

};

void Scalanie(double)
{

};

void Introspekcja(double)
{

};

int main()
{

	srand(time(NULL));

	int rozmiar;
	cout << "Podaj rozmiar tablicy" << endl;
	cin >> rozmiar;

	Tablica tablica;


	// 1 SPOSOB ///////////////////////////////////////////////////////
	tablica.Tworz_Tablice(rozmiar);
	
	for (int i = 0; i < rozmiar; i++)
	{
		cout << *(tablica.tab + i) << " ";
	}
	cout << "KOLEJNE TESTY" << endl;

	cout << tablica.tab[0] << " " << tablica.tab[1]<<endl;

	tablica.Usun_Tablice(tablica.tab, tablica.tab_rand);
	cout << "Usunalem tablice" << endl;

	cout << "UWAGA!!!!!" << endl;

	// 2 SPOSOB /////////////////////////////////////////////////////////

	tablica.Tworz_Tablice2(rozmiar);
	cout << endl << endl;

	cout << tablica.licznik;
}

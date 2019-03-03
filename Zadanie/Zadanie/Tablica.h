#ifndef TABLICA_HH
#define TABLICA_HH

#include <iostream>

using namespace std;


class Tablica {

	int rozmiar;

public:

	double* tab;

	int licznik;
	
	void Usun_Tablice(double*);

	void Przepisz_wiersz(double*,double*, int);

	void Tworz_Tablice_Wiktor(int);

	void Wypelnij_Tablice(double*);

	//Tablica(int);
	   
};

/*
Tablica::Tablica(int rozmiar)
{
	tab = new double[rozmiar];
}
*/

#endif
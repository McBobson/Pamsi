#ifndef TABLICA_HH
#define TABLICA_HH

#include <iostream>

using namespace std;


class Tablica {

	int rozmiar;

	//double* tab;
	//double* tab_rand;

public:

	double* tab;
	double* tab_rand;
	double** tab2;
	int licznik;

	void Tworz_Tablice(int);
	
	void Usun_Tablice(double*, double*);

	void Tworz_Tablice2(int);

};



#endif
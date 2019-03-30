#ifndef TABLICA_HH
#define TABLICA_HH

#include <iostream>

using namespace std;

template<typename T>
class Tablica {

	int rozmiar;

public:

	T* tab;
	T* tab1;
	T* tabpom;

	int licznik;
	
	void Usun_Tablice(T*);

	void Przepisz_wiersz(T*,T*, int);

	void Tworz_Tablice(int);

	void Wypelnij_Tablice(T*);

	void Tworz_Tablice_Pom(int);

	void Tworz_Tablice_PomTest(int);

	   
};

#endif
#include "pch.h"

using namespace std;

/*
double* pom;

void Quick_Sort(double tab[],int poczatek,int koniec)
{
	int i = poczatek;
	int j = koniec;
	int srodek = tab[(poczatek + koniec) / 2];

	do
	{
		while (tab[i] < srodek)
			i++;
		while (tab[j] > srodek)
			j--;

		if (i <= j)
		{
			swap(tab[i],tab[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (poczatek < j) Quick_Sort(tab, poczatek, j);
	if (koniec > i) Quick_Sort(tab, i, koniec);
}

void Scalanie(double tab[], int poczatek, int srodek, int koniec)
{
	//double* pom;
	//pom = new double[koniec + 1];

	for (int i = poczatek; i <= koniec; i++)
	{
		pom[i] = tab[i];
	}

	int k = srodek + 1;
	int j = poczatek;

	for (int i = poczatek; i <= koniec; i++)
	{
		if (j <= srodek)
		{
			if (k <= koniec)
			{
				if (pom[k] < pom[j])
				{
					tab[i] = pom[k++];
				}
				else
				{
					tab[i] = pom[j++];
				}
			}
			else
			{
				tab[i] = pom[j++];
			}
		}
		else
		{
			tab[i] = pom[k++];
		}
	}
}

void Dzielenie(double tab[], int poczatek, int koniec)
{
	int srodek = (poczatek + koniec) / 2;

	if (tab[poczatek] != tab[koniec])
	{
		Dzielenie(tab, poczatek, srodek);
		Dzielenie(tab, srodek + 1, koniec);
	}

	Scalanie(tab, poczatek, srodek, koniec);
}

void Shell(double)
{

}
*/

int main()
{
	srand(time(NULL));

	int rozmiar;
	cout << "Podaj rozmiar tablicy" << endl;
	cin >> rozmiar;
	
	Tablica<double> tablica;
	Sortowanie<double> sorto;


	clock_t start;
	double dlugosc;
	start = clock();

	for (int k = 0; k < 100; k++)
	{
		tablica.Tworz_Tablice(rozmiar);
		tablica.Tworz_Tablice_Pom(rozmiar);
		tablica.Tworz_Tablice_PomTest(rozmiar);
		tablica.Przepisz_wiersz(tablica.tab1, tablica.tab, rozmiar);
		sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
		tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
		tablica.Usun_Tablice(tablica.tab);
		tablica.Usun_Tablice(tablica.tabpom);
	}

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

	start = clock();

	for (int k = 0; k < 100; k++)
	{
		tablica.Tworz_Tablice(rozmiar);
		tablica.Tworz_Tablice_Pom(rozmiar);
		tablica.Tworz_Tablice_PomTest(rozmiar);
		tablica.Przepisz_wiersz(tablica.tab1, tablica.tab, rozmiar);
		sorto.Dzielenie(tablica.tab1,tablica.tabpom, 0, rozmiar - 1);
		tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
		tablica.Usun_Tablice(tablica.tab);
		tablica.Usun_Tablice(tablica.tabpom);
	}

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;

	/*start = clock();

	for (int k = 0; k < 100; k++)
	{
		tablica.Tworz_Tablice(rozmiar);
		double* tab3 = new double[rozmiar];
		tablica.Przepisz_wiersz(tab3, tablica.tab, rozmiar);
		Introsort(tab3, 0, rozmiar - 1);
		tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
		tablica.Usun_Tablice(tablica.tab);
	}

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/


	/***********************************\
	/*******TUTAJ ZACZYNAJA SIE TESTY***\
	/***********************************/

	
	cout << "Jaki test chcesz wykonac?" << endl;
	cout << "1. 25% posortowanych elementow" << endl;
	cout << "2. 50% posortowanych elementow" << endl;
	cout << "3. 75% posortowanych elementow" << endl;
	cout << "4. 95% posortowanych elementow" << endl;
	cout << "5. 99% posortowanych elementow" << endl;
	cout << "6. 99.7% posortowanych elementow" << endl;
	cout << "0. przerwij testy" << endl;

	char wybor='1';
	tablica.Tworz_Tablice(rozmiar);

	while (wybor != '0')
	{
		cout << "Wybierz: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1':
		{
			//double* tab_pom1 = new double[rozmiar];
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.25*rozmiar); // 25% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab1 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			/*start = clock();

			for (int k = 0; k < 100; k++)
			{
				double* tab3 = new double[rozmiar];
				tablica.Przepisz_wiersz(tab3, tab_pom1, rozmiar);
				Introsort(tab3, 0, rozmiar - 1);
				tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab2 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1,tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;


			tablica.Usun_Tablice(tablica.tabpom); // Zwolnienie pamięci
			break;
		}

		case '2':
		{
			//double* tab_pom2 = new double[rozmiar];
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.5*rozmiar); // 50% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab1 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			/*start = clock();

			for (int k = 0; k < 100; k++)
			{
				double* tab3 = new double[rozmiar];
				tablica.Przepisz_wiersz(tab3, tab_pom2, rozmiar);
				Introsort(tab3, 0, rozmiar - 1);
				tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab2 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1, tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;



			tablica.Usun_Tablice(tablica.tabpom); // Zwolnienie pamięci
			break;
		}

		case '3':
		{
			//double* tab_pom3 = new double[rozmiar];
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.75*rozmiar); // 75% poczatkowych elemnetow posortowanych

			start = clock();


			for (int k = 0; k < 100; k++)
			{
				//double* tab1 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			/*start = clock();

			for (int k = 0; k < 100; k++)
			{
				double* tab3 = new double[rozmiar];
				tablica.Przepisz_wiersz(tab3, tab_pom3, rozmiar);
				Introsort(tab3, 0, rozmiar - 1);
				tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab2 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1,tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;



			tablica.Usun_Tablice(tablica.tabpom); // Zwolnienie pamięci
		
			break;
		}

		case '4':
		{
			//double* tab_pom4 = new double[rozmiar];
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.95*rozmiar); // 95% poczatkowych elemnetow posortowanych

			start = clock();


			for (int k = 0; k < 100; k++)
			{
				//double* tab1 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

	
			/*start = clock();

			for (int k = 0; k < 100; k++)
			{
				double* tab3 = new double[rozmiar];
				tablica.Przepisz_wiersz(tab3, tab_pom, rozmiar);
				Introsort(tab3, 0, rozmiar - 1);
				tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/


			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab2 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1,tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;



			tablica.Usun_Tablice(tablica.tabpom); // Zwolnienie pamięci

			break;
		}

		case '5':
		{
			//double* tab_pom5 = new double[rozmiar];
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.99*rozmiar); // 99% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab1 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			/*start = clock();

			for (int k = 0; k < 100; k++)
			{
				double* tab3 = new double[rozmiar];
				tablica.Przepisz_wiersz(tab3, tab_pom, rozmiar);
				Introsort(tab3, 0, rozmiar - 1);
				tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab2 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1,tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;



			tablica.Usun_Tablice(tablica.tabpom); // Zwolnienie pamięci

			break;
		}


		case '6':
		{
			//double* tab_pom6 = new double[rozmiar];
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.997*rozmiar); // 99% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab1 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			/*start = clock();

			for (int k = 0; k < 100; k++)
			{
				double* tab3 = new double[rozmiar];
				tablica.Przepisz_wiersz(tab3, tab_pom6, rozmiar);
				Introsort(tab3, 0, rozmiar - 1);
				tablica.Usun_Tablice(tab3); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;*/

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				//double* tab2 = new double[rozmiar];
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1, tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;



			tablica.Usun_Tablice(tablica.tabpom); // Zwolnienie pamięci

			break;
		}

		default:
		{
			if (wybor != '0')
			{
				cout << "Bledny wybor!" << endl;
			}
			break;
		}
		}	
	}

}

#include "pch.h"

using namespace std;

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
		//sorto.ZapisQuick(tablica.tab, rozmiar); // wykomentowany zapis gdyż znacząco zwiększyłoby to długość działania programu
		tablica.Tworz_Tablice_Pom(rozmiar);
		tablica.Tworz_Tablice_PomTest(rozmiar);
		tablica.Przepisz_wiersz(tablica.tab1, tablica.tab, rozmiar);

		sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
		//sorto.ZapisQuick(tablica.tab1, rozmiar);

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
		//sorto.ZapisMerge(tablica.tab, rozmiar);
		tablica.Tworz_Tablice_PomTest(rozmiar);
		tablica.Przepisz_wiersz(tablica.tab1, tablica.tab, rozmiar);

		sorto.Dzielenie(tablica.tab1,tablica.tabpom, 0, rozmiar - 1);
		//sorto.ZapisMerge(tablica.tab1, rozmiar);

		tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
		tablica.Usun_Tablice(tablica.tab);
		tablica.Usun_Tablice(tablica.tabpom);
	}

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;

	start = clock();

	for (int k = 0; k < 100; k++)
	{
		tablica.Tworz_Tablice(rozmiar);
		//sorto.ZapisShell(tablica.tab, rozmiar);
		tablica.Tworz_Tablice_Pom(rozmiar);
		tablica.Przepisz_wiersz(tablica.tab1, tablica.tab, rozmiar);

		sorto.Shell(tablica.tab1,rozmiar);
		//sorto.ZapisShell(tablica.tab1, rozmiar);

		tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
		tablica.Usun_Tablice(tablica.tab);
	}

	dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;


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
	cout << "7. Posortowanie na odwrot" << endl;
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
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.25*rozmiar); // 25% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1,tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
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
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.5*rozmiar); // 50% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
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
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.75*rozmiar); // 75% poczatkowych elemnetow posortowanych

			start = clock();


			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
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
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.95*rozmiar); // 95% poczatkowych elemnetow posortowanych

			start = clock();


			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

	
			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;


			start = clock();

			for (int k = 0; k < 100; k++)
			{
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
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.99*rozmiar); // 99% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
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
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			sorto.Quick_Sort(tablica.tabpom, 0, 0.997*rozmiar); // 99% poczatkowych elemnetow posortowanych

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
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

		case'7':
		{
			tablica.Tworz_Tablice_PomTest(rozmiar);
			tablica.Przepisz_wiersz(tablica.tabpom, tablica.tab, rozmiar);
			
			sorto.Quick_Sort(tablica.tabpom, 0, rozmiar-1);

			sorto.Odwracanie(tablica.tabpom, rozmiar);

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Quick_Sort(tablica.tab1, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania quick: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				sorto.Shell(tablica.tab1, rozmiar);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania Shell: " << dlugosc << endl;

			start = clock();

			for (int k = 0; k < 100; k++)
			{
				tablica.Tworz_Tablice_Pom(rozmiar);
				tablica.Przepisz_wiersz(tablica.tab1, tablica.tabpom, rozmiar);
				tablica.Usun_Tablice(tablica.tabpom);
				tablica.Tworz_Tablice_PomTest(rozmiar);
				sorto.Dzielenie(tablica.tab1, tablica.tabpom, 0, rozmiar - 1);
				tablica.Usun_Tablice(tablica.tab1); // Zwolnienie pamięci
			}

			dlugosc = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Dlugosc dzialania sortowania merge: " << dlugosc << endl;
		

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

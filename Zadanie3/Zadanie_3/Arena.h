#ifndef ARENA_H
#define ARENA_H
#include "pch.h"

using namespace std;

class Arena{

public:

	char **tablica;
	int pom[2];

	Arena();
	~Arena();

	void Przesun_Pionek(int,int,int,int);
	bool Czy_Jest_Pionek(int,int);
	bool Czy_Jest_W_Arenie(int,int);
	int Kierunek_Bicia(int[]);
	bool Bicie(int, int,int[]);



};

Arena::Arena()
{
	tablica = new char *[ROZ];

	for (int i = 0; i < ROZ; i++)
	{
		tablica[i] = new char[ROZ];
	}

	for (int i = 0; i < ROZ; i++)
	{
		for (int j = 0; j < ROZ; j++)
		{
			tablica[i][j] = ' ';
		}
	}

	for (int i = 0; i < 3; i+=2)
	{
		for (int j = 0; j < 8; j+=2)
		{
			tablica[i][j] = 'X';
		}
	}

	for (int i = 1; i < 8; i+=2)
	{
		tablica[1][i] = 'X';
	}

	
	for (int i = 5; i < 8; i += 2)
	{
		for (int j = 1; j < 8; j += 2)
		{
			tablica[i][j] = 'O';
		}
	}

	for (int i = 0; i < 8; i += 2)
	{
		tablica[6][i] = 'O';
	}

	


}

Arena::~Arena()
{
	for (int i = 0; i < ROZ; i++)
	{
		delete[] tablica[i];
	}

	delete[] tablica;
}

bool Arena::Czy_Jest_Pionek(int x, int y)
{
	if (tablica[x][y]!=' ')
	{
		return true;
	}

	else return false;
}

bool Arena::Czy_Jest_W_Arenie(int x, int y)
{
	if (x <= 7 && y <= 7)
	{
		return true;
	}

	else return false;
}

int Arena::Kierunek_Bicia(int tab[])
{
	if (tab[0] < 0 && tab[1] < 0)
	{
		return 0;
	}
	else if (tab[0] < 0 && tab[1] > 0)
	{
		return 1;
	}
	else if (tab[0] > 0 && tab[1] < 0)
	{
		return 2;
	}
	else if (tab[0] > 0 && tab[1] > 0)
	{
		return 3;
	}
	else return -1;
}

bool Arena::Bicie(int x, int y, int tab[])
{
	/*
	if (tab[0] < 0 && tab[1] < 0)
	{
		if (!Czy_Jest_Pionek(x - 1, y - 1) && Czy_Jest_W_Arenie(x-1,y-1))
		{
			return true;
		}
	}
	else if (tab[0] < 0 && tab[1] > 0)
	{
		if (!Czy_Jest_Pionek(x - 1, y + 1) && Czy_Jest_W_Arenie(x - 1, y + 1))
		{
			return true;
		}
	}
	else if (tab[0] > 0 && tab[1] < 0)
	{
		if (!Czy_Jest_Pionek(x + 1, y - 1) && Czy_Jest_W_Arenie(x + 1, y - 1))
		{
			return true;
		}
	}
	else if (tab[0] < 0 && tab[1] < 0)
	{
		if (!Czy_Jest_Pionek(x + 1, y + 1) && Czy_Jest_W_Arenie(x + 1, y + 1))
		{
			return true;
		}
	}
	else return false;
	*/

	
	switch (Kierunek_Bicia(tab))
	{
	case 0:
	{
		if (!Czy_Jest_Pionek(x - 1, y - 1) && Czy_Jest_W_Arenie(x - 1, y - 1))
		{
			return true;
		}
		else return false;
	}
	break;

	case 1:
	{
		if (!Czy_Jest_Pionek(x - 1, y + 1) && Czy_Jest_W_Arenie(x - 1, y + 1))
		{
			return true;
		}
		else return false;
	}
	break;

	case 2:
	{
		if (!Czy_Jest_Pionek(x + 1, y - 1) && Czy_Jest_W_Arenie(x + 1, y - 1))
		{
			return true;
		}
		else return false;
	}
	break;

	case 3:
	{
		if (!Czy_Jest_Pionek(x + 1, y + 1) && Czy_Jest_W_Arenie(x + 1, y + 1))
		{
			return true;
		}
		else return false;
	}
	break;

	default: return false;
	}
	
}

void Arena::Przesun_Pionek(int y1,int x1,int y2,int x2)
{
	if (Czy_Jest_Pionek(x1, y1) && Czy_Jest_W_Arenie(x2, y2))
	{
		pom[0] = x2 - x1;
		pom[1] = y2 - y1;
		if (Czy_Jest_Pionek(x2, y2))
		{
			if (Bicie(x2, y2, pom))
			{
				switch (Kierunek_Bicia(pom))
				{
				case 0:
				{
					tablica[x2-1][y2-1] = tablica[x1][y1];
					tablica[x1][y1] = ' ';
					tablica[x2][y2] = ' ';
				}
				break;

				case 1:
				{
					tablica[x2-1][y2+1] = tablica[x1][y1];
					tablica[x1][y1] = ' ';
					tablica[x2][y2] = ' ';
				}
				break;

				case 2:
				{
					tablica[x2+1][y2-1] = tablica[x1][y1];
					tablica[x1][y1] = ' ';
					tablica[x2][y2] = ' ';
				}
				break;

				case 3:
				{
					tablica[x2+1][y2+1] = tablica[x1][y1];
					tablica[x1][y1] = ' ';
					tablica[x2][y2] = ' ';
				}
				break;
				}
			}
			else
				cout << "Bicie nie jest mozliwe" << endl;
		}
		else
		{
			tablica[x2][y2] = tablica[x1][y1];
			tablica[x1][y1] = ' ';
		}
	}
	else
	{
		cout << "Zjebales" << endl;
		cout << "Kody b³edu: " << endl;
		cout << "Czy jest pionek: " << Czy_Jest_Pionek(x1, y1) << endl;
		cout << "Czy jest w arenie: " << Czy_Jest_W_Arenie(x2, y2) << endl;
	}
}

ostream& operator << (ostream& wyjscie, Arena& A) {

	{

		wyjscie << "     ";

		for (int i = 0; i < 24; i++)
		{
			wyjscie << "_ ";
		}

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 0" << "  ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  "<< A.tablica[0][i] <<"  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     ";

	}

	{
	wyjscie << endl << "    ";

	for (int i = 0; i < ROZ + 1; i++)
	{
		wyjscie << "|     ";
	}

	wyjscie << endl << " 1" << "  ";


	for (int i = 0; i < ROZ; i++)
	{
		wyjscie << "|  " << A.tablica[1][i] << "  ";
	}

	wyjscie << "|";

	wyjscie << endl << "    ";

	for (int i = 0; i < ROZ; i++)
	{
		wyjscie << "|_ _ _";
	}

	wyjscie << "|     " << endl;

	}

	{
		wyjscie << "    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 2" << "  ";


		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  " << A.tablica[2][i] << "  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     " << endl;

	}

	{
		wyjscie << "    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 3" << "  ";


		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  " << A.tablica[3][i] << "  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     " << endl;

	}

	{
		wyjscie <<"    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 4" << "  ";


		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  " << A.tablica[4][i] << "  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     " << endl;

	}

	{
		wyjscie <<"    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 5" << "  ";


		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  " << A.tablica[5][i] << "  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     " << endl;

	}

	{
		wyjscie <<"    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 6" << "  ";


		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  " << A.tablica[6][i] << "  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     " << endl;

	}

	{
		wyjscie <<"    ";

		for (int i = 0; i < ROZ + 1; i++)
		{
			wyjscie << "|     ";
		}

		wyjscie << endl << " 7" << "  ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|  " << A.tablica[7][i] << "  ";
		}

		wyjscie << "|";

		wyjscie << endl << "    ";

		for (int i = 0; i < ROZ; i++)
		{
			wyjscie << "|_ _ _";
		}

		wyjscie << "|     " << endl;

	}

	{
		wyjscie << endl << "       ";


		for (int i = 65; i < 65+8; i++)
		{
			wyjscie << (char)i << "     ";
		}
		
	}

	
	return wyjscie;
}







#endif // !PLANSZA_H


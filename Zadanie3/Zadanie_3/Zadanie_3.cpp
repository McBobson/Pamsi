#include "pch.h"
#include <iostream>
#include "Arena.h"

using namespace std;

int main()
{
	
	Arena A;

	cout << A;

	char warcab[2] = { 'O','X' };

	int gracz;
	int q = 0;
	cout << endl << "Gracz 1 -> O" << endl << "Gracz 2 -> X" << endl;
	cout << "Wybierz swojego championa: ";
	cin >> gracz;

	while(q!=1)
	{
		system("cls");

		cout << A << endl;

		cout << "TURA GRACZA " << gracz << " -> " << warcab[gracz - 1] << endl;

		cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;

		int y1, y2;
		char a, b;

		cin >> a >> y1 >> b >> y2;

		A.Przesun_Pionek((int)a - 65 ,y1 , (int)b - 65, y2, gracz);

		system("Pause");
		system("cls");
		cout << A;
		
		if (gracz == 2) gracz--;
		else gracz++;

		cout << endl;

		cout << "TURA GRACZA " << gracz <<" -> " << warcab[gracz-1] << endl;

		cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;

		cin >> a >> y1 >> b >> y2;

		A.Przesun_Pionek((int)a - 65, y1, (int)b - 65, y2, gracz);

		system("Pause");
		system("cls");
		cout << A;
		gracz--;
	}
	

	

}

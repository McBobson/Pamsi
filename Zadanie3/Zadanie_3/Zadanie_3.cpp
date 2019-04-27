#include "pch.h"
#include <iostream>
#include "Arena.h"

using namespace std;

int main()
{
	
	Arena A;

	cout << A;

	int q = 0;
	while(q!=1)
	{
		system("cls");

		cout << A << endl;

		cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;

		int y1, y2;
		char a, b;

		cin >> a >> y1 >> b >> y2;

		A.Przesun_Pionek((int)a - 65 ,y1 , (int)b - 65, y2);

		system("Pause");
		system("cls");
		cout << A;
	}
	

	

}

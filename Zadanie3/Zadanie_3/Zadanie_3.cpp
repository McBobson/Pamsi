#include "pch.h"
#include <iostream>
#include "Arena.h"

using namespace std;

int main()
{
	
	Arena A(2);

	cout << A;

	char warcab[2] = { 'O','X' };

	int pom[2];
	int gracz;
	int g;
	int q = 0;
	cout << endl << "Gracz 1 -> O" << endl << "Gracz 2 -> X" << endl;
	cout << "Wybierz swojego championa: ";
	cin >> gracz;
	g = gracz;

	while(q!=1)
	{
		gracz = g;
		/*system("cls");

		cout << A << endl;

		cout << "TURA GRACZA " << gracz << " -> " << warcab[gracz - 1] << endl;

		cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;
		*/
		int y1, y2;
		char a, b;
		int a1, b1;

		
		//cin >> a >> y1 >> b >> y2;
		//pom[0] = ((int)b - 65) - ((int)a - 65);
		//pom[1] = y2 - y1;
		//A.Przesun_Pionek((int)a - 65, y1, (int)b - 65, y2, gracz);
		
		
		int bicie = 0;
		do
		{
			system("cls");

			cout << A << endl;

			cout << "TURA GRACZA " << gracz << " -> " << warcab[gracz - 1] << endl;

			if (bicie < 1)
			{
				cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;
				cin >> a >> y1 >> b >> y2;
				a1 = (int)a - 65;

			}
			else
			{
				cout << "Podaj pionka do zbicia" << endl;
				cin >> b >> y2;
				pom[1] = ((int)b - 65) - ((int)a - 65);
				pom[0] = y2 - y1;
			}
			//cout << "przed switch" << endl;

			if (A.Przesun_Pionek(a1, y1, (int)b - 65, y2, gracz)==1)
			{
				//cout << "switch" << endl;
				//cout << A.Kierunek_Bicia(pom)<<endl;
				switch (A.Kierunek_Bicia(pom))
				{
				case 0:
				{
					pom[1] = ((int)b - 65) - (a1) - 1;
					pom[0] = y2 - y1 - 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;

				case 1:
				{
					pom[1] = ((int)b - 65) - (a1) + 1;
					pom[0] = y2 - y1 - 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;

				case 2:
				{
					pom[1] = ((int)b - 65) - (a1) - 1;
					pom[0] = y2 - y1 + 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;

				case 3:
				{
					pom[1] = ((int)b - 65) - (a1) + 1;
					pom[0] = y2 - y1 + 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;
				}

				bicie++;
				a1 = (int)a - 65 + pom[1];
				y1 = y1 + pom[0];

				//cout << "Bicie" << endl;
			}
			else
			{
				//cout << "NieBicie" << endl;
				pom[0] = 0;
				pom[1] = 0;
				break;
			}

			//cout << (int)a - 65 + pom[1] << " " << y1 + pom[0];
			//A.Czy_Mozliwe_Bicie(y1 + pom[0], (int)a - 65 + pom[1]);
			//system("pause");

		} while (bicie>0 && A.Czy_Mozliwe_Bicie(y1 + pom[0], (int)a - 65 + pom[1]));
		
		
		system("Pause");
		//system("cls");
		//cout << A;
		
		if (gracz == 2) gracz--;
		else gracz++;

		cout << endl;

		//cout << "TURA GRACZA " << gracz <<" -> " << warcab[gracz-1] << endl;

		//cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;

		//cin >> a >> y1 >> b >> y2;

		//A.Przesun_Pionek((int)a - 65, y1, (int)b - 65, y2, gracz);

		bicie = 0;
		do
		{
			system("cls");

			cout << A << endl;

			cout << "TURA GRACZA " << gracz << " -> " << warcab[gracz - 1] << endl;

			if (bicie < 1)
			{
				cout << "PODAJ POLOZENIE PIONKA DO PRZESUNIECIA I TO GDZIE CHCESZ GO PRZESUNAC" << endl;
				cin >> a >> y1 >> b >> y2;
				a1 = (int)a - 65;

			}
			else
			{
				cout << "Podaj pionka do zbicia" << endl;
				cin >> b >> y2;
				pom[1] = ((int)b - 65) - ((int)a - 65);
				pom[0] = y2 - y1;
			}
			//cout << "przed switch" << endl;

			if (A.Przesun_Pionek(a1, y1, (int)b - 65, y2, gracz) == 1)
			{
				//cout << "switch" << endl;
				//cout << A.Kierunek_Bicia(pom)<<endl;
				switch (A.Kierunek_Bicia(pom))
				{
				case 0:
				{
					pom[1] = ((int)b - 65) - (a1)-1;
					pom[0] = y2 - y1 - 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;

				case 1:
				{
					pom[1] = ((int)b - 65) - (a1)+1;
					pom[0] = y2 - y1 - 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;

				case 2:
				{
					pom[1] = ((int)b - 65) - (a1)-1;
					pom[0] = y2 - y1 + 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;

				case 3:
				{
					pom[1] = ((int)b - 65) - (a1)+1;
					pom[0] = y2 - y1 + 1;
					//cout<<pom[0]<<" "<<pom[1]<<endl;
				}
				break;
				}

				bicie++;
				a1 = (int)a - 65 + pom[1];
				y1 = y1 + pom[0];

				//cout << "Bicie" << endl;
			}
			else
			{
				//cout << "NieBicie" << endl;
				pom[0] = 0;
				pom[1] = 0;
				break;
			}

			//cout << (int)a - 65 + pom[1] << " " << y1 + pom[0];
			//A.Czy_Mozliwe_Bicie(y1 + pom[0], (int)a - 65 + pom[1]);
			//system("pause");

		} while (bicie > 0 && A.Czy_Mozliwe_Bicie(y1 + pom[0], (int)a - 65 + pom[1]));

		system("Pause");
		system("cls");
		cout << A;
	}
	
	
	

}

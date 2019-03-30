#ifndef SORTOWANIE_HH
#define SORTOWANIE_HH

#include <iostream>

using namespace std;

template<typename T>
class Sortowanie {

public:

	void Quick_Sort(T [], int, int );

	void Scalanie(T [],T [], int , int , int );

	void Dzielenie(T [],T [], int , int );

	void Shell(T [], int);

	void Odwracanie(T[], int);

	void ZapisQuick(T[], int);

	void ZapisMerge(T[], int);

	void ZapisShell(T[], int);



};
#endif

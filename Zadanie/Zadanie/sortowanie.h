#ifndef SORTOWANIE_HH
#define SORTOWANIE_HH

#include <iostream>

using namespace std;

template<typename T>
class Sortowanie {

public:

	//T* pom;

	void Quick_Sort(T [], int, int );

	void Scalanie(T [],T [], int , int , int );

	void Dzielenie(T [],T [], int , int );

	void Shell(T [], int);



};
#endif

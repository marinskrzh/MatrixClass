#include "..\include\Matrix.h"
#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix m(4, 4);
	m.InitRandom();
	m.Print();
	
	
	return 0;
}
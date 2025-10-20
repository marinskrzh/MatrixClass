#include "..\include\Matrix.h"
#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix m(5, 5); 
	m.InitRandom();
	m.Print();
	cout << endl;
	cout << m.Determinant() << endl;
	
	return 0;
}
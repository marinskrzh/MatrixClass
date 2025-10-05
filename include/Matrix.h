// Matrix.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <random>
#include <initializer_list>

class Matrix
{

public:
	Matrix();
	Matrix(int, int); // Инициализация матрицы нулями через размерности
	Matrix (std::initializer_list<std::initializer_list<int>> list); // Инициализация матрицы через список значений
	Matrix(const Matrix&);
	~Matrix();

	Matrix& operator=(const Matrix& other); //присваивание
	Matrix operator+(const Matrix& other); //сложение матриц
	Matrix operator-(const Matrix& other); //вычитание матриц.
	Matrix operator*(const Matrix& other); //умножение матриц.

	Matrix operator*(int scalar); //умножение на скаляр.
	Matrix operator/(int scalar); //деление на скаляр.

	bool operator==(const Matrix& other) const; //проверка на равенство.
	bool operator!=(const Matrix& other) const; //проверка на неравенство.
	int& operator()(int i, int j); //доступ к элементу(можно изменять).
	const int& operator()(int i, int j) const; //доступ к элементу(только чтение).

	void Print(); //вывод матрицы
	void InitRandom(); //инициализация случайными числами
	bool IsSquare() const; // квадратная ли матрица
	bool IsZero() const; // нулевая ли мартрица

	Matrix Power(int exponent) const; // Возведение матрицы в степень
	Matrix Minor(int row, int col) const; // Получение минора матрицы

	bool IsOrthogonal() const; // Проверка ортогональности матрицы (проверяется с помощью ортогональной и тарспонированной)

	int Determinant() const; // Вычисление определителя (после метода с минором)
	Matrix Transpose(); //тринспонирование 
	int Trace() const; // след матрицы
	Matrix Inverse() const; // Обратная матрица (после определителя)


private:
	int** matrix; // Указатель на указатели
	size_t rows;
	size_t cols;
	void CopyFrom(const Matrix& other);
};

#pragma once

#include <iostream>
#include <random>
#include <initializer_list>

class Matrix
{

public:
	Matrix();
	Matrix(int, int);
	Matrix (std::initializer_list<std::initializer_list<int>> list); // Инициализация матрицы через список значений
	Matrix(const Matrix&);
	~Matrix();

	// Перегруженные операторы
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(int scalar);
	Matrix operator/(int scalar);
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;
	int& operator()(int i, int j); //доступ к элементу(можно изменять)
	const int& operator()(int i, int j) const; //доступ к элементу(только чтение)

	// Основные методы для работы с матрицами
	void Print();
	void InitRandom();
	bool IsSquare() const;
	bool IsZero() const;
	static Matrix Identity(int rows, int cols);
	int Trace() const;
	Matrix Transpose();


	
	int Determinant() const; // ---
	Matrix Power(int exponent) const; // ---
	Matrix Inverse() const; // ---
	bool IsOrthogonal() const; // --- Проверка ортогональности матрицы (проверяется с помощью ортогональной и тарспонированной)
	


private:
	int** matrix;
	size_t rows;
	size_t cols;
	void CopyFrom(const Matrix& other);
	Matrix Minor(int exclude_col) const; // ---
};

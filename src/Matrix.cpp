// Matrix.cpp: определяет точку входа для приложения.
//

#include "..\include\Matrix.h"

using namespace std;


Matrix::Matrix() : rows(0), cols(0)
{
	matrix = nullptr;
}
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    matrix = new int*[rows]; // Выделение памяти под строки матрицы (каждая - тоже указатель)
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int [cols] {0}; // Выделение памяти под столбцы и иницализация их нулями
	}
}

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> list) : rows(list.size()), cols(list.begin()->size())
{
	matrix = new int* [rows];// Выделение памяти под строки матрицы (каждая - тоже указатель)
	int i = 0;
	for (const auto& row : list) // Прохождение по каждой строке матрицы
	{
		matrix[i] = new int[cols]; // Выделение памяти под столбцы
		int j = 0;
		for (const auto& elem : row) // Прохождение по каждому элементу строки
			matrix[i][j++] = elem; // Заполнение матрицы
		i++;
	}
}

void Matrix::CopyFrom(const Matrix& other)
{
	// Выделяем память под новую матрицу
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	// Копируем элементы
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}
Matrix::Matrix(const Matrix& other): rows(other.rows), cols(other.cols)
{
	CopyFrom(other);
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	// Очищаем текущую матрицу
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;

	this->rows = other.rows;
	this->cols = other.cols;
	
	CopyFrom(other);
	
	return *this;
}
Matrix Matrix::operator+(const Matrix& other)
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw std::runtime_error("Matrices have different sizes");
	}
	else
	{
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
			}
		}
		return result;
	}
	
}
Matrix Matrix::operator-(const Matrix& other)
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		throw std::runtime_error("Matrices have different sizes");
	}
	else
	{
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator*(int scalar)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.matrix[i][j] = this->matrix[i][j] * scalar;
		}
	}
	return result;
}
Matrix Matrix::operator/(int scalar)
{
	if (scalar == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	else
	{
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.matrix[i][j] = this->matrix[i][j] / scalar;
			}
		}
		return result;
	}
}

bool Matrix::operator==(const Matrix& other) const
{
	if (this->cols != other.cols || this->rows != other.rows)
		return false;
	// Быстрая проверка перед полным сравнением
	if (rows > 0 && cols > 0 && this->matrix[0][0] != other.matrix[0][0])
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (this->matrix[i][j] != other.matrix[i][j])
				return false;
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}

int& Matrix::operator()(int i, int j) {
	if (i < 1 || i > rows || j < 1 || j > cols) {
		throw std::out_of_range("Indices must be in [1, rows] and [1, cols]");
	}
	return matrix[i - 1][j - 1]; // Переводим в 0-базированный
}

const int& Matrix::operator()(int i, int j) const
{
	if (i < 1 || i > rows || j < 1 || j > cols) {
		throw std::out_of_range("Indices must be in [1, rows] and [1, cols]");
	}
	return matrix[i - 1][j - 1]; // Переводим в 0-базированный
}


void Matrix::Print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j]<<"\t";
		}
		cout << endl;
	}
}

void Matrix::InitRandom()
{
	random_device rd;
	mt19937 gen(rd()); // генератор (Mersenne Twister)
	uniform_int_distribution<int> dist(1, 100); // диапазон [1, 100]

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = dist(gen);
		}
	}
}

bool Matrix::IsSquare() const
{
	return cols == rows;
}
bool Matrix::IsZero() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}
Matrix Matrix::Power(int exponent) const
{

	// реализовать после метода умножения матриц
	cout << "Метод еще не реализован" << endl;
	return *this;
	//if (!this->IsSquare())
	//	throw std::logic_error("Power is defined only for square matrices!");

	//if (exponent < 0)
	//	throw std::logic_error("Negative exponent not supported!");

	//if (exponent == 1)
	//	return *this; // Возвращаем копию самой матрицы

	//

	//if (exponent % 2 == 0) // Если степень четная
	//{
	//	Matrix halfM = this->Power(exponent / 2);
	//	//return halfM * halfM;
	//}
}
int Matrix::Determinant() const
{
	cout << "Метод еще не реализован" << endl;
	return 0;
	//if (!this->IsSquare())
	//	throw std::logic_error("Determinant is defined only for square matrices!");

	//if (this->IsSquare() && rows == 1)
	//	return matrix[0][0];

	//if (this->IsSquare() && rows == 2)
	//	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];


	//if (this->IsZero())
	//	return 0;
	//// все что ниже - бесконечная рекурсия. переделать когда реализую метод поиска соответствующего минора
	//int det = 0;
	//int sign = 1;

	//	// Разложение по первой строке
	//for (int j = 0; j < cols; j++) 
	//{
	//	// Создаем минор (подматрицу без 0-й строки и j-го столбца)
	//	Matrix minor(rows - 1, cols - 1);

	//	for (int i = 1; i < rows; i++) 
	//	{
	//		int minor_col = 0;
	//		for (int k = 0; k < cols; k++) 
	//		{
	//			if (k == j) continue; // Пропускаем j-й столбец
	//			minor(i - 1, minor_col) = matrix[i][k];
	//			minor_col++;
	//		}
	//	}

	//	// Рекурсивно вычисляем определитель минора
	//	int minor_det = minor.Determinant();
	//	det += sign * matrix[0][j] * minor_det;
	//	sign = -sign; // Чередуем знаки

	//		
	//}
	//	return det;

}
Matrix Matrix::Transpose()
{
	Matrix temp_matr(cols, rows);
	
	for (int i = 0; i < temp_matr.rows; i++)
	{
		for (int j = 0; j < temp_matr.cols; j++)
		{
			temp_matr.matrix[j][i] = this->matrix[i][j];
		}
	}
	return temp_matr;
}

int Matrix::Trace() const
{
	if (!this->IsSquare())
	{
		throw std::logic_error("Trace is defined only for square matrices!");
	}
	int trace = 0;
	for (int i = 0; i < rows; i++)
	{
		trace += this->matrix[i][i];
	}
	return trace;
	
}

Matrix Matrix::Inverse() const
{
	cout << "Мметод еще не реализован" << endl;
	return Matrix();
	// писать метод после того как напишу метод поиск определителя. 
}

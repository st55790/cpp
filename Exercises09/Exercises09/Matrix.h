#pragma once
#ifndef MATRIX_H
#define MATRIX_H

template<typename T>

class Matrix {

public:
	Matrix(int row, int column);
	Matrix(const Matrix<T>& matrix);
	~Matrix();
	void SetElementInMatrix(int row, int column, T data);
	void SetFrom(T* array);
	T& GetElement(int row, int column);
	const T& GetElement(int row, int column) const;
	template<typename R> Matrix<R> Retype() const;
	Matrix<T> Transposition() const;
	Matrix<T> Multiplication(const Matrix& matrix) const;
	Matrix<T> Multiplication(T scalar) const;
	Matrix<T> Addition(const Matrix& matrix) const;
	Matrix<T> Addition(T scalar) const;
	bool EaqulMatrix(const Matrix& matrix) const;
	void Print() const;

private:
	int rows;
	int columns;
	T** data;
};

#endif // !MATRIX_H

template<typename T>
inline Matrix<T>::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	data = new T * [rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new T[columns];
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& matrix)
{
	this->rows = matrix.rows;
	this->columns = matrix.columns;
	this->data = new T * [rows];
	for (int i = 0; i < rows; i++) {
		this->data[i] = new T[columns];
		for(int j = 0; j < columns; j++) {
			this->data[i][j] = matrix.data[i][j];
		}
	}

}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete[] data;

}

template<typename T>
inline void Matrix<T>::SetElementInMatrix(int row, int column, T data)
{
	if (row < 0 || row > rows || column < 0 || column > columns) {
		throw std::invalid_argument("BAD ROW OR COLUMN");
	}
	this->data[row][column] = data;
}

template<typename T>
inline void Matrix<T>::SetFrom(T* array)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			data[i][j] = array[(i * columns) + j];
		}
	}
}

template<typename T>
inline T& Matrix<T>::GetElement(int row, int column)
{
	if (row < 0 || row > rows || column < 0 || column > columns) {
		throw std::invalid_argument("BAD ROW OR COLUMN");
	}
	return data[row][column];
}

template<typename T>
inline const T& Matrix<T>::GetElement(int row, int column) const
{
	if (row < 0 || row > rows || column < 0 || column > columns) {
		throw std::invalid_argument("BAD ROW OR COLUMN");
	}
	return data[row][column];
}

template<typename T>
inline Matrix<T> Matrix<T>::Transposition() const
{
	Matrix<T> newMatrix = Matrix(columns, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.data[i][j] = this->data[j][i];
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Multiplication(const Matrix& matrix) const
{
	if (this->columns != matrix.columns) {
		throw std::length_error("Dimensions dont match");
	}
	Matrix<T> newMatrix = Matrix<T>(this->rows, matrix.columns);
	T sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			for (int k = 0; k < matrix.rows; k++) {
				sum += this->data[i][k] * matrix.data[k][j];
			}
			newMatrix.data[i][j] = sum;
			sum = 0;
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Multiplication(T scalar) const
{
	Matrix<T> newMatrix = Matrix<T>(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.data[i][j] = this->data[i][j] * scalar;
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Addition(const Matrix& matrix) const
{
	if (this->columns != matrix.columns || this->rows != matrix.rows) {
		throw std::length_error("Dimensions dont match");
	}
	Matrix<T> newMatrix = Matrix<T>(rows,columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.data[i][j] = this->data[i][j] + matrix.data[i][j];
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Addition(T scalar) const
{
	Matrix<T> newMatrix = Matrix<T>(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.data[i][j] = this->data[i][j] + scalar;
		}
	}
	return newMatrix;
}

template<typename T>
inline bool Matrix<T>::EaqulMatrix(const Matrix& matrix) const
{
	Matrix<T> newMatrix = Matrix<T>(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (this->data[i][j] != matrix.data[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
inline void Matrix<T>::Print() const
{
	Matrix<T> newMatrix = Matrix<T>(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout<< newMatrix.data[i][j] << "	";
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
inline Matrix<R> Matrix<T>::Retype() const
{
	Matrix<R> newMatrix = Matrix<R>(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.SetElementInMatrix(i,j, static_cast<R>(GetElement(i,j)));
		}
	}
	return newMatrix;
}

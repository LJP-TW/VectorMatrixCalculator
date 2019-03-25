#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix();

	std::string Name;
	std::vector<std::vector<double>> Data;

	/*
	 * Addition
	 * 可能會 throw
	 * - DIMENSION_NON_EQUIVALENT
	 */
	Matrix operator +(const Matrix& m);

	/*
	 * Subtraction
	 * 可能會 throw
	 * - DIMENSION_NON_EQUIVALENT
	 */
	Matrix operator -(const Matrix& m);

	/*
	 * Multiplication
	 * 可能會 throw
	 * - MULTIPLICATION_DIMENSION_ERROR
	 */
	Matrix operator *(const Matrix& m);

	/*
	 * Solving linear system
	 */
	Matrix solve(const Matrix& m);

	/*
	 * Rank
	 */
	unsigned int rank();

	Matrix trans();
	double det();
	Matrix inverse();
	Matrix adj();
	std::vector<Matrix> eigen();
	std::vector<Matrix> pm();
	friend Matrix leastsquare(const Matrix& A, const Matrix& B);
};

// 定義相關錯誤
enum class MATRIX_ERROR {
	DIMENSION_NON_EQUIVALENT,
	MULTIPLICATION_DIMENSION_ERROR,
	ROW_DIMENSION_NON_EQUIVALENT,
	NON_SQUARE,
	NON_SINGULAR
};
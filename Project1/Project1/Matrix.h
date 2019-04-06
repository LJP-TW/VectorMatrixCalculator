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
	 * Return the result of A+B, which A is this matrix, B is m
	 * might throw
	 * - DIMENSION_NON_EQUIVALENT
	 */
	Matrix operator +(const Matrix& m);

	/*
	 * Return the result of A-B, which A is this matrix, B is m
	 * might throw
	 * - DIMENSION_NON_EQUIVALENT
	 */
	Matrix operator -(const Matrix& m);

	/*
	 * Return the result of A*B, which A is this matrix, B is m
	 * might throw
	 * - MULTIPLICATION_DIMENSION_ERROR
	 */
	Matrix operator *(const Matrix& m);

	/*
	 * Return the solution of Ax=B, which A is this matrix, B is m
	 * might throw
	 * - NON_SQUARE
	 * - SINGULAR
	 * - ROW_DIMENSION_NON_EQUIVALENT
	 */
	Matrix solve(const Matrix& m);

	/*
	 * Return the rank of this matrix
	 */
	unsigned int rank();

	/*
	 * Return transpose matrix of this matrix
	 */
	Matrix trans() const;

	/*
	 * Return determinant of this matrix
	 * might throw
	 * - NON_SQUARE
	 */
	double det();

	/*
	 * Return inverse of this matrix
	 * will call
	 * - solve()
	 * might throw
	 * - NON_SQUARE
	 * - ROW_DIMENSION_NON_EQUIVALENT
	 * - SINGULAR
	 */
	Matrix inverse();

	/*
	 * Return adjoint matrix of this matrix
	 * will call
	 * - det()
	 * might throw
	 * - NON_SQUARE
	 */
	Matrix adj();

	/*
	 * Return two matrix
	 * - The matrix containing eigenvectors as columns 
	 * - The diagonal eigenvalues matrix
	 * e.g.
	 * AX1 = D1X1
	 * AX2 = D2X2
	 * While 
	 * - A is this matrix (suppose it is 2x2 matrix)
	 * - Xn is eigenvectors {xn1, xn2}
	 * - Dn is eigenvalue
	 * That this function return two matrix
	 *  | x11 x21 |     | D1   0 |
	 *  | x12 x22 | and |  0  D2 |
	 *
	 * ATTENTION: ONLY SUPPORT 2x2 AND 3x3 MATRIX !!
	 * might throw
	 * - EIGEN_DIMENSION_ERROR
	 * - NON_DIAGONALIZABLE
	 * - NON_SQUARE
	 */
	std::vector<Matrix> eigen();

	/*
	 * Return two matrix
	 * - The matrix containing eigenvectors as columns 
	 * - The diagonal eigenvalues matrix
	 * But there is no limit of dimension
	 *
	 * might throw
	 * - NON_SQUARE
	 * - NON_DIAGONALIZABLE
	 */
	std::vector<Matrix> pm();

	/*
	 * Return the best solution of Ax=B
	 * might throw
	 * - ROW_DIMENSION_NON_EQUIVALENT
	 * - SINGULAR
	 */
	friend Matrix leastsquare(const Matrix& A, const Matrix& B);

protected:
	/*
	 * Change this matrix into r.e.f.
	 */
	void ref(double threshold);
};

// 定義相關錯誤
enum class MATRIX_ERROR {
	DIMENSION_NON_EQUIVALENT, // A 與 B 維度不同
	EIGEN_DIMENSION_ERROR, // 目前 eigen() 只支援 2x2 或 3x3 Matrix
	MULTIPLICATION_DIMENSION_ERROR, // A 與 B 不能做乘法
	NON_DIAGONALIZABLE, // Matrix 不是 diagonalizable matrix
	NON_SQUARE, // Matrix 不是 square matrix
	ROW_DIMENSION_NON_EQUIVALENT, // A 與 B Row 的維度不同
	SINGULAR // Matrix 是 singular matrix
};
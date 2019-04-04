#include "Matrix.h"
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#define THRESHOLD 10E-12

Matrix::Matrix()
{
}

Matrix Matrix::operator+(const Matrix & m)
{
	// 判斷是否可以相加
	// A(r1 x c1) * B(r2 x c2)
	// --> r1 必須等於 r2, c1 必須等於 c2
	if (this->Data.size() != m.Data.size() || this->Data[0].size() != m.Data[0].size())
	{
		throw MATRIX_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Matrix result = *this;

	for (unsigned int y = 0; y < result.Data.size(); ++y)
	{
		for (unsigned int x = 0; x < result.Data[y].size(); ++x)
		{
			result.Data[y][x] += m.Data[y][x];
		}
	}

	return result;
}

Matrix Matrix::operator-(const Matrix & m)
{
	// 判斷是否可以相減
	// A(r1 x c1) * B(r2 x c2)
	// --> r1 必須等於 r2, c1 必須等於 c2
	if (this->Data.size() != m.Data.size() || this->Data[0].size() != m.Data[0].size())
	{
		throw MATRIX_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Matrix result = *this;

	for (unsigned int y = 0; y < result.Data.size(); ++y)
	{
		for (unsigned int x = 0; x < result.Data[y].size(); ++x)
		{
			result.Data[y][x] -= m.Data[y][x];
		}
	}

	return result;
}

Matrix Matrix::operator*(const Matrix & m)
{
	// 判斷是否可以相乘
	// A(r1 x c1) * B(r2 x c2)
	// --> c1 必須等於 r2
	if (this->Data[0].size() != m.Data.size())
	{
		throw MATRIX_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Matrix result;

	for (unsigned int y = 0; y < this->Data.size(); ++y)
	{
		std::vector<double> rowVectorTemp;
		for (unsigned int x = 0; x < m.Data[0].size(); ++x)
		{
			double sumTemp = 0;
			for (unsigned int i = 0; i < this->Data[0].size(); ++i)
			{
				sumTemp += (this->Data[y][i] * m.Data[i][x]);
			}
			rowVectorTemp.push_back(sumTemp);
		}
		result.Data.push_back(rowVectorTemp);
	}

	return result;
}

Matrix Matrix::solve(const Matrix & m)
{
	// Solving Ax = B, A.rows must equal B.rows, A must be square matrix
	if (this->Data.size() != m.Data.size())
	{
		throw MATRIX_ERROR::ROW_DIMENSION_NON_EQUIVALENT;
	}
	else if (this->Data.size() != this->Data[0].size())
	{
		throw MATRIX_ERROR::NON_SQUARE;
	}

	Matrix A = *this;
	Matrix B = m;

	// Gaussian elimination to get r.e.f.
	for (unsigned int current = 0; current < A.Data[0].size(); ++current)
	{
		// Search for maximum in this column
		double maxNum = abs(A.Data[current][current]);
		unsigned int maxRow = current;
		for (unsigned int r = current + 1; r < A.Data.size(); ++r)
		{
			if (abs(A.Data[r][current]) > maxNum)
			{
				maxNum = abs(A.Data[r][current]);
				maxRow = r;
			}
		}

		if (!maxNum)
			throw MATRIX_ERROR::SINGULAR;

		// Swap maxRow to current row
		for (unsigned int c = current; c < A.Data[0].size(); ++c)
		{
			double temp = A.Data[current][c];
			A.Data[current][c] = A.Data[maxRow][c];
			A.Data[maxRow][c] = temp;
		}
		for (unsigned int c = 0; c < B.Data[0].size(); ++c)
		{
			double temp = B.Data[current][c];
			B.Data[current][c] = B.Data[maxRow][c];
			B.Data[maxRow][c] = temp;
		}

		// Doing elimination
		for (unsigned int r = current + 1; r < A.Data.size(); ++r)
		{
			if (!A.Data[r][current])
			{
				continue;
			}
			for (unsigned int c = current + 1; c < A.Data[0].size(); ++c)
			{
				A.Data[r][c] -= (A.Data[current][c] * A.Data[r][current] / A.Data[current][current]);
			}
			for (unsigned int c = 0; c < B.Data[0].size(); ++c)
			{
				B.Data[r][c] -= (B.Data[current][c] * A.Data[r][current] / A.Data[current][current]);
			}
			A.Data[r][current] = 0;
		}
	}

	// Get result by solving upper triangular matrix
	for (int current = A.Data.size() - 1; current >= 0; --current)
	{
		for (unsigned int c = 0; c < B.Data[0].size(); ++c)
		{
			B.Data[current][c] /= A.Data[current][current];
		}

		for (int r = current - 1; r >= 0; --r)
		{
			for (unsigned int c = 0; c < B.Data[0].size(); ++c)
			{
				B.Data[r][c] -= (A.Data[r][current] * B.Data[current][c]);
			}
		}
	}

	return B;
}

unsigned int Matrix::rank()
{
	Matrix A = *this;

	// Change this matrix into r.e.f.
	A.ref();

	for (unsigned int y = 0; y < A.Data.size(); ++y)
	{
		for (unsigned int x = 0; x < A.Data[0].size(); ++x)
		{
			// threshold
			if (-THRESHOLD < A.Data[y][x] && A.Data[y][x] < THRESHOLD)
			{
				A.Data[y][x] = 0;
			}
		}
	}

	// Check for zero row
	unsigned int zeroRow = 0;
	for (int i = A.Data.size() - 1; i >= 0; --i)
	{
		bool isZeroRow = true;
		for (int j = 0; j < A.Data[0].size(); ++j)
		{
			if (A.Data[i][j] != 0)
			{
				isZeroRow = false;
				break;
			}
		}
		if (isZeroRow)
		{
			++zeroRow;
		}
		else
		{
			break;
		}
	}

	return A.Data.size() - zeroRow;
}

Matrix Matrix::trans()
{
	Matrix result;
	for (unsigned int x = 0; x < this->Data[0].size(); ++x)
	{
		std::vector<double> rowVectorTemp;
		for (unsigned int y = 0; y < this->Data.size(); ++y)
		{
			rowVectorTemp.push_back(this->Data[y][x]);
		}
		result.Data.push_back(rowVectorTemp);
	}
	return result;
}

double Matrix::det()
{
	// Solving det(A), A must be square matrix.
	if (this->Data.size() != this->Data[0].size())
	{
		throw MATRIX_ERROR::NON_SQUARE;
	}

	Matrix A = *this;
	double result;
	int sign = true;

	// Gaussian elimination to get upper triangle matrix
	for (unsigned int current_y = 0, current_x = 0; \
		current_y < A.Data.size() && current_x < A.Data[0].size(); \
		++current_y, ++current_x)
	{
		// Search for maximum in this column
		double maxNum = abs(A.Data[current_y][current_x]);
		unsigned int maxRow = current_y;
		for (unsigned int r = current_y + 1; r < A.Data.size(); ++r)
		{
			if (abs(A.Data[r][current_x]) > maxNum)
			{
				maxNum = abs(A.Data[r][current_x]);
				maxRow = r;
			}
		}

		// If there is a zero in diagonal line, det(A) = 0
		if (!maxNum)
		{
			return 0;
		}

		// Swap maxRow to current row
		if (current_y != maxRow)
		{
			for (unsigned int c = current_x; c < A.Data[0].size(); ++c)
			{
				double temp = A.Data[current_y][c];
				A.Data[current_y][c] = A.Data[maxRow][c];
				A.Data[maxRow][c] = temp;
			}
			sign = !sign;
		}

		// Doing elimination
		for (unsigned int r = current_y + 1; r < A.Data.size(); ++r)
		{
			if (!A.Data[r][current_x])
			{
				continue;
			}

			for (unsigned int c = current_x + 1; c < A.Data[0].size(); ++c)
			{
				A.Data[r][c] -= (A.Data[current_y][c] * A.Data[r][current_x] / A.Data[current_y][current_x]);
			}
			A.Data[r][current_x] = 0;
		}
	}
	
	// Calculate det(A)
	result = A.Data[0][0];
	for (unsigned int i = 1; i < A.Data.size(); ++i)
	{
		result *= A.Data[i][i];
	}
	result *= sign ? 1 : -1;
	return result;
}

Matrix Matrix::inverse()
{
	// Solving inverse(A), A must be square matrix.
	if (this->Data.size() != this->Data[0].size())
	{
		throw MATRIX_ERROR::NON_SQUARE;
	}

	Matrix A = *this;
	Matrix B, result;

	// Making a identity matrix
	for (unsigned r = 0; r < A.Data.size(); ++r)
	{
		std::vector<double> tempRowVector;
		for (unsigned c = 0; c < A.Data.size(); ++c)
		{
			if (r == c)
				tempRowVector.push_back(1);
			else
				tempRowVector.push_back(0);
		}
		B.Data.push_back(tempRowVector);
	}

	// Solving Ax=B
	try
	{
		result = A.solve(B);
	}
	catch (...)
	{
		throw;
	}

	return result;
}

Matrix Matrix::adj()
{
	// Solving inverse(A), A must be square matrix.
	if (this->Data.size() != this->Data[0].size())
	{
		throw MATRIX_ERROR::NON_SQUARE;
	}

	Matrix result = *this;

	for (unsigned int y = 0; y < this->Data.size(); ++y)
	{
		for (unsigned int x = 0; x < this->Data[0].size(); ++x)
		{
			Matrix temp;
			for (unsigned int tempY = 0; tempY < this->Data.size(); ++tempY)
			{
				if (tempY == y)
					continue;

				std::vector<double> tempRowVector;
				for (unsigned int tempX = 0; tempX < this->Data.size(); ++tempX)
				{
					if (tempX != x)
					{
						tempRowVector.push_back(this->Data[tempY][tempX]);
					}
				}

				temp.Data.push_back(tempRowVector);
			}

			result.Data[x][y] = temp.det();
			if ((y + x) % 2 == 1)
			{
				result.Data[x][y] *= -1;
			}
		}
	}
	return result;
}

std::vector<Matrix> Matrix::eigen()
{
	if (this->Data.size() != (*this).Data[0].size())
	{
		throw MATRIX_ERROR::NON_SQUARE;
	}
	else if (this->Data.size() > 3)
	{
		throw MATRIX_ERROR::EIGEN_DIMENSION_ERROR;
	}

	std::vector<double> eigenValues;
	std::vector<std::vector<double>> eigenVectors;
	std::vector<Matrix> result;
	std::vector<double> tempEigenVector;
	Matrix tempMatrix[2];

	// Find eigenvalues and eigenvectors
	if (this->Data.size() == 1)
	{
		eigenValues.push_back(this->Data[0][0]);
		tempEigenVector.push_back(1);
		eigenVectors.push_back(tempEigenVector);
	}
	else if (this->Data.size() == 2)
	{
		// | A00 - D      A01 |
		// | A10      A11 - D |
		// D^2 + bD + c = 0
		// a = 1
		// b = (-A11) + (-A00)
		// c = A00 * A11 - A01 * A10
		double b, c, e[2];
		b = -this->Data[0][0] - this->Data[1][1];
		c = this->Data[0][0] * this->Data[1][1] - this->Data[0][1] * this->Data[1][0];

		// Get eigenvalues by Quadric Equation
		// 0 isn't a eigenvalue
		if ((e[0] = (-b + sqrt(b * b - 4 * c)) / 2) == 0 || \
			(e[1] = (-b - sqrt(b * b - 4 * c)) / 2) == 0 || \
			 e[0] == e[1])
		{
			throw MATRIX_ERROR::NON_DIAGONALIZABLE;
		}
		eigenValues.push_back(e[0]);
		eigenValues.push_back(e[1]);

		// Get eigenvectors
		for (unsigned int n = 0; n < 2; ++n)
		{
			// Produce (A - DnI)
			// Dn: nth eigenvalue
			// I : Identity matrix
			Matrix A = *this;
			for (unsigned int r = 0; r < 2; ++r)
			{
				A.Data[r][r] -= eigenValues[n];
			}

			A.ref();

			if (A.Data[0][0] != 0)
			{
				// (A - DnI) = 
				// | a00 a01 |
				// |   0   0 |
				// If a00 have a value, a11 will always be 0.
				// x0 = a01
				// x1 = -a00
				// Normalization =>
				// t = sqrt(1 / (x0^ + x1^)
				// x0 *= t 
				// x1 *= t
				double x[2], t;
				x[0] = A.Data[0][1];
				x[1] = -A.Data[0][0];
				t = sqrt(1 / (x[0] * x[0] + x[1] * x[1]));
				x[0] *= t;
				x[1] *= t;

				// threshold
				for (unsigned i = 0; i < 2; ++i)
				{
					if (-THRESHOLD < x[i] && x[i] < THRESHOLD)
					{
						x[i] = 0;
					}
				}

				tempEigenVector.push_back(x[0]);
				tempEigenVector.push_back(x[1]);
				eigenVectors.push_back(tempEigenVector);
			}
			else
			{
				// (A - DnI) = 
				// |   0 a01 |
				// |   0   0 |
				// x0 = n
				// x1 = 0
				// Normalization 
				// x0 = 1
				// x1 = 0
				tempEigenVector.push_back(1);
				tempEigenVector.push_back(0);
				eigenVectors.push_back(tempEigenVector);
			}
			tempEigenVector.clear();
		}
	}
	else if (this->Data.size() == 3)
	{
		// | A00 - D      A01      A02 |
		// | A10      A11 - D      A12 |
		// | A20          A21  A22 - D | 
		// aD^3 + bD^2 + cD + d = 0
		// a = -1
		// b = A00 + A11 + A22
		// c = - A00 * A11 
		//     - A11 * A22 
		//     - A22 * A00
		//	   + A01 * A10
		//     + A02 * A20
		//	   + A12 * A21
		// d = + A00 * A11 * A22 
		//     + A01 * A12 * A20 
		//     + A02 * A10 * A21 
		//     - A02 * A11 * A20 
		//     - A00 * A12 * A21 
		//     - A01 * A10 * A22
		// If a = 1, bcd will *= -1
		double b, c, d, q, r, t, e[3];
		b = -this->Data[0][0] - this->Data[1][1] - this->Data[2][2];

		c = + this->Data[0][0] * this->Data[1][1] \
			+ this->Data[1][1] * this->Data[2][2] \
			+ this->Data[2][2] * this->Data[0][0] \
			- this->Data[0][1] * this->Data[1][0] \
			- this->Data[0][2] * this->Data[2][0] \
			- this->Data[1][2] * this->Data[2][1];

		d = - this->Data[0][0] * this->Data[1][1] * this->Data[2][2] \
			- this->Data[0][1] * this->Data[1][2] * this->Data[2][0] \
			- this->Data[0][2] * this->Data[1][0] * this->Data[2][1] \
			+ this->Data[0][2] * this->Data[1][1] * this->Data[2][0] \
			+ this->Data[0][0] * this->Data[1][2] * this->Data[2][1] \
			+ this->Data[0][1] * this->Data[1][0] * this->Data[2][2];

		q = (b * b - 3 * c) / 9;
		r = (2 * b * b * b - 9 * b * c + 27 * d) / 54;
		t = acos(r / (sqrt(q * q * q)));

		// Get eigenvalues by Cubic Equation
		// 0 isn't a eigenvalue
		if ((e[0] = -2 * sqrt(q) * cos(t / 3) - b / 3) == 0 || \
			(e[1] = -2 * sqrt(q) * cos((t + 2 * M_PI) / 3) - b / 3) == 0 || \
			(e[2] = -2 * sqrt(q) * cos((t - 2 * M_PI) / 3) - b / 3) == 0 || \
			 e[0] == e[1] || \
			 e[0] == e[2] || \
			 e[1] == e[2])
		{
			throw MATRIX_ERROR::NON_DIAGONALIZABLE;
		}
		eigenValues.push_back(e[0]);
		eigenValues.push_back(e[1]);
		eigenValues.push_back(e[2]);
		
		// Get eigenvectors
		for (unsigned int n = 0; n < 3; ++n)
		{
			// Produce (A - DnI)
			// Dn: nth eigenvalue
			// I : Identity matrix
			Matrix A = *this;
			for (unsigned int r = 0; r < 3; ++r)
			{
				A.Data[r][r] -= eigenValues[n];
			}

			A.ref();

			if (A.Data[0][0] != 0)
			{
				// (A - DnI) = 
				// | a00 a01 a02 |
				// |   0 a11 a12 |
				// |   0   0   0 |
				// x0 = (a11 * a02 - a12 * a01) / a00
				// x1 = a12
				// x2 = -a11
				// Normalization =>
				// t = sqrt(1 / (x0^ + x1^ + x2^)
				// x0 *= t 
				// x1 *= t
				// x2 *= t
				double x[3], t;
				x[0] = (A.Data[1][1] * A.Data[0][2] - A.Data[1][2] * A.Data[0][1]) / A.Data[0][0];
				x[1] = A.Data[1][2];
				x[2] = -A.Data[1][1];
				t = sqrt(1 / (x[0] * x[0] + x[1] * x[1] + x[2] * x[2]));
				x[0] *= t;
				x[1] *= t;
				x[2] *= t;

				// threshold
				for (unsigned i = 0; i < 3; ++i)
				{
					if (-THRESHOLD < x[i] && x[i] < THRESHOLD)
					{
						x[i] = 0;
					}
				}

				tempEigenVector.push_back(x[0]);
				tempEigenVector.push_back(x[1]);
				tempEigenVector.push_back(x[2]);
				eigenVectors.push_back(tempEigenVector);
			}
			else
			{
				// (A - DnI) = 
				// |   0 a01 a02 |
				// |   0   0 a12 |
				// |   0   0   0 |
				// x0 = n
				// x1 = 0
				// x2 = 0
				// Normalization 
				// x0 = 1
				// x1 = 0
				// x2 = 0
				tempEigenVector.push_back(1);
				tempEigenVector.push_back(0);
				tempEigenVector.push_back(0);
				eigenVectors.push_back(tempEigenVector);
			}
			tempEigenVector.clear();
		}
	}

	// Produce matrix containing eigenvectors as columns 
	for (unsigned int i = 0; i < eigenVectors.size(); ++i)
	{
		tempMatrix[0].Data.push_back(eigenVectors[i]);
	}
	tempMatrix[0] = tempMatrix[0].trans();

	// Produce diagonal eigenvalues matrix
	for (unsigned int i = 0; i < eigenValues.size(); ++i)
	{
		std::vector<double> tempRow;
		for (unsigned int c = 0; c < eigenValues.size(); ++c)
		{
			if (c == i)
			{
				tempRow.push_back(eigenValues[i]);
			}
			else
			{
				tempRow.push_back(0);
			}
		}
		tempMatrix[1].Data.push_back(tempRow);
	}

	// Produce result
	result.push_back(tempMatrix[0]);
	result.push_back(tempMatrix[1]);
	
	return result;
}

std::vector<Matrix> Matrix::pm()
{
	if (this->Data.size() != (*this).Data[0].size())
	{
		throw MATRIX_ERROR::NON_SQUARE;
	}

	Matrix tempMatrix[2];
	std::vector<Matrix> result;
	std::vector<double> eigenValues;
	std::vector<std::vector<double>> eigenVectors;
	std::vector<Matrix> eigenResult;
	Matrix A[2];
	std::vector<double> xk[2];
	double scalar = 0, temp;

	// Initial Matrix
	A[1] = *this;

	// Using Power Method & Deflation to calculate all the eigenvalues when dimension of square matrix is too big
	while (A[1].Data.size() > 3)
	{
		// Random Initial Vector [1, 0, 0, .... ]
		srand(time(NULL));
		xk[1].clear();
		xk[1].push_back(1);
		for (unsigned int i = 1; i < A[1].Data.size(); ++i)
		{
			xk[1].push_back((double)(rand() % 1001) / 1000);
		}
		xk[0] = xk[1];

		// Do approximation
		// xk[1] turn out eigenvector, corresponding to dominant eigenvalue
		// scalar turn out dominant eigenvalue
		do
		{
#ifdef DEBUG
			// DEBUG
			std::cout << "xk = ";
			for (unsigned int i = 0; i < xk[1].size(); ++i)
			{
				std::cout << xk[0][i] << " ";
			}
			std::cout << "\n";
#endif

			// x(k) = A * x(k - 1)
			for (unsigned int r = 0; r < A[1].Data.size(); ++r)
			{
				xk[0][r] = 0;
				for (unsigned int i = 0; i < A[1].Data.size(); ++i)
				{
					xk[0][r] += A[1].Data[r][i] * xk[1][i];
				}
			}

			// Find new scalar
			temp = scalar;
			scalar = 0;

			for (unsigned int i = 0; i < xk[0].size(); ++i)
			{
				if (abs(xk[0][i]) > abs(scalar))
				{
					scalar = xk[0][i];
				}
			}

			// Scaling
			for (unsigned int i = 0; i < xk[0].size(); ++i)
			{
				xk[0][i] /= scalar;
			}

			xk[1] = xk[0];
		} while (abs(scalar - temp) > THRESHOLD);

#ifdef DEBUG
		// DEBUG
		std::cout << "xk = ";
		for (unsigned int i = 0; i < xk[1].size(); ++i)
		{
			std::cout << xk[0][i] << " ";
		}
		std::cout << "\n";
#endif

		// Recode dominant eigenvalue
		eigenValues.push_back(scalar);

		for (unsigned int r = 0; r < A[0].Data.size(); ++r)
		{
			A[0].Data[r].clear();
		}
		A[0].Data.clear();

		// Do Wielandt deflation
		for (unsigned int r = 1; r < A[1].Data.size(); ++r)
		{
			std::vector<double> tempRowVector;

			for (unsigned int c = 1; c < A[1].Data.size(); ++c)
			{
				tempRowVector.push_back(A[1].Data[r][c] - (xk[0][r] / xk[0][0]) * A[1].Data[0][c]);
			}

			A[0].Data.push_back(tempRowVector);
		}
		A[1] = A[0];
	}
	
	// When the matrix deflate to 3D or lower dimension, using eigen()
	// might throw NON_DIAGONALIZABLE
	try
	{
		eigenResult = A[1].eigen();
	}
	catch (...)
	{
		throw;
	}
	
	for (unsigned int i = 0; i < eigenResult[1].Data.size(); ++i)
	{
		eigenValues.push_back(eigenResult[1].Data[i][i]);
	}

	// Produce matrix containing eigenvectors as columns 
	// TODO:

	// Produce diagonal eigenvalues matrix
	for (unsigned int i = 0; i < eigenValues.size(); ++i)
	{
		std::vector<double> tempRow;
		for (unsigned int c = 0; c < eigenValues.size(); ++c)
		{
			if (c == i)
			{
				tempRow.push_back(eigenValues[i]);
			}
			else
			{
				tempRow.push_back(0);
			}
		}
		tempMatrix[1].Data.push_back(tempRow);
	}

	// Produce result
	//result.push_back(tempMatrix[0]);
	result.push_back(tempMatrix[1]);
	result.push_back(tempMatrix[1]);

	return result;
}

Matrix leastsquare(const Matrix & A, const Matrix & B)
{
	return Matrix();
}

void Matrix::ref()
{
	// Gaussian elimination to get r.e.f.
	for (unsigned int current_y = 0, current_x = 0; \
		current_y < this->Data.size() && current_x < this->Data[0].size(); \
		++current_y, ++current_x)
	{
		// Search for maximum in this column
		double maxNum = abs(this->Data[current_y][current_x]);
		unsigned int maxRow = current_y;
		for (unsigned int r = current_y + 1; r < this->Data.size(); ++r)
		{
			if (abs(this->Data[r][current_x]) > maxNum)
			{
				maxNum = abs(this->Data[r][current_x]);
				maxRow = r;
			}
		}

		if (!maxNum)
		{
			--current_y;
			continue;
		}

		// Swap maxRow to current row
		for (unsigned int c = current_x; c < this->Data[0].size(); ++c)
		{
			double temp = this->Data[current_y][c];
			this->Data[current_y][c] = this->Data[maxRow][c];
			this->Data[maxRow][c] = temp;
		}

		// Doing elimination
		for (unsigned int r = current_y + 1; r < this->Data.size(); ++r)
		{
			if (!this->Data[r][current_x])
			{
				continue;
			}

			for (unsigned int c = current_x + 1; c < this->Data[0].size(); ++c)
			{
				this->Data[r][c] -= (this->Data[current_y][c] * this->Data[r][current_x] / this->Data[current_y][current_x]);
			}
			this->Data[r][current_x] = 0;
		}
	}
}
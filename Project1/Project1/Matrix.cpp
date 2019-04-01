#include "Matrix.h"
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

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
			throw MATRIX_ERROR::NON_SINGULAR;

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
			if (-10E-12 < A.Data[y][x] && A.Data[y][x] < 10E-12)
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
	else if (this->Data.size() != 2 && this->Data.size() != 3)
	{
		throw MATRIX_ERROR::EIGEN_DIMENSION_ERROR;
	}

	std::vector<double> eigenValues;
	std::vector<std::vector<double>> eigenVectors;
	std::vector<Matrix> result;
	std::vector<double> tempEigenVector;
	Matrix tempMatrix[2];

	// Find eigenvalues and eigenvectors
	if (this->Data.size() == 2)
	{
		// | A00 - D      A01 |
		// | A10      A11 - D |
		// D^2 + bD + c = 0
		// a = 1
		// b = (-A11) + (-A00)
		// c = A00 * A11 - A01 * A10
		double b, c;
		b = -this->Data[0][0] - this->Data[1][1];
		c = this->Data[0][0] * this->Data[1][1] - this->Data[0][1] * this->Data[1][0];

		// Get eigenvalues by Quadric Equation
		eigenValues.push_back((-b + sqrt(b * b - 4 * c)) / 2);
		eigenValues.push_back((-b - sqrt(b * b - 4 * c)) / 2);

		// Get eigenvectors
		tempEigenVector.push_back(this->Data[0][1]);
		tempEigenVector.push_back(eigenValues[0] - this->Data[0][0]);
		eigenVectors.push_back(tempEigenVector);

		tempEigenVector.clear();
		tempEigenVector.push_back(this->Data[1][1] - eigenValues[1]);
		tempEigenVector.push_back(this->Data[1][0]);
		eigenVectors.push_back(tempEigenVector);
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
		double b, c, d, q, r, t;
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
		eigenValues.push_back(-2 * sqrt(q) * cos(t / 3) - b / 3);
		eigenValues.push_back(-2 * sqrt(q) * cos((t + 2 * M_PI) / 3) - b / 3);
		eigenValues.push_back(-2 * sqrt(q) * cos((t - 2 * M_PI) / 3) - b / 3);
		
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

			if (A.Data[1][1] == 0)
			{
				// (A - DnI) = 
				// | a00 a01 a02 |
				// |   0   0 a12 |
				// |   0   0   0 |
				// x0 = a01
				// x1 = -a00
				// x2 = 0
				tempEigenVector.push_back(A.Data[0][1]);
				tempEigenVector.push_back(-A.Data[0][0]);
				tempEigenVector.push_back(0);
				eigenVectors.push_back(tempEigenVector);
			}
			else
			{
				// (A - DnI) = 
				// | a00 a01 a02 |
				// |   0 a11 a12 |
				// |   0   0   0 |
				// x0 = (a11 * a02 - a12 * a01) / a00
				// x1 = a12
				// x2 = -a11
				tempEigenVector.push_back((A.Data[1][1] * A.Data[0][2] - A.Data[1][2] * A.Data[0][1]) / A.Data[0][0]);
				tempEigenVector.push_back(A.Data[1][2]);
				tempEigenVector.push_back(-A.Data[1][1]);
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
	tempMatrix[0].trans();

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
	return std::vector<Matrix>();
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
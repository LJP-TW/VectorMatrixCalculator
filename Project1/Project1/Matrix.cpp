#include "Matrix.h"
#include <cstdlib>

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
		double maxNum = A.Data[current][current];
		unsigned int maxRow = current;
		for (unsigned int r = current + 1; r < A.Data.size(); ++r)
		{
			if (abs(A.Data[r][current]) > maxNum)
			{
				maxNum = A.Data[r][current];
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
			for (unsigned int c = current + 1; c < A.Data[0].size(); ++c)
			{
				A.Data[r][c] -= ((A.Data[current][c] * A.Data[r][current] / A.Data[current][current]));
			}
			for (unsigned int c = 0; c < B.Data[0].size(); ++c)
			{
				B.Data[r][c] -= ((B.Data[current][c] * A.Data[r][current] / A.Data[current][current]));
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

double Matrix::rank()
{
	return 0.0;
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
	return 0.0;
}

Matrix Matrix::inverse()
{
	return Matrix();
}

Matrix Matrix::adj()
{
	return Matrix();
}

std::vector<Matrix> Matrix::eigen()
{
	return std::vector<Matrix>();
}

std::vector<Matrix> Matrix::pm()
{
	return std::vector<Matrix>();
}

Matrix leastsquare(const Matrix & A, const Matrix & B)
{
	return Matrix();
}

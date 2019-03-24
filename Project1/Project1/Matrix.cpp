#include "Matrix.h"

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

Matrix Matrix::operator/(const Matrix & m)
{
	return Matrix();
}

double Matrix::rank()
{
	return 0.0;
}

Matrix Matrix::trans()
{
	return Matrix();
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

Matrix leastsquare(Matrix & A, Matrix & B)
{
	return Matrix();
}

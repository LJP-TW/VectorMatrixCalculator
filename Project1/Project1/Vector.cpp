#include "Vector.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define PI 3.14159265
constexpr auto THRESHOLD = 10E-12;

Vector::Vector()
{
}

Vector::Vector(double d)
{
	this->Data.push_back(d);
}

//////沒處理0
Vector Vector::operator+(const Vector & v)
{
	// 判斷是否可以相加 --> 維度必須相同
	if (this->Data.size() != v.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Vector result = *this;
	
	for (unsigned int i = 0; i < result.Data.size(); ++i)
	{
		result.Data[i] += v.Data[i];
	}

	return result;
}

Vector Vector::operator-(const Vector & v)
{
	// 判斷是否可以相減 --> 維度必須相同
	if (this->Data.size() != v.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Vector result = *this;

	for (unsigned int i = 0; i < result.Data.size(); ++i)
	{
		result.Data[i] -= v.Data[i];
	}

	return result;
}

Vector Vector::operator*(const Vector & v)
{
	// 判斷是否可以求 dot --> 維度必須相同
	// 或其中一方為 scalar --> 其中一方維度必須等於 1
	if (this->Data.size() != 1 && v.Data.size() != 1 && this->Data.size() != v.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Vector result;

	if (this->Data.size() == 1)
	{
		result = v;

		for (unsigned int i = 0; i < result.Data.size(); ++i)
		{
			result.Data[i] *= this->Data[0];
		}
		
	}
	else if (v.Data.size() == 1)
	{
		result = *this;

		for (unsigned int i = 0; i < result.Data.size(); ++i)
		{
			result.Data[i] *= v.Data[0];
		}
	}
	else
	{
		double dot = 0;

		for (unsigned int i = 0; i < this->Data.size(); ++i)
		{
			dot += this->Data[i] * v.Data[i];
		}

		result.Data.push_back(dot);
	}

	return result;
}

double Vector::norm() const
{
	double mag = 0.0;
	for (unsigned int i = 0;i < this->Data.size();i++)
	{
		mag += pow(this->Data[i], 2);
	}
	mag = sqrt(mag);
	return mag;
}

Vector Vector::normal()
{
	Vector result;
	for (unsigned int i = 0;i < this->Data.size();i++)
	{
		result.Data.push_back(this->Data[i] / this->norm());
	}
	return result;
}

Vector cross(const Vector& A, const Vector& B)
{
	// 判斷是否可以求 cross --> 維度必須為3
	// 或其中一方為 0 --> 結果為0
	if (A.Data.size() != 3 || B.Data.size() != 3 )
	{
		if ((A.Data.size() == 1 && A.Data[0] == 0) || (B.Data.size() == 1 && B.Data[0] == 0)) {}
		else
		{
			throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
		}
	}
	Vector result;
	if (A.Data.size() == 1 || B.Data.size() == 1)
	{
		result.Data.push_back(0);
	}
	else
	{
		double temp = 0.0;
		temp = A.Data[1] * B.Data[2] - A.Data[2] * B.Data[1];//i
		result.Data.push_back(temp);
		temp = 0.0;
		temp = A.Data[0] * B.Data[2] - A.Data[2] * B.Data[0];//j
		temp *= -1;
		result.Data.push_back(temp);
		temp = 0.0;
		temp = A.Data[0] * B.Data[1] - A.Data[1] * B.Data[0];//k
		result.Data.push_back(temp);
	}

	return result;
}

double com(const Vector& A,const Vector& B)//comp=(A dot B)/ ||B||
{
	// 判斷是否可以計算comp --> 維度必須相同
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double comp = 0.0, mag=0.0;//magnitude
	
	for (unsigned int i = 0; i < A.Data.size(); ++i)
	{
		comp += A.Data[i] * B.Data[i];
	}
	
	comp /= B.norm();
	return comp;
}

Vector proj(const Vector& A, const Vector& B)
{
	// 判斷是否可以計算proj --> 維度必須相同
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double dot = 0.0,mag=0.0;
	Vector result;
	for (unsigned int i = 0; i < A.Data.size(); ++i)
	{
		dot += A.Data[i] * B.Data[i];
		mag += pow(B.Data[i], 2);
	}
	dot /= mag;
	for (unsigned int i = 0;i < B.Data.size();i++)
	{
		result.Data.push_back(dot*B.Data[i]);
	}
	return result;
}

double area(const Vector& A, const Vector& B)//  area=1/2 || A cross B ||
{
	// 判斷是否可以計算area(triangle) --> 維度必須為3
	//if (A.Data.size() != 3||B.Data.size()!=3)
	//{
	//	throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	//}
	Vector result;
	Vector p;
	double area=0.0;
	
	area = A.norm() * B.norm() * sin(angle(A, B) * M_PI / 180) / 2;

	//result = cross(A, B);
	//area = result.norm();
	//area /= 2;
	return area;
}

bool isparallel(const Vector& A, const Vector& B)
{

	// 判斷是否可以求 cross --> 維度必須為3
	if (A.Data.size() != B.Data.size() )
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	else
	{
		double sclar = 0.0;
		bool isparallel = true;
		for (unsigned int i = 0;i < A.Data.size();i++)
		{
			if (A.Data[i] != 0 && B.Data[i] != 0)
			{
				if (sclar == 0)
				{
					sclar = A.Data[i] / B.Data[i];
				}
				else
				{
					if (sclar != A.Data[i] / B.Data[i])
					{
						return false;
					}
				}
			}
			else
			{
				if (A.Data[i] != B.Data[i])
				{
					return false;
				}
			}
		}
		return isparallel;

	}
}

bool isorthogonal(const Vector& A, const Vector& B)
{
	// 判斷是否垂直 --> 維度必須相同   //垂直-->dot=0
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double dot = 0.0;
	for (unsigned int i = 0;i < A.Data.size();i++)
	{
		dot += A.Data[i] * B.Data[i];
	}
	if (dot == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double angle(const Vector& A, const Vector& B)
{
	// 求angle --> 維度必須相同
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double dot = 0.0, normA = 0.0,normB=0.0;//A dot B =||A|| ||B|| cos-->反推求角度
	for (unsigned int i = 0;i < A.Data.size();i++)
	{
		dot += A.Data[i] * B.Data[i];
		normA += pow(A.Data[i], 2);
		normB += pow(B.Data[i], 2);
	}
	normA = sqrt(normA);
	normB = sqrt(normB);
	
	dot = dot / (normA*normB);//arc cos
	dot = acos(dot);//angle(弧度)
	dot = dot * 180 / M_PI;//angle(degree)
	return dot;
}

Vector pn(const Vector& A, const Vector& B)
{
	return cross(A,B);
}


std::vector<Vector> ob(std::vector<Vector> vectors)
{
	std::vector<Vector> result;
	Vector ans;
	for (unsigned int i = 0;i < vectors.size();i++)
	{
		ans = vectors[i];
		for (unsigned int j = 0;j < i;j++)
		{
			ans =ans-proj(vectors[i], result[j]);
		}

		
		result.push_back(ans.normal());
	}
	return result;
}

bool isln(std::vector<Vector> vectors)
{
	if (vectors.size() == 0)
	{
		return false;
	}

	unsigned int d = vectors[0].Data.size();
	for (unsigned int i = 1; i < vectors.size(); ++i)
	{
		if (vectors[i].Data.size() != d)
		{
			throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
		}
	}

	bool result = false;

	// Gaussian elimination to get r.e.f.
	for (unsigned int current_y = 0, current_x = 0; \
		current_y < vectors.size() && current_x < vectors[0].Data.size(); \
		++current_y, ++current_x)
	{
		// Search for maximum in this column
		double maxNum = abs(vectors[current_y].Data[current_x]);
		unsigned int maxRow = current_y;
		for (unsigned int r = current_y + 1; r < vectors.size(); ++r)
		{
			if (abs(vectors[r].Data[current_x]) > maxNum)
			{
				maxNum = abs(vectors[r].Data[current_x]);
				maxRow = r;
			}
		}

		if (!maxNum)
		{
			--current_y;
			continue;
		}

		// Swap maxRow to current row
		Vector temp = vectors[current_y];
		vectors[current_y] = vectors[maxRow];
		vectors[maxRow] = temp;

		// Doing elimination
		for (unsigned int r = current_y + 1; r < vectors.size(); ++r)
		{
			if (!vectors[r].Data[current_x])
			{
				continue;
			}

			vectors[r] = vectors[r] - vectors[current_y] * Vector(vectors[r].Data[current_x] / vectors[current_y].Data[current_x]);
		}
	}

	for (unsigned int y = 0; y < vectors.size(); ++y)
	{
		for (unsigned int x = 0; x < vectors[0].Data.size(); ++x)
		{
			// threshold
			if (abs(vectors[y].Data[x]) < THRESHOLD)
			{
				vectors[y].Data[x] = 0;
			}
		}
	}

	// Check if 0 row exist
	for (int x = vectors[0].Data.size() - 1; x >= 0; --x)
	{
		if (vectors[vectors.size() - 1].Data[x] != 0)
		{
			result = true;
			break;
		}
	}

	return result;
}

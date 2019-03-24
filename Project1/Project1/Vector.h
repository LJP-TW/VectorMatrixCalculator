#pragma once
#include <iostream>
#include <vector>

//定義向量資料結構
class Vector
{
public:
	Vector();

	std::string Name;
	std::vector<double> Data;

	/*
	 * 以下為 Vector 能操作的行為
	 * 皆可能會 throw 
	 * - DIMENSION_NON_EQUIVALENT
	 */

	/*
	 * Addition
	 */
	Vector operator +(const Vector& v);

	/*
	 * Subtraction
	 */
	Vector operator -(const Vector& v);

	/*
	 * Dot or Scalar multiplication
	 */
	Vector operator *(const Vector& v);
	double norm();
	double normal();
	friend Vector cross(const Vector& A, const Vector& B);
	friend double com(const Vector& A, const Vector& B);
	friend Vector proj(const Vector& A, const Vector& B);
	friend double area(const Vector& A, const Vector& B);
	friend bool isparallel(const Vector& A, const Vector& B);
	friend bool isorthogonal(const Vector& A, const Vector& B);
	friend double angle(const Vector& A, const Vector& B);
	friend Vector pn(const Vector& A, const Vector& B);
	friend bool isln(const Vector& A, const Vector& B);
	friend std::vector<Vector> ob(std::vector<Vector> vectors);
};

// 定義相關錯誤
enum class VECTOR_ERROR {
	DIMENSION_NON_EQUIVALENT
};
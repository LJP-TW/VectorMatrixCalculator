#pragma once
#include "Vector.h"
#include "Matrix.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	//儲存矩陣資料
	std::vector<Matrix> Matrices;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadVectorData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	//運算向量資料
	Vector VectorCalculate(System::String^ command);
	//讀取矩陣資料
	bool LoadMatrixData();
	//取得矩陣資料
	std::vector<Matrix> GetMatrices();
	//運算矩陣資料
	Matrix MatrixCalculate(System::String^ command);
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
};

// 定義相關錯誤
enum class DATA_MANAGER_ERROR {
	VARIABLE_NOT_FOUND // 找不到變數
};
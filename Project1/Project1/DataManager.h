#pragma once
#include "Vector.h"
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
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();
	//讀取向量資料
	bool LoadVectorData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
	//運算向量資料
	Vector Calculate(System::String^ command);
};
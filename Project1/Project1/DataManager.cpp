#include"DataManager.h"
#include <stack>

using System::String;
using namespace System::Collections::Generic;
using std::stack;

DataManager::DataManager()
{
	VectorVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//先清除 Vectors 相關資料
		this->Vectors.clear();
		this->VectorVariableIndex = 0;

		//向量總數
		unsigned int n;
		//定義讀取檔案字串暫存變數
		std::string tempSring;
		//從檔案讀取字串，解析向量總數
		fin >> n;
		
		for (unsigned int i = 0; i < n; ++i)
		{
			//定義暫存向量資料結構
			Vector tempVector;
			int dimension;

			//解析掉向量標記"V"
			fin >> tempSring;
			//從檔案讀取字串，解析向量維度
			fin >> dimension;

			//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
			std::string vectorVariableTemp = "$v" + std::to_string(i);
			tempVector.Name = vectorVariableTemp;

			//讀取向量資料
			for (unsigned int j = 0; j < dimension; ++j)
			{
				double value;
				fin >> value;
				tempVector.Data.push_back(value);
			}

			Vectors.push_back(tempVector);
		}

		//讀取成功回傳false
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}
void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

Vector DataManager::Calculate(String^ command)
{
	List<String^> postfix;
	Stack<String^> ops;
	stack<Vector> result;

	//將command依空白切割
	array<String^> ^userCommand = command->Split(' ');

	//排成後序法
	for (unsigned int i = 0; i < userCommand->Length; ++i)
	{
		if (userCommand[i] == gcnew String("(") || userCommand[i] == gcnew String("*"))
		{
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String("+"))
		{
			while (ops.Count != 0 && ops.Peek() == gcnew String("*"))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String(")"))
		{
			while (ops.Count != 0 && ops.Peek() != gcnew String("("))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Pop();
		}
		else
		{
			postfix.Add(userCommand[i]);
		}
	}
	while (ops.Count != 0)
	{
		postfix.Add(ops.Peek());
		ops.Pop();
	}

	//運算後序法
	try 
	{
		for (unsigned int i = 0; i < postfix.Count; ++i)
		{
			if (postfix[i] == gcnew String("+"))
			{
				Vector temp = result.top();
				result.pop();
				result.top() = result.top() + temp;
			}
			else if (postfix[i] == gcnew String("*"))
			{
				Vector temp = result.top();
				result.pop();
				result.top() = result.top() * temp;
			}
			else
			{
				// 代表 postfix[i] 是 Vector 名稱
				// 尋找對應變數 放進 stack result
				for (unsigned int j = 0; j < Vectors.size(); ++j)
				{
					if (postfix[i] == gcnew String(Vectors[j].Name.c_str()))
					{
						result.push(Vectors[j]);
						break;
					}
				}
			}
		}
	}
	catch (...)
	{
		throw;
	}
	
	return result.top();
}


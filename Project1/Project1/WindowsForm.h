#pragma once
#include"DataManager.h"
#include"DotNetUtilities.h"

enum Mode { VECTOR_MODE, MATRIX_MODE };

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm 的摘要
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			nowMode = VECTOR_MODE;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged_Vector);
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged_Matrix);
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;




	private: System::Windows::Forms::TextBox^  Output;

	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  DataLabel;

	private: System::Windows::Forms::ListBox^  DataList;
	private: System::Windows::Forms::OpenFileDialog^  openVectorFileDialog;



	private:
		DataManager* dataManager;
		String^ userInput;
		Mode nowMode;
	private: System::Windows::Forms::ToolStripMenuItem^  loadMatrixToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openMatrixFileDialog;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;


			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
			 /// 這個方法的內容。
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
				 this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->loadMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->InputLabel = (gcnew System::Windows::Forms::Label());
				 this->Input = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->Output = (gcnew System::Windows::Forms::TextBox());
				 this->DataLabel = (gcnew System::Windows::Forms::Label());
				 this->DataList = (gcnew System::Windows::Forms::ListBox());
				 this->openVectorFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->openMatrixFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->menuStrip2->SuspendLayout();
				 this->tableLayoutPanel1->SuspendLayout();
				 this->tableLayoutPanel3->SuspendLayout();
				 this->tableLayoutPanel4->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // menuStrip2
				 // 
				 this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
				 this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
				 this->menuStrip2->Location = System::Drawing::Point(0, 0);
				 this->menuStrip2->Name = L"menuStrip2";
				 this->menuStrip2->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
				 this->menuStrip2->Size = System::Drawing::Size(1022, 27);
				 this->menuStrip2->TabIndex = 1;
				 this->menuStrip2->Text = L"menuStrip2";
				 // 
				 // FileToolStripMenuItem
				 // 
				 this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->LoadVectorToolStripMenuItem,
						 this->loadMatrixToolStripMenuItem
				 });
				 this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
				 this->FileToolStripMenuItem->Size = System::Drawing::Size(45, 23);
				 this->FileToolStripMenuItem->Text = L"File";
				 // 
				 // LoadVectorToolStripMenuItem
				 // 
				 this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
				 this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(168, 26);
				 this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
				 this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
				 // 
				 // loadMatrixToolStripMenuItem
				 // 
				 this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
				 this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(168, 26);
				 this->loadMatrixToolStripMenuItem->Text = L"Load Matrix";
				 this->loadMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadMatrixToolStripMenuItem_Click);
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->ColumnCount = 1;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 77.38636F)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 690)));
				 this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
				 this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 0);
				 this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel1->Location = System::Drawing::Point(0, 27);
				 this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 2;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 114)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(1022, 475);
				 this->tableLayoutPanel1->TabIndex = 2;
				 // 
				 // InputLabel
				 // 
				 this->InputLabel->AutoSize = true;
				 this->InputLabel->Dock = System::Windows::Forms::DockStyle::Left;
				 this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->InputLabel->Location = System::Drawing::Point(4, 0);
				 this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->InputLabel->Name = L"InputLabel";
				 this->InputLabel->Size = System::Drawing::Size(48, 21);
				 this->InputLabel->TabIndex = 0;
				 this->InputLabel->Text = L"Input";
				 // 
				 // Input
				 // 
				 this->Input->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->Input->Location = System::Drawing::Point(4, 25);
				 this->Input->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Input->Multiline = true;
				 this->Input->Name = L"Input";
				 this->Input->Size = System::Drawing::Size(994, 75);
				 this->Input->TabIndex = 1;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Dock = System::Windows::Forms::DockStyle::Left;
				 this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->label1->Location = System::Drawing::Point(142, 0);
				 this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(61, 16);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"Output";
				 // 
				 // Output
				 // 
				 this->Output->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->Output->Location = System::Drawing::Point(142, 20);
				 this->Output->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Output->Multiline = true;
				 this->Output->Name = L"Output";
				 this->Output->ReadOnly = true;
				 this->Output->Size = System::Drawing::Size(856, 337);
				 this->Output->TabIndex = 1;
				 // 
				 // DataLabel
				 // 
				 this->DataLabel->AutoSize = true;
				 this->DataLabel->Dock = System::Windows::Forms::DockStyle::Left;
				 this->DataLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 this->DataLabel->Location = System::Drawing::Point(4, 0);
				 this->DataLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->DataLabel->Name = L"DataLabel";
				 this->DataLabel->Size = System::Drawing::Size(43, 16);
				 this->DataLabel->TabIndex = 2;
				 this->DataLabel->Text = L"Data";
				 // 
				 // DataList
				 // 
				 this->DataList->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->DataList->FormattingEnabled = true;
				 this->DataList->ItemHeight = 15;
				 this->DataList->Location = System::Drawing::Point(4, 20);
				 this->DataList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->DataList->Name = L"DataList";
				 this->DataList->Size = System::Drawing::Size(130, 337);
				 this->DataList->TabIndex = 3;
				 // 
				 // openVectorFileDialog
				 // 
				 this->openVectorFileDialog->FileName = L"openVectorFileDialog";
				 this->openVectorFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openVectorFileDialog_FileOk);
				 // 
				 // openMatrixFileDialog
				 // 
				 this->openMatrixFileDialog->FileName = L"openMatrixFileDialog";
				 this->openMatrixFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openMatrixFileDialog_FileOk);
				 // 
				 // tableLayoutPanel3
				 // 
				 this->tableLayoutPanel3->ColumnCount = 1;
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel3->Controls->Add(this->Input, 0, 1);
				 this->tableLayoutPanel3->Controls->Add(this->InputLabel, 0, 0);
				 this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel3->Location = System::Drawing::Point(10, 361);
				 this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(10, 0, 10, 10);
				 this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				 this->tableLayoutPanel3->RowCount = 2;
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.19231F)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 79.80769F)));
				 this->tableLayoutPanel3->Size = System::Drawing::Size(1002, 104);
				 this->tableLayoutPanel3->TabIndex = 3;
				 // 
				 // tableLayoutPanel4
				 // 
				 this->tableLayoutPanel4->ColumnCount = 2;
				 this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 13.77953F)));
				 this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 86.22047F)));
				 this->tableLayoutPanel4->Controls->Add(this->Output, 1, 1);
				 this->tableLayoutPanel4->Controls->Add(this->DataList, 0, 1);
				 this->tableLayoutPanel4->Controls->Add(this->label1, 1, 0);
				 this->tableLayoutPanel4->Controls->Add(this->DataLabel, 0, 0);
				 this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel4->Location = System::Drawing::Point(10, 0);
				 this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
				 this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				 this->tableLayoutPanel4->RowCount = 2;
				 this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.709141F)));
				 this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 95.29086F)));
				 this->tableLayoutPanel4->Size = System::Drawing::Size(1002, 361);
				 this->tableLayoutPanel4->TabIndex = 4;
				 // 
				 // WindowsForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1022, 502);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->Controls->Add(this->menuStrip2);
				 this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
				 this->Name = L"WindowsForm";
				 this->Text = L"EM_Project";
				 this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
				 this->menuStrip2->ResumeLayout(false);
				 this->menuStrip2->PerformLayout();
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->tableLayoutPanel3->ResumeLayout(false);
				 this->tableLayoutPanel3->PerformLayout();
				 this->tableLayoutPanel4->ResumeLayout(false);
				 this->tableLayoutPanel4->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//開啟Dialog
		nowMode = VECTOR_MODE;
		openVectorFileDialog->ShowDialog();
	}
	private: System::Void LoadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//開啟Dialog
		nowMode = MATRIX_MODE;
		openMatrixFileDialog->ShowDialog();
	}
	private: System::Void Input_TextChanged_Vector(System::Object^  sender, System::EventArgs^  e)
	{
		if (nowMode != VECTOR_MODE)
			return;

		// 當 File 選擇 Load Vector 時, this->Input->TextChanged 事件會執行此 function
		//當Input textbox中的輸入改變時，便會進入此函式
		//判斷輸入自元為'\n'，並防止取到字串-1位置
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//取得向量資料
			std::vector<Vector> vectors = dataManager->GetVectors();
			//定意輸出暫存	
			String^ outputTemp = "";
			//將使用者輸入字串(在userInput中)，依第一個空白切割成兩個子字串
			array<Char>^ delims = { ' ' };
			array<String^> ^userCommand = userInput->Split(delims, 2);
			//字串比較，若指令為"print"的情況
			try
			{
				if (userCommand[0] == "print")
				{
					//交給DataManager處理
					Vector result = dataManager->VectorCalculate(userCommand[1]);
					//輸出
					outputTemp += "[";
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "norm")
				{
					//先交給DataManager處理裡面
					Vector temp = dataManager->VectorCalculate(userCommand[1]);
					//輸出
					outputTemp += "[";
					outputTemp += temp.norm().ToString();
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "normal")
				{
					//先交給DataManager處理裡面
					Vector temp = dataManager->VectorCalculate(userCommand[1]);
					//輸出
					outputTemp += "[";
					outputTemp += temp.normal().ToString();
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "cross")
				{
					// cross(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					Vector result = cross(variable_a, variable_b);
					//輸出
					outputTemp += "[";
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "com")
				{
					// com(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					//輸出
					outputTemp += "[";
					outputTemp += com(variable_a, variable_b).ToString();
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "proj")
				{
					// proj(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					Vector result = proj(variable_a, variable_b);
					//輸出
					outputTemp += "[";
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "area")
				{
					// area(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					//輸出
					outputTemp += "[";
					outputTemp += area(variable_a, variable_b).ToString();
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "isparallel")
				{
					// isparallel(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					//輸出
					if (isparallel(variable_a, variable_b))
					{
						outputTemp += "Yes";
					}
					else
					{
						outputTemp += "No";
					}
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "isorthogonal")
				{
					// isorthogonal(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					//輸出
					if (isorthogonal(variable_a, variable_b))
					{
						outputTemp += "Yes";
					}
					else
					{
						outputTemp += "No";
					}
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "angle")
				{
					// angle(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					//輸出
					outputTemp += "theta = ";
					outputTemp += angle(variable_a, variable_b).ToString();
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "pn")
				{
					// pn(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Vector variable_a = dataManager->VectorCalculate(variables[0]);
					Vector variable_b = dataManager->VectorCalculate(variables[1]);
					Vector result = pn(variable_a, variable_b);
					//輸出
					outputTemp += "[";
					for (unsigned int i = 0; i < result.Data.size(); ++i)
					{
						outputTemp += result.Data[i].ToString();
						if (i != result.Data.size() - 1)
							outputTemp += ",";
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "isli")
				{
					// isli(A, B, ...)
					// 依據 ',' 分割
					std::vector<Vector> vectors;
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims);
					// 所有 variable 分別交給 DataManager 處理
					for (unsigned int i = 0; i < variables->Length; ++i)
					{
						vectors.push_back(dataManager->VectorCalculate(variables[i]));
					}
					//輸出
					if (isln(vectors))
					{
						outputTemp += "Y";
					}
					else
					{
						outputTemp += "N";
					}
					outputTemp += Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "ob")
				{
					// ob(A, B, ....)
					// 依據 ',' 分割
					std::vector<Vector> vectors, result;
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims);
					// 所有 variable 分別交給 DataManager 處理
					for (unsigned int i = 0; i < variables->Length; ++i)
					{
						vectors.push_back(dataManager->VectorCalculate(variables[i]));
					}
					result = ob(vectors);
					//輸出
					outputTemp += "normal " + result.size().ToString() + Environment::NewLine;
					for (unsigned int i = 0; i < result.size(); ++i)
					{
						outputTemp += "[";
						for (unsigned int j = 0; j < result[i].Data.size(); ++j)
						{
							outputTemp += result[i].Data[j].ToString();
							if (j != result[i].Data.size() - 1)
								outputTemp += ",";
						}
						outputTemp += "]" + Environment::NewLine;
					}
					outputTemp += Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				//都沒有 則判斷找不到指令
				else
				{
					Output->AppendText("-Command not found-" + Environment::NewLine);
				}
			}
			catch (VECTOR_ERROR e)
			{
				switch (e)
				{
				case VECTOR_ERROR::DIMENSION_NON_EQUIVALENT:
					Output->AppendText("Error: Dimension non equivalent.");
					break;
				}
				Output->AppendText(Environment::NewLine);
			}
			userInput = "";
		}
		else
		{
			//將使用者輸入字串(在Text box中)，依'\n'作切割
			array<String^> ^userCommand = Input->Text->Split('\n');
			//並將最後一行，作為目前使用者輸入指令
			userInput = userCommand[userCommand->Length - 1];
		}

	}
	private: System::Void Input_TextChanged_Matrix(System::Object^  sender, System::EventArgs^  e)
	{
		if (nowMode != MATRIX_MODE)
			return;
		// 當 File 選擇 Load Matrix 時, this->Input->TextChanged 事件會執行此 function
		//當Input textbox中的輸入改變時，便會進入此函式
		//判斷輸入自元為'\n'，並防止取到字串-1位置
		if (Input->Text->Length - 1 >= 0 && Input->Text[Input->Text->Length - 1] == '\n')
		{
			//取得矩陣資料
			std::vector<Matrix> matrixs = dataManager->GetMatrices();
			//定意輸出暫存	
			String^ outputTemp = "";
			//將使用者輸入字串(在userInput中)，依第一個空白切割成兩個子字串
			array<Char>^ delims = { ' ' };
			array<String^> ^userCommand = userInput->Split(delims, 2);
			//字串比較，若指令為"print"的情況
			try
			{
				if (userCommand[0] == "print")
				{
					//交給DataManager處理
					Matrix result = dataManager->MatrixCalculate(userCommand[1]);
					//輸出
					outputTemp += "[";
					for (unsigned int y = 0; y < result.Data.size(); ++y)
					{
						for (unsigned int x = 0; x < result.Data[y].size(); ++x)
						{
							outputTemp += result.Data[y][x].ToString();
							if (x != result.Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != result.Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "rank")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					//輸出
					outputTemp += "[";
					outputTemp += temp.rank().ToString();
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "trans")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					temp = temp.trans();
					//輸出
					outputTemp += "[";
					for (unsigned int y = 0; y < temp.Data.size(); ++y)
					{
						for (unsigned int x = 0; x < temp.Data[y].size(); ++x)
						{
							outputTemp += temp.Data[y][x].ToString();
							if (x != temp.Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != temp.Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "det")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					//輸出
					outputTemp += "[";
					outputTemp += temp.det().ToString();
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "inverse")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					temp = temp.inverse();
					//輸出
					outputTemp += "[";
					for (unsigned int y = 0; y < temp.Data.size(); ++y)
					{
						for (unsigned int x = 0; x < temp.Data[y].size(); ++x)
						{
							outputTemp += temp.Data[y][x].ToString();
							if (x != temp.Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != temp.Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "adj")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					temp = temp.adj();
					//輸出
					outputTemp += temp.Data.size().ToString();
					outputTemp += " ";
					outputTemp += temp.Data[0].size().ToString() + Environment::NewLine;
					outputTemp += "[";
					for (unsigned int y = 0; y < temp.Data.size(); ++y)
					{
						for (unsigned int x = 0; x < temp.Data[y].size(); ++x)
						{
							outputTemp += temp.Data[y][x].ToString();
							if (x != temp.Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != temp.Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "eigen")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					// eigen[0] 代表 Eigen Vector(v), eigen[1] 代表 Eigen Value(d)
					std::vector<Matrix> eigen = temp.eigen();
					//輸出
					outputTemp += "v = " + Environment::NewLine;
					outputTemp += "[";
					for (unsigned int y = 0; y < eigen[0].Data.size(); ++y)
					{
						for (unsigned int x = 0; x < eigen[0].Data[y].size(); ++x)
						{
							outputTemp += eigen[0].Data[y][x].ToString();
							if (x != eigen[0].Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != eigen[0].Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine;
					outputTemp += "d = " + Environment::NewLine;
					outputTemp += "[";
					for (unsigned int y = 0; y < eigen[1].Data.size(); ++y)
					{
						for (unsigned int x = 0; x < eigen[1].Data[y].size(); ++x)
						{
							outputTemp += eigen[1].Data[y][x].ToString();
							if (x != eigen[1].Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != eigen[1].Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "pm")
				{
					//先交給DataManager處理
					Matrix temp = dataManager->MatrixCalculate(userCommand[1]);
					// eigen[0] 代表 Eigen Vector(v), eigen[1] 代表 Eigen Value(d)
					std::vector<Matrix> eigen = temp.pm();
					//輸出
					outputTemp += "v = " + Environment::NewLine;
					outputTemp += "[";
					for (unsigned int y = 0; y < eigen[0].Data.size(); ++y)
					{
						for (unsigned int x = 0; x < eigen[0].Data[y].size(); ++x)
						{
							outputTemp += eigen[0].Data[y][x].ToString();
							if (x != eigen[0].Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != eigen[0].Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine;
					outputTemp += "d = " + Environment::NewLine;
					outputTemp += "[";
					for (unsigned int y = 0; y < eigen[1].Data.size(); ++y)
					{
						for (unsigned int x = 0; x < eigen[1].Data[y].size(); ++x)
						{
							outputTemp += eigen[1].Data[y][x].ToString();
							if (x != eigen[1].Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != eigen[1].Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				else if (userCommand[0] == "leastsquare")
				{
					// leastsquare(A, B)
					// 分割 A, B
					array<Char>^ delims = { ',' };
					array<String^> ^variables = userInput->Split(delims, 2);
					// A, B 分別交給DataManager處理
					Matrix variable_a = dataManager->MatrixCalculate(variables[0]);
					Matrix variable_b = dataManager->MatrixCalculate(variables[1]);
					Matrix result = leastsquare(variable_a, variable_b);
					//先交給DataManager處理
					//輸出
					outputTemp += result.Data.size().ToString();
					outputTemp += " ";
					outputTemp += result.Data[0].size().ToString() + Environment::NewLine;
					outputTemp += "[";
					for (unsigned int y = 0; y < result.Data.size(); ++y)
					{
						for (unsigned int x = 0; x < result.Data[y].size(); ++x)
						{
							outputTemp += result.Data[y][x].ToString();
							if (x != result.Data[y].size() - 1)
								outputTemp += ",";
						}
						if (y != result.Data.size() - 1)
							outputTemp += Environment::NewLine;
					}
					outputTemp += "]" + Environment::NewLine + Environment::NewLine;
					Output->AppendText(outputTemp);
				}
				//都沒有 則判斷找不到指令
				else
				{
					Output->AppendText("-Command not found-" + Environment::NewLine);
				}
			}
			catch (MATRIX_ERROR e)
			{
				switch (e)
				{
				case MATRIX_ERROR::DIMENSION_NON_EQUIVALENT:
					Output->AppendText("Error: Dimension non equivalent.");
					break;
				case MATRIX_ERROR::EIGEN_DIMENSION_ERROR:
					Output->AppendText("Error: eigen() now only supports for lower than 3D matrices.");
					break;
				case MATRIX_ERROR::MULTIPLICATION_DIMENSION_ERROR:
					Output->AppendText("Error: Matrix multiplication dimension error.");
					break;
				case MATRIX_ERROR::NON_DIAGONALIZABLE:
					Output->AppendText("Error: Matrix is non-diagonalizable.");
					break;
				case MATRIX_ERROR::NON_SQUARE:
					Output->AppendText("Error: Matrix is non-square.");
					break;
				case MATRIX_ERROR::ROW_DIMENSION_NON_EQUIVALENT:
					Output->AppendText("Error: Number of row of A and B must be same when solving Ax=B.");
					break;
				case MATRIX_ERROR::SINGULAR:
					Output->AppendText("Error: Matrix is singular.");
					break;
				default:
					break;
				}
				Output->AppendText(Environment::NewLine);
			}
			userInput = "";
		}
		else
		{
			//將使用者輸入字串(在Text box中)，依'\n'作切割
			array<String^> ^userCommand = Input->Text->Split('\n');
			//並將最後一行，作為目前使用者輸入指令
			userInput = userCommand[userCommand->Length - 1];
		}
	}
	private: System::Void openVectorFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//在Dialog按下OK便會進入此函式
		//字串轉制string^ to string
		std::string tempFileName;
		MarshalString(openVectorFileDialog->FileName, tempFileName);
		//將檔案路徑名稱傳入dataManager
		dataManager->SetFileName(tempFileName);
		//讀取向量資料
		if (dataManager->LoadVectorData())
		{
			//將DataList中項目先做清除
			DataList->Items->Clear();
			//取得所有向量資料
			std::vector<Vector> vectors = dataManager->GetVectors();

			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//項目格式:
				// name(dimension) [data1, data2, ...]

				//將檔案名稱存入暫存
				std::string tempString = vectors[i].Name;
				//將輸出格式存入暫存
				tempString += "(";
				//將向量維度存入暫存
				tempString += std::to_string(vectors[i].Data.size());
				//將輸出格式存入暫存
				tempString += ") [";
				//將向量資料存入暫存
				for (unsigned int j = 0; j < vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//將輸出格式存入暫存
				tempString += "]";
				//將項目加入DataList中
				DataList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->AppendText("-Vector datas have been loaded-" + Environment::NewLine);
		}
	}
	private: System::Void openMatrixFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		//在Dialog按下OK便會進入此函式
		//字串轉制string^ to string
		std::string tempFileName;
		MarshalString(openMatrixFileDialog->FileName, tempFileName);
		//將檔案路徑名稱傳入dataManager
		dataManager->SetFileName(tempFileName);
		//讀取矩陣資料
		if (dataManager->LoadMatrixData())
		{
			//將DataList中項目先做清除
			DataList->Items->Clear();
			//取得所有向量資料
			std::vector<Matrix> matrices = dataManager->GetMatrices();

			for (unsigned int i = 0; i < matrices.size(); i++)
			{
				//項目格式:
				// name(dimension x dimension)

				//將檔案名稱存入暫存
				std::string tempString = matrices[i].Name;
				//將輸出格式存入暫存
				tempString += "(";
				//將矩陣 row 存入暫存
				tempString += std::to_string(matrices[i].Data.size());
				//將輸出格式存入暫存
				tempString += " x ";
				//將矩陣 column 存入暫存
				tempString += std::to_string(matrices[i].Data[0].size());
				//將輸出格式存入暫存
				tempString += ")";
				//將項目加入DataList中
				DataList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->AppendText("-Matrix datas have been loaded-" + Environment::NewLine);
		}
	}
	};
}
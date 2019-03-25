#pragma once
#include"DataManager.h"
#include"DotNetUtilities.h"

enum Mode {VECTOR_MODE, MATRIX_MODE};

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


	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;

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
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel4;

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
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->DataLabel = (gcnew System::Windows::Forms::Label());
			this->DataList = (gcnew System::Windows::Forms::ListBox());
			this->openVectorFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openMatrixFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1311, 24);
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
			this->FileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->FileToolStripMenuItem->Text = L"File";
			// 
			// LoadVectorToolStripMenuItem
			// 
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			// 
			// loadMatrixToolStripMenuItem
			// 
			this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
			this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->loadMatrixToolStripMenuItem->Text = L"Load Matrix";
			this->loadMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadMatrixToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				77.38636F)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 91)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1311, 795);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->InputLabel);
			this->flowLayoutPanel3->Controls->Add(this->Input);
			this->flowLayoutPanel3->Location = System::Drawing::Point(3, 707);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(1305, 85);
			this->flowLayoutPanel3->TabIndex = 2;
			// 
			// InputLabel
			// 
			this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(3, 0);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(41, 16);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(3, 19);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(1293, 65);
			this->Input->TabIndex = 1;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->tableLayoutPanel2);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(1305, 698);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.48331F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				87.51669F)));
			this->tableLayoutPanel2->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->flowLayoutPanel4, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1302, 695);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label1);
			this->flowLayoutPanel1->Controls->Add(this->Output);
			this->flowLayoutPanel1->Location = System::Drawing::Point(165, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1134, 689);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Location = System::Drawing::Point(3, 19);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(1125, 664);
			this->Output->TabIndex = 1;
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->DataLabel);
			this->flowLayoutPanel4->Controls->Add(this->DataList);
			this->flowLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(156, 689);
			this->flowLayoutPanel4->TabIndex = 3;
			// 
			// DataLabel
			// 
			this->DataLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DataLabel->AutoSize = true;
			this->DataLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->DataLabel->Location = System::Drawing::Point(3, 0);
			this->DataLabel->Name = L"DataLabel";
			this->DataLabel->Size = System::Drawing::Size(36, 16);
			this->DataLabel->TabIndex = 2;
			this->DataLabel->Text = L"Data";
			// 
			// DataList
			// 
			this->DataList->FormattingEnabled = true;
			this->DataList->ItemHeight = 12;
			this->DataList->Location = System::Drawing::Point(3, 19);
			this->DataList->Name = L"DataList";
			this->DataList->Size = System::Drawing::Size(153, 664);
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
			// WindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1311, 819);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
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
				else if (userCommand[0] == "rref")
				{
					// TODO
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
				case MATRIX_ERROR::MULTIPLICATION_DIMENSION_ERROR:
					Output->AppendText("Error: Matrix multiplication dimension error.");
					break;
				case MATRIX_ERROR::ROW_DIMENSION_NON_EQUIVALENT:
					Output->AppendText("Error: Number of row of A and B must be same when solving Ax=B.");
					break;
				default:
					break;
				}
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

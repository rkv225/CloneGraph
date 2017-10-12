#pragma once

namespace cloneGraphGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Threading;
	using namespace System::Text;

	/// <summary>
	/// Summary for GraphDisplay
	/// </summary>
	public ref class GraphDisplay : public System::Windows::Forms::Form
	{
	public:
		//user defined properties
		List<List<int>^> adjListOrg;//adjacency list
		List<System::Drawing::Point> graphPoints;//coordinates of nodes
		List<int> visited;
		array<int>^ stack;
		int stackTop;
		int numOfPoints;
	private: System::Windows::Forms::Label^  label3;
	public:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Button^  button1;
	public:
		void push(int x)
		{
			stack[++stackTop] = x;
		}

		int pop()
		{
			return stack[stackTop--];
		}

		GraphDisplay(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pictureBox1->Image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox2->Image = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
			numOfPoints = 0;
			adjListOrg.Clear();
			visited.Clear();
			stack = gcnew array<int>(50);
			stackTop = -1;
			label6->Text = "";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GraphDisplay()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(490, 388);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphDisplay::pictureBox1_MouseClick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(513, 41);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(490, 388);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(225, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Original Graph";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(775, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Cloned Graph";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(40, 453);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Source:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(182, 453);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Destination:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(357, 448);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Add Edge";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GraphDisplay::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(668, 438);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(222, 42);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Clone Graph";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GraphDisplay::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(100, 450);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(36, 20);
			this->textBox2->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(263, 450);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(36, 20);
			this->textBox3->TabIndex = 12;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(928, 448);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GraphDisplay::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(522, 451);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Source Node:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(598, 448);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 20);
			this->textBox1->TabIndex = 15;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(525, 21);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"label6";
			// 
			// GraphDisplay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1015, 503);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"GraphDisplay";
			this->Text = L"GraphDisplay";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Point mouseLocation = Point(e->X, e->Y);
	graphPoints.Add(mouseLocation);
	adjListOrg.Add(gcnew List<int>());
	Graphics^ g = Graphics::FromImage(pictureBox1->Image);
	g->FillEllipse(System::Drawing::Brushes::Red, mouseLocation.X, mouseLocation.Y, 10, 10);
	g->DrawString(numOfPoints.ToString(), gcnew System::Drawing::Font("Arial",16), gcnew System::Drawing::SolidBrush(Color::Black), mouseLocation.X, (mouseLocation.Y - 15));
	numOfPoints++;
	pictureBox1->Refresh();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	int source = Convert::ToInt32(textBox2->Text);
	int destination = Convert::ToInt32(textBox3->Text);
	adjListOrg[source]->Add(destination);
	Graphics^ g = Graphics::FromImage(pictureBox1->Image);
	g->DrawLine(System::Drawing::Pens::Blue, graphPoints[source], graphPoints[destination]);
	g->FillEllipse(System::Drawing::Brushes::Blue, graphPoints[destination].X - 5, graphPoints[destination].Y - 5, 5, 5);
	pictureBox1->Refresh();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	int sourceNode = Convert::ToInt32(textBox1->Text);
	DrawNodes();
	TraverseNode(sourceNode);
	/*if (visited.Count < numOfPoints)
	{
		label6->Text = "Graph is not Strongly Connected";
	}
	else
	{
		label6->Text = "Graph is strongly connected";
	}*/
}
		 void TraverseNode(int x)
		 {
			 if (!visited.Contains(x))
			 {
				 array<int> ^node = adjListOrg[x]->ToArray();
				 for (int i = 0; i < adjListOrg[x]->Count; i++)
				 {
					 DrawEdge(x, node[i]);
					 if (!visited.Contains(node[i]))
					 {
						 push(node[i]);
					 }
				 }
			 }
			 
			 if (stackTop != -1)
			 {
				 visited.Add(x);
				 TraverseNode(pop());
			 }
		 }

		 void DrawNodes()
		 {
			 for (int i = 0; i < numOfPoints; i++)
			 {
				 Graphics^ g = Graphics::FromImage(pictureBox2->Image);
				 g->FillEllipse(System::Drawing::Brushes::Red, graphPoints[i].X, graphPoints[i].Y, 10, 10);
				 g->DrawString(i.ToString(), gcnew System::Drawing::Font("Arial", 16), gcnew System::Drawing::SolidBrush(Color::Black), graphPoints[i].X, (graphPoints[i].Y - 15));
			 }
			 pictureBox2->Refresh();
		 }
		 
		 void DrawEdge(int from, int to)
		 {
			 Graphics^ g = Graphics::FromImage(pictureBox2->Image);
			 g->DrawLine(System::Drawing::Pens::Blue, graphPoints[from], graphPoints[to]);
			 g->FillEllipse(System::Drawing::Brushes::Blue, graphPoints[to].X - 5, graphPoints[to].Y - 5, 5, 5);
			 System::Threading::Thread::Sleep(1000);
			 pictureBox2->Refresh();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	pictureBox1->Image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	pictureBox2->Image = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height);
	numOfPoints = 0;
	adjListOrg.Clear();
	visited.Clear();
	stack = gcnew array<int>(50);
	stackTop = -1;
}
};
}

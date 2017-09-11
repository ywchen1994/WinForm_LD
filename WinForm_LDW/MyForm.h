#pragma once
#include"cv.h"
#include"highgui.h"
using namespace cv;
 char *filename = "20150210-130128CO.avi";
 CvCapture *cap;
 IplImage *frame;
 typedef std::vector<Vec4i> Vtr4i;
namespace WinForm_LDW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Btn_Start;
	protected:

	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: 


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadFileToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Btn_Start = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->loadFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// Btn_Start
			// 
			this->Btn_Start->Location = System::Drawing::Point(975, 443);
			this->Btn_Start->Name = L"Btn_Start";
			this->Btn_Start->Size = System::Drawing::Size(87, 41);
			this->Btn_Start->TabIndex = 0;
			this->Btn_Start->Text = L"開始";
			this->Btn_Start->UseVisualStyleBackColor = true;
			this->Btn_Start->Click += gcnew System::EventHandler(this, &MyForm::Btn_Load_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(364, 329);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->loadFileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1074, 27);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// loadFileToolStripMenuItem
			// 
			this->loadFileToolStripMenuItem->Name = L"loadFileToolStripMenuItem";
			this->loadFileToolStripMenuItem->Size = System::Drawing::Size(80, 23);
			this->loadFileToolStripMenuItem->Text = L"LoadFile";
			this->loadFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadFileToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(918, 223);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(417, 30);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(364, 329);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1074, 549);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Btn_Start);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Btn_Load_Click(System::Object^  sender, System::EventArgs^  e) {
		cap = cvCaptureFromFile(filename);
		int frame_counter = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_COUNT);
		Thread ^ thread1 = gcnew Thread(gcnew ThreadStart(this, &MyForm::CapfromFile));
		thread1->Start();
		
	}
	private:void CapfromFile(void)
	{
		int total_frameNo = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_COUNT);
		int counter =1;
		
		while (true)
		{
			if (cvGrabFrame(cap))
			{
				//cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
				frame = cvRetrieveFrame(cap);
				Mat img = frame;	
				img = img(cv::Rect(cv::Point(0, 450), cv::Point(1255, 610)));
				Mat result=Pretreatment(img);
				cv::bitwise_and(img,result, img);
				counter++;
				System::String^ str = counter.ToString() + "/" + total_frameNo.ToString();
				SetLabelText(label1, str);
				ShowImage(pictureBox1, frame);
				ShowImage(pictureBox2, img);
			}
			else
			{
				counter++;
				System::String^ str = counter.ToString() + "/" + total_frameNo.ToString();
				break;
			}
		}
	}
	delegate void SetPictureDelegate(System::Windows::Forms::PictureBox^ PBox, cv::Mat Image);
	public:void ShowImage(System::Windows::Forms::PictureBox^ PBox, cv::Mat Image)
	{
		Mat image_Temp;
		switch (Image.type())
		{
		case CV_8UC3:
			image_Temp = Image;
			break;
		case CV_8UC1:
			cvtColor(Image, image_Temp, CV_GRAY2RGB);
			break;
		default:
			break;
		}
		resize(image_Temp, image_Temp,cv::Size(PBox->Width, PBox->Height));
		System::IntPtr ptr(image_Temp.ptr());
		System::Drawing::Graphics^ graphics = PBox->CreateGraphics();
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(image_Temp.cols, image_Temp.rows, image_Temp.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		System::Drawing::RectangleF rect(0, 0, PBox->Width, PBox->Height);
		graphics->DrawImage(b, rect);
		delete graphics;
	}
	private: System::Void loadFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ opnFileDlg = gcnew OpenFileDialog;
		opnFileDlg->DefaultExt = "*.wmv";  //預設副檔名
		if (opnFileDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			filename = (char*)(void*)Marshal::StringToHGlobalAnsi(opnFileDlg->FileName);
			
		}
		delete opnFileDlg;
	}
	delegate void SetLabelDelegate(Label^ obj, System::String^ text);
	private:void SetLabelText(Label^ obj, System::String^ text)
	{
		if (obj->InvokeRequired)
		{
			SetLabelDelegate^ d =
				gcnew SetLabelDelegate(this, &MyForm::SetLabelText);
			this->Invoke(d, gcnew array<Object^> {obj, text });
		}
		else
		{
			obj->Text = text;
		}
	}
	private:cv::Mat Pretreatment(Mat& src) {
		
		Mat img_gray;

		cvtColor(src, img_gray, CV_RGB2GRAY);
		Mat img_blur;
		GaussianBlur(img_gray, img_blur, cv::Size(5, 5), 0, 0);
		Mat edges;
		Canny(img_blur, edges, 70, 150);
	
		IplConvKernel *pKernel = NULL;
		pKernel = cvCreateStructuringElementEx(3, 3, 1, 1, CV_SHAPE_RECT, NULL);
		cvDilate(&(IplImage)edges, &(IplImage)edges, cvCreateStructuringElementEx(3, 3, 1, 1, CV_SHAPE_RECT, NULL), 1);

	
		Vector<cv::Point> TopLineCompensate, ButtomLineCompensate;
		for (size_t i = 0; i < edges.cols; i++)
		{
			if (cvGet2D(&(IplImage)edges, 1, i).val[0] > 0)TopLineCompensate.push_back(cv::Point(i, 1));
			if(cvGet2D(&(IplImage)edges,158,i).val[0] > 0)ButtomLineCompensate.push_back(cv::Point(i, 158));
		}
		if (TopLineCompensate.size() != 0)
		{
			for (size_t i = 0; i < TopLineCompensate.size() - 1; i++)
			{
				if ((TopLineCompensate[i + 1].x - TopLineCompensate[i].x) < 25)
					line(edges, TopLineCompensate[i], TopLineCompensate[i + 1], CV_RGB(255, 255, 255), 2);
			}
		}
		if (ButtomLineCompensate.size() != 0)
		{
			for (size_t i = 0; i < ButtomLineCompensate.size() - 1; i++)
			{
			if ((ButtomLineCompensate[i + 1].x - ButtomLineCompensate[i].x) < 40)
				line(edges, ButtomLineCompensate[i], ButtomLineCompensate[i + 1], CV_RGB(255, 255, 255), 2);
			}
		}
		Mat dst = Mat::zeros(img_gray.size(), CV_8UC3);
		vector<vector<cv::Point>> contours; // Vector for storing contour
		Vtr4i hierarchy;
		img_gray.release(); img_blur.release();
		findContours(edges, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE); // Find the contours in the image
		for (int i = 0; i < contours.size(); i++) // Iterate through each contour
		{
			drawContours(dst, contours, i, CV_RGB(255, 255, 255), CV_FILLED, 8, hierarchy);
		} 
		
		return dst;
	}
};
}

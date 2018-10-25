#pragma once
#include <Windows.h>
#include "ArregloCG.h"
#include "circuloG.h"
#include "circuloM.h"
#include "Jugador.h"


namespace Juego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		cg*obj1;
		cm*objm;
		cm*obj2m;
		Arrcg*arreglo;
		Jugador*objJugador;
		Direcciones teclapulsada;
		int tCG;
		int vCG;
		bool iCG;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
			 Graphics ^d;
	public:
		MyForm(void)
		{
			InitializeComponent();
			d = this->CreateGraphics();
			obj1 = new cg(d,5,5,100,50,5);
			objm = new cm(d,5,5,50,50,5);
			obj2m = new cm(d, 5, 5, 50, 50, 5);
			arreglo = new Arrcg();
			tCG = 0;
			vCG = 0;
			iCG = true;
			objJugador = new Jugador();
			teclapulsada = Direcciones::Ninguna;
			objJugador->set_x(100);
			objJugador->set_y(100);
			objJugador->cambiar_imagen("spritepng2.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{

		System::Drawing::Graphics^gr = this->CreateGraphics();
		SolidBrush^brocha = gcnew SolidBrush(Color::White);
		float a = gr->VisibleClipBounds.Width;
		float  l = gr->VisibleClipBounds.Height;
		gr->FillRectangle(brocha, 0, 0, (int)a, (int)l);

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
	private: System::Void eventLog1_EntryWritten(System::Object^  sender, System::Diagnostics::EntryWrittenEventArgs^  e) {
	
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics^gr = this->CreateGraphics();
	//crear hasta cierta cantidad;
		BufferedGraphicsContext^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = espacio->Allocate(gr, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		objJugador->Mover(buffer->Graphics, teclapulsada);
	
			objJugador->cambiar_dx_dy(teclapulsada);
			buffer->Render(gr);
			delete buffer;
			delete espacio;
			delete gr;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		teclapulsada = Direcciones::Ninguna;
		if (e->KeyCode == Keys::Up)
			teclapulsada = Direcciones::Arriba;
		if (e->KeyCode == Keys::Down)
			teclapulsada = Direcciones::Abajo;
		if (e->KeyCode == Keys::Left)
			teclapulsada = Direcciones::Izquierda;
		if (e->KeyCode == Keys::Right)
			teclapulsada = Direcciones::Derecha;

		objJugador->cambiar_dx_dy(teclapulsada);
	}
};
}

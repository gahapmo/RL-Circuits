#include "Elements.h"
#include <io.h>
#include <fcntl.h>
#include <iostream>
using namespace std;

Resistor::Resistor()
{
	this->R = 0;
}

Resistor::~Resistor()
{
}

Resistor::Resistor(double R)
{
	this->Z = this->R = R;
}

void Resistor::displayDetail()
{
	wcout << L"Điện trở:\n\tGiá trị điện trở: " << this->R << " Ohm\n";
}

void Resistor::input()
{
	wcout << L"\tNhập giá trị điện trở (đơn vị Ohm): ";
	wcin >> this->R;
	this->Z = this->R;
}

Inductor::Inductor()
{
	this->f = this->L = 0;
}

Inductor::~Inductor()
{
}

Inductor::Inductor(double f, double L)
{
	this->f = f;
	this->L = L;
}

void Inductor::displayDetail()
{
	wcout << L"Cuộn cảm:\n\tĐộ tự cảm: " << this->L << " H";
	wcout << L"\n\tTần số: " << this->f << " Hz\n";
}

void Inductor::input()
{
	wcout << L"\tNhập độ tự cảm (đơn vị H): ";
	wcin >> this->L;
	wcout << L"\tNhập tần số (đơn vị Hz): ";
	wcin >> this->f;
	this->Z = complex<double>(0, 2 * PI * this->f * this->L); //Z = i(2*pi*f*L)
}

//Capacitor::Capacitor()
//{
//	this->f = this->C = 0;
//}
//
//Capacitor::~Capacitor()
//{
//}
//
//Capacitor::Capacitor(double f, double C)
//{
//	this->f = f;
//	this->C = C;
//}
//
//void Capacitor::displayDetail()
//{
//	wcout << L"Tụ điện:\n\tĐiện dung: " << this->C << " F";
//	wcout << L"\n\tTần số: " << this->f << " Hz\n";
//}
//
//void Capacitor::input()
//{
//	wcout << L"\tNhập điện dung (đơn vị F): ";
//	wcin >> this->C;
//	wcout << L"\tNhập tần số (đơn vị Hz): ";
//	wcin >> this->f;
//	this->Z = 1 / (2 * PI * this->f * this->C);
//}

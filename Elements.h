#pragma once
#include "Element.h"
// Điện trở
class Resistor :
	public Element
{
public:
	Resistor();
	~Resistor();
	Resistor(double R);
	void displayDetail();
	void input();
	char typeOf() { return 'R'; }

private:
	double R; // Điện trở
};

// Cuộn cảm
class Inductor :
	public Element
{
public:
	Inductor();
	~Inductor();
	Inductor(double f, double L);
	void displayDetail();
	void input();
	char typeOf() { return 'L'; }

private:
	double f; // Tần số
	double L; // Độ tự cảm
};

// Tự điện
//class Capacitor :
//	public Element
//{
//public:
//	Capacitor();
//	~Capacitor();
//	Capacitor(double f, double C);
//	void displayDetail();
//	void input();
//	char typeOf() { return 'C'; }
//
//private:
//	double f; // Tần số
//	double C; // Điện dung
//};
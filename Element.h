#pragma once
#include <complex>
#include <math.h>
#define PI 3.14

//Thành phần của mạch
class Element
{
protected:
	//double Z; // Trở kháng của thành phần
	std::complex<double> Z;
public:
	Element();
	~Element();
	virtual void displayDetail() = 0;// Xuất thông tin của phần tử
	virtual void input() = 0;
	virtual char typeOf() = 0;
	std::complex<double> getZ() { return this->Z; }
};
#pragma once
#include "Element.h"
#include "Elements.h"
#include <vector>
// Mạch điện
class Circuits
{
private:
	std::vector<Element*> vectorElements; // vecto các phần tử được tạo
	std::vector<Element*> vectorEleInCircuits; // vecto các phần tử được thêm vào mạch
	std::wstring outputCircuit;
	int circuitsLen;
	//double Z; //Tổng trở
	std::complex<double> Z;
public:
	Circuits();
	~Circuits();
	void input();
	void inputByString();
	void output();
	void addSeries(Element*);
	void addParallel(Element*);
	std::wstring setCirString(int);
};


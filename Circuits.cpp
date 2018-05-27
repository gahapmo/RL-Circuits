#include "Circuits.h"
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


Circuits::Circuits()
{
	this->Z = 0;
	this->outputCircuit = L"";
	this->circuitsLen = 0;
}


Circuits::~Circuits()
{
}

void Circuits::input()
{
	bool check = false;
	wchar_t s;
	do {
		if (check) {
			wcout << L"Tiếp tục\n";
		}
		if (!check)
		{
			wcout << L"\t\t\t\t\t\tBÀI TẬP TÍNH TỔNG TRỞ CỦA MẠCH RLC\n";
			wcout << L"\t\t\t\tChương trình nhập vào một mạch RLC và tính tổng trở của mạch đó";
			wcout << L"\t\t\t\t\t\t\t\t\t\tBắt đầu\n\t\t\t\t\t\t";
			check = true;
		}

		system("pause");
		system("cls");
		wcout << L"Chọn một hành động để thực hiện: ";
		wcout << L"\n\t0 - In thông tin mạch";
		wcout << L"\n\t1 - Tạo ra một thành phần";
		wcout << L"\n\t2 - Thêm một thành phần vào mạch theo kiểu nối tiếp";
		wcout << L"\n\t3 - Thêm một thành phần vào mạch theo kiểu song song";
		wcout << L"\n\tx - Thoát khỏi chương trình";
		wcout << L"\nNhập lựa chọn: "; 
		wcin >> s;
		int len = this->vectorElements.size();
		switch (s)
		{
			case '0':
				this->output();
				break;
			case '1':
				wcout << L"Bạn muốn tạo (R, L): ";
				wchar_t type;
				do {
						wcin >> type;
				} while (type != 'R' && type != 'L');
				Element *tmp;
				switch (type)
				{
				case 'R': case 'r': tmp = new Resistor; break;
				default: tmp = new Inductor; break;
				}
				tmp->input();
				this->vectorElements.push_back(tmp);
				break;
			case '2':
				if (len == 0) {
					wcout << L"Danh sách rỗng";
				}
				wcout << L"Danh sách các phần tử đã được thêm:\n";
				for (int i = 0; i < len; i++)
				{
					wcout << "\t" << i << " - ";
					this->vectorElements[i]->displayDetail();
				}
				wcout << L"Chọn phần tử muốn thêm để mắc nối tiếp vào: ";
				wcin >> len;
				addSeries(this->vectorElements[len]);
				break;
			case '3':
				if (len == 0) {
					wcout << L"Danh sách rỗng\n";
				}
				wcout << L"Danh sách các phần tử đã được thêm:\n";
				for (int i = 0; i < len; i++)
				{
					wcout << "\t" << i << " - ";
					this->vectorElements[i]->displayDetail();
				}
				wcout << L"Chọn phần tử muốn thêm để mắc song song vào: ";
				wcin >> len;
				addParallel(this->vectorElements[len]);
				break;
		}

	} while (s != 'e');
}

void Circuits::inputByString()
{
	wcout << L"Cách nhập:";
	wcout << L"\n\t- Dòng đầu tiên nhập n là số phần tử điện khác nhau";
	wcout << L"\n\t- n dòng tiếp theo:";
	wcout << L"\n\t\t+ Nếu là R nhập ký tự R và giá trị điện trở (Ví dụ R 50)";
	wcout << L"\n\t\t+ Nếu là L nhập ký tự L và giá trị độ tự cảm và tấn số (Ví dụ L 0.5 50)";
	wcout << L"\n\t- Dòng cuối là biểu diễn quan hệ các phần tử, song song thì dùng dấu '/', nối tiếp dùng dấu '.' (Ví dụ: 1/2.3/4.5)";
}

void Circuits::output()
{
	wcout << L"\nTổng trở của mạch: " << abs(this->Z);
	int len = this->vectorEleInCircuits.size();
	if (len == 0) {
		wcout << L"\nDanh sách rỗng\n";
		return;
	}
	wcout << L"\nDanh sách các phần tử đã được thêm:\n";
	for (int i = 0; i < len; i++)
	{
		wcout << "\t" << i << " - ";
		this->vectorEleInCircuits[i]->displayDetail();
	}
	wcout << L"\n\nMạch hiện tại:\n";
	wcout << this->outputCircuit;
	wcout << L"\n";
}

void Circuits::addSeries(Element *ele)
{
	this->Z += ele->getZ();
	this->vectorEleInCircuits.push_back(ele);
	this->circuitsLen++;
	if (ele->typeOf() == 'R')
		this->outputCircuit += L".--R--.";
	else
		this->outputCircuit += L".--L--.";
}



void Circuits::addParallel(Element *ele)
{
	this->Z = this->Z * ele->getZ() / (this->Z + ele->getZ());
	this->vectorEleInCircuits.push_back(ele);
	if (ele->typeOf() == 'R')
		this->outputCircuit += L"\n|" + setCirString(this->circuitsLen) + L"R" + setCirString(this->circuitsLen) + L"|";
	else
		this->outputCircuit += L"\n|" + setCirString(this->circuitsLen) + L"L" + setCirString(this->circuitsLen) + L"|";
}

wstring Circuits::setCirString(int len)
{
	wstring s;
	if (len == 1)
		s = L"--";
	else
		s = L"---";
	while (len-- > 1)
	{
		s += L"---";
	}
	return s;
}

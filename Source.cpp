#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Circuits.h"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	Circuits *cir = new Circuits;
	cir->input();

	system("pause");
	return 0;
}
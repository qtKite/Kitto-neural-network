// Kitto Neural.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
	The pattern will be define as:

	[0.1] = 1
	[0.0] = 0
	[1.1] = 0
	[1.0] = 1

*/

int main()
{
	Matrix2x2 m1 = Matrix2x2({
		2,4,
		1,0
		});


	Maths::PrintMatrix(m1);

	std::cout << "Multyping by 2..." << std::endl;

	Maths::PrintMatrix(Maths::ScalarM(m1, 2));

	getchar();
	return 0;
}


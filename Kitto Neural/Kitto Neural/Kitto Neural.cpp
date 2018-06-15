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
		1,1,
		0,0
		});


	for (auto row = 0; row < m1.m_rows; row++) {
		for (auto col = 0; col < m1.m_columns; col++) {
			std::cout << m1.m_matrix[col][row];
		}
		std::cout << std::endl;
	}

	std::cout << "Transposing..." << std::endl;

	Matrix2x2 transposedm1 = Maths::Transpose(m1);

	for (auto row = 0; row < transposedm1.m_rows; row++) {
		for (auto col = 0; col < transposedm1.m_columns; col++) {
			std::cout << transposedm1.m_matrix[col][row];
		}
		std::cout << std::endl;
	}

	std::cout << "Transposing..." << std::endl;

	m1 = Maths::Transpose(transposedm1);


	for (auto row = 0; row < m1.m_rows; row++) {
		for (auto col = 0; col < m1.m_columns; col++) {
			std::cout << m1.m_matrix[col][row];
		}
		std::cout << std::endl;
	}

	getchar();
	return 0;
}


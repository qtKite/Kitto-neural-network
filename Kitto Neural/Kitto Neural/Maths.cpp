#include "stdafx.h"

namespace Maths {

	// https://en.wikipedia.org/wiki/Sigmoid_function

	double sigmoid(double x) {

#if 0
		return (1 / (1 + exp(-x)));
#else
		return (exp(x) / (exp(x) + 1));
#endif

	}

	Matrix2x2 Transpose(Matrix2x2 matrix)
	{
		Matrix2x2 tmp;
		// Row = X
		// Col = Y

		for (auto c = 0; c < matrix.m_columns; c++) {
			for (auto r = 0; r < matrix.m_rows; r++) {
				tmp.m_matrix[r][c] = matrix.m_matrix[c][r];
			}
		}

		tmp.m_rows = matrix.m_columns;
		tmp.m_columns = matrix.m_rows;

		return tmp;
	}

	void printMatrix(Matrix2x2 m) {

		for (auto row = 0; row < m.m_rows; row++) {
			for (auto col = 0; col < m.m_columns; col++) {
				std::cout << m.m_matrix[col][row];
			}
			std::cout << std::endl;
		}
	}

}
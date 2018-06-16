#include "stdafx.h"

namespace Maths {

	// https://en.wikipedia.org/wiki/Sigmoid_function

	double sigmoid(double x) {

#if 1
		return (1 / (1 + exp(-x)));
#else
		return (exp(x) / (exp(x) + 1));
#endif

	}

	double SigmodDerivative(double x)
	{
		return (x * (1 - x));
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

	Matrix2x2 DotMatrix(Matrix2x2 m1, Matrix2x2 m2)
	{

		std::vector<double> a;

		for (auto m1r = 0; m1r < 2; m1r++) {
			for (auto m2c = 0; m2c < 2; m2c++) {

				double b = 0;

				for (auto col_count = 0; col_count < 2; col_count++) {
					b += (m1.m_matrix[col_count][m1r] * m2.m_matrix[m2c][col_count]);
				}

				a.push_back(b);

			}
		}

		return Matrix2x2(a);

	}

	Matrix2x2 ScalarM(Matrix2x2 m, double scale)
	{
		Matrix2x2 tmp = m;

		for (auto row = 0; row < tmp.m_rows; row++) {
			for (auto col = 0; col < tmp.m_columns; col++) {
				tmp.m_matrix[col][row] *= scale;
			}
		}
		return tmp;
	}

	Matrix2x2 Scalar3D(Matrix2x2 m1, Matrix2x2 m2)
	{
		Matrix2x2 tmp;

		for (auto row = 0; row < tmp.m_rows; row++) {
			for (auto col = 0; col < tmp.m_columns; col++) {
				tmp.m_matrix[col][row] = m1.m_matrix[col][row] * m2.m_matrix[col][row];
			}
		}
		return tmp;
	}



	Matrix2x2 MatrixSubtract(Matrix2x2 m1, Matrix2x2 m2)
	{
		Matrix2x2 tmp;

		for (auto row = 0; row < tmp.m_rows; row++) {
			for (auto col = 0; col < tmp.m_columns; col++) {
				tmp.m_matrix[col][row] = m1.m_matrix[col][row] - m2.m_matrix[col][row];
			}
		}

		return tmp;
	}

	Matrix2x2 MatrixAddition(Matrix2x2 m1, Matrix2x2 m2)
	{
		Matrix2x2 tmp;

		for (auto row = 0; row < tmp.m_rows; row++) {
			for (auto col = 0; col < tmp.m_columns; col++) {
				tmp.m_matrix[col][row] = m1.m_matrix[col][row] + m2.m_matrix[col][row];
			}
		}
		return tmp;
	}


	Matrix2x2 SigmoidMatrix(Matrix2x2 m) {

		Matrix2x2 tmp = m;

		for (auto row = 0; row < tmp.m_rows; row++) {
			for (auto col = 0; col < tmp.m_columns; col++) {
				tmp.m_matrix[col][row] = sigmoid(tmp.m_matrix[col][row]);
			}
		}
		return tmp;
	}

	Matrix2x2 SigmoidDeriveMatrix(Matrix2x2 m) {

		Matrix2x2 tmp = m;

		for (auto row = 0; row < tmp.m_rows; row++) {
			for (auto col = 0; col < tmp.m_columns; col++) {
				tmp.m_matrix[col][row] = SigmodDerivative(tmp.m_matrix[col][row]);
			}
		}
		return tmp;
	}


	void PrintMatrix(Matrix2x2 m) {

		for (auto row = 0; row < m.m_rows; row++) {
			for (auto col = 0; col < m.m_columns; col++) {
				std::cout << " | " << m.m_matrix[col][row];
			}
			std::cout << std::endl;
		}
	}

}
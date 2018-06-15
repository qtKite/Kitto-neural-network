#pragma once

struct Matrix2x2
{
	// The matrix will go as follow 
	//	// Sample input { 1, 1 , 0 , 0}
	//	First row Values in 1st columns      -> 1 1
	//	Last row Values into 2nd column		 -> 0 0

	double m_matrix[2][2];

	Matrix2x2(std::vector<double> m = { 0,0,0,0 }) {

		auto i = 0;

		for (auto row = 0; row < 2; row++) {

			for (auto col = 0; col < 2; col++)
			{
				if (row < 1) {
					m_matrix[col][row] = m[col];
				}
				else {
					i++;
					m_matrix[col][row] = m[row + i];
				}
			}
		}

	}

	int m_rows = 2, m_columns = 2;
};

class CNeuralNetwork
{
public:

	double m_weights[2];
	double m_training[2];

};
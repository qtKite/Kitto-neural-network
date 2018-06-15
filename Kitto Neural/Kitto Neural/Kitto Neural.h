#pragma once

struct Matrix
{
	double m_matrix[2][2];
	int m_rows = 2, m_columns = 2;
};

class CNeuralNetwork
{
public:

	double m_weights[2];
	double m_training[2];

};
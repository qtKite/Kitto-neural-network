// Kitto Neural.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
#ifndef training
	std::vector<Matrix2x2> training;
	training.push_back(Matrix2x2({ 1, -1, -1, -1 }));
	training.push_back(Matrix2x2({ 1, 1, -1, -1 }));
	training.push_back(Matrix2x2({ -1, -1, -1, -1 }));
	training.push_back(Matrix2x2({ 1, -1, -1, -1 }));
	training.push_back(Matrix2x2({ 1, -1, 1, -1 }));
	training.push_back(Matrix2x2({ 1, 1, 1, 1 }));
	training.push_back(Matrix2x2({ -1, 0, 0, 0 }));
	training.push_back(Matrix2x2({ 1, 0, 0, 0 }));
	training.push_back(Matrix2x2({ 0, 1, 0, 0 }));


	std::vector<Matrix2x2> results;
	results.push_back(Matrix2x2({ 1, 0, 0, 0 }));
	results.push_back(Matrix2x2({ 1, 1, 0, 0 }));
	results.push_back(Matrix2x2({ 0, 0, 0, 0 }));
	results.push_back(Matrix2x2({ 1, 0, 0, 0 }));
	results.push_back(Matrix2x2({ 1, 0, 1, 0 }));
	results.push_back(Matrix2x2({ 1, 1, 1, 1 }));
	results.push_back(Matrix2x2({ 0, 1, 1, 1 }));
	results.push_back(Matrix2x2({ 1, 0, 0, 0 }));
	results.push_back(Matrix2x2({ 0, 1, 0, 0 }));




#if 0
	std::vector<double> training_results = { 1, 0, 0, 1 };
#endif

	Matrix2x2 weight = Matrix2x2({ 0.1, 0.1,  0.1,  0.1 });

	std::cout << "size: " << training.size() << std::endl;


	for (auto i = 0; i < 5000; i++) {

		for (auto len = 0; len < training.size(); len++) {

			Matrix2x2 output = Maths::SigmoidMatrix(Maths::DotMatrix(results[len], weight));

			Matrix2x2 error = Maths::MatrixSubtract(training[len], output);

			Matrix2x2 adjustment = Maths::DotMatrix(Maths::Transpose(training[len]), Maths::Scalar3D(error, Maths::SigmoidDeriveMatrix(output)));

			weight = Maths::MatrixAddition(weight, adjustment);
		}
	}

	// Done training
	// Give it a sample question
	Matrix2x2 sample = Matrix2x2({ -1, -1, 1, 1 });
	std::cout << "Sample: " << std::endl;
	Maths::PrintMatrix(sample);
	std::cout << "Answer: " << std::endl;
	Matrix2x2 test = Maths::SigmoidMatrix(Maths::DotMatrix(sample, weight));
	Maths::PrintMatrix(test);
#endif
	getchar();
	return 0;
}


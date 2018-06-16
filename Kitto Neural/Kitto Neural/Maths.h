#pragma once
#include "Kitto Neural.h"

namespace Maths
{
	void PrintMatrix(Matrix2x2 m);

	Matrix2x2 Transpose(Matrix2x2 matrix);
	Matrix2x2 ScalarM(Matrix2x2 m, double scale);
	Matrix2x2 SigmoidMatrix(Matrix2x2 m);
	Matrix2x2 SigmoidDeriveMatrix(Matrix2x2 m);
	Matrix2x2 DotMatrix(Matrix2x2 m1, Matrix2x2 m2);
	Matrix2x2 MatrixSubtract(Matrix2x2 m1, Matrix2x2 m2);
	Matrix2x2 MatrixAddition(Matrix2x2 m1, Matrix2x2 m2);
	Matrix2x2 Scalar3D(Matrix2x2 m1, Matrix2x2 m2);
}
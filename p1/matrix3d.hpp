#ifndef MATRIX3D_HPP
#define MATRIX3D_HPP
#include "polygon.hpp"
class Matrix3D{
	public:
		Matrix3D();
		Matrix3D(int a, int b, int c, int d, int e, int f, int h, int g, int i);
		~Matrix3D();
		Matrix3D(const Polygon& objToCopy);
		int Determinant();
		bool testMatrix();
		int GetValue(int a, int b);
	private:
		int *mat;
		int testPointX;
		int testPointY;
		int testMat[9];
		int vertices;
};




#endif

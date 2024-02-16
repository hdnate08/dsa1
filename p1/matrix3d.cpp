#include "matrix3d.hpp"
#include "polygon.hpp"
#include <iostream>
Matrix3D::Matrix3D(){
	mat = new int[9] {0};
}
Matrix3D::Matrix3D(int a, int b, int c, int d, int e, int f, int g, int h, int i){
		mat = new int[9] {a,b,c,d,e,f,g,h,i};
		testMat[0] = a;
		testMat[1] = b;
		testMat[2] = c;
		testMat[3] = d;
		testMat[4] = e;
		testMat[5] = f;
		testMat[6] = g;
		testMat[7] = h;
		testMat[8] = i;
}
Matrix3D::Matrix3D(const Polygon& objToCopy){ //Takes polygon object and converts all points into 1D array
	this->vertices = objToCopy.GetVertexCount() * 3;
	this->testPointX = objToCopy.getTestPointX();
	this->testPointY = objToCopy.getTestPointY();
	int counter = 0;

	mat = new int[this->vertices];

	for(int i = 0; i < this->vertices - 2; i+=3){
		mat[i] = 1;
		mat[i+1] = objToCopy.getPointX(counter);
		mat[i+2] = objToCopy.getPointY(counter);
		counter++;
	}
}
Matrix3D::~Matrix3D(){
delete []mat;
}
int Matrix3D::GetValue(int a, int b){
	int coordValue = mat[a*3 + b];
	return coordValue;
}
bool Matrix3D::testMatrix(){ //Creates a separate 9 input array for testing 2 points against a test point and passes it to determinant - does this for all vertices
	int inside = 0;
	for(int i = 0; i < (vertices / 3); i++){		
		if(i < (vertices / 3) - 1){
				for(int j = 0; j < 6; j++){
					testMat[j] = mat[(j)+(i*3)];
				}		
					testMat[6] = 1;
					testMat[7] = testPointX;
					testMat[8] = testPointY;
		}
		else{
			for(int j = 0; j < 6; j++){
				if(j < 3){
				testMat[j] = mat[(j)+(i*3)];
				}
				else{
				testMat[j] = mat[j-3];
				}
			}
		}
		if(Determinant() <= 0){
			inside++;
		}
	}
	if(inside == vertices/3){
		return true;
	}
	else{
		return false;
	}	
return false;
}
int Matrix3D::Determinant(){
	int determinant = ((testMat[4] * testMat[8]) - (testMat[5] * testMat[7])) - (testMat[1] * (testMat[8] - testMat[5])) + (testMat[2] * (testMat[7] - testMat[4]));
	return determinant;
}


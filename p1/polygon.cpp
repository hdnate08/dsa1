#include "polygon.hpp"
#include "matrix3d.hpp"
#include <iostream>
Polygon::Polygon(){
	vertices = 0;
	name = "";
	pts = NULL;
}
Polygon::Polygon(string name, Point points[], int vertices){
	this->name = name;
	this->vertices = vertices;
	pts = new Point[vertices];
	for(int i = 0; i < vertices; i++){
		pts[i] = Point(points[i]);
	}
}
Polygon::Polygon(const Polygon& objToCopy){
	this->name = objToCopy.name;
	this->vertices = objToCopy.vertices;
	pts = new Point[vertices];
	for(int i = 0; i < vertices; i++){
		pts[i] = Point(objToCopy.pts[i]);
	}
}
Polygon& Polygon::operator=(const Polygon& objToCopy){
	this->name = objToCopy.name;
	this->vertices = objToCopy.vertices;
	if(this == &objToCopy){
		return *this;
	}
	if(pts != NULL){
		delete [] pts;
		pts = new Point[vertices];
		for(int i = 0; i < vertices; i++){
			pts[i] = Point(objToCopy.pts[i]);
		}
	}
	return *this;
}
Polygon::~Polygon(){
	delete []pts;
}
bool Polygon::Contains(Point testPoint){	// Tests polygon object for testPoint by using 3x3 matrix determinant.
	if(this->vertices == 0){
		return false;
	}
	this->testPointX = testPoint.GetX();
	this->testPointY = testPoint.GetY();
	Matrix3D newMat(*this);
	if(newMat.testMatrix() == true){
		return true;
	}
	else{
		return false;
	}
}
void Polygon::outPoints(){
	for(int i = 0; i < vertices; i++){
		cout << getPointX(i) << " "<<getPointY(i) << endl;
	}
}
void Polygon::setVertices(int vertices){
	this->vertices = vertices;
}
void Polygon::setPoints(Point coords[]){
	delete []pts;
	pts = new Point[vertices];
	for(int i = 0; i < vertices; i++){
		pts[i] = Point(coords[i]);
	}
}









#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "point.hpp"
#include <string>
class Polygon {
	public:
		Polygon();//constructor
		Polygon(string name, Point points[], int vertices);//paramaterized constructor
		Polygon(const Polygon& objToCopy);//copy constructor
		Polygon& operator=(const Polygon& objToCopy);//copy assignment operator
		~Polygon();//destructor
		int GetVertexCount() const {return this->vertices;};
		string GetName() {return this->name;};
		bool Contains(Point testPoint);
		void outPoints();
		int getTestPointX() const {return testPointX;};
		int getTestPointY() const {return testPointY;};
		int getPointX(int a) const {return pts[a].GetX();};
		int getPointY(int a) const {return pts[a].GetY();};
		void setName(string name) {this->name = name;};
		void setPoints(Point points[]);
		void setVertices(int vertices);
	private:
		int vertices;
		string name;
		Point *pts;
		int testPointX;
		int testPointY;
};
#endif

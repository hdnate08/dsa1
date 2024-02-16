#include "point.hpp"

Point::Point(){
	this->x=0;
	this->y=0;
}
Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}
Point::Point(const Point& objToCopy){
	this->x = objToCopy.x;
	this->y = objToCopy.y;
}
Point& Point::operator=(const Point& objToCopy){
	this->x = objToCopy.x;
	this->y = objToCopy.y;
	return *this;
}
int Point::GetX(){
	return x;
}
int Point::GetY(){
	return y;
}

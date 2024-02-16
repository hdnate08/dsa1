#ifndef POINT_HPP
#define POINT_HPP

using namespace std;

class Point {
	public:
		Point();
		Point(int x, int y);
		Point(const Point& objToCopy);
		Point& operator=(const Point& objToCopy);
		int GetX();
		int GetY();
		void SetX(int x) {this->x=x;};
		void SetY(int y) {this->y=y;};
	private:
		int x, y;
};
#endif

#ifndef GIS_HPP
#define GIS_HPP
#include "point.hpp"
#include "polygon.hpp"
#include <fstream>
#include <string>
using namespace std;
class GIS
{
	public:
		bool ReadFile(string fileName);
		void CloseFile() {in.close();};
		string GetParcel(Point testPoint);
		void getnumShapes();
		void createArray();
		void fillArray();
		void fillPts();
		void printAll();
		static string NOT_FOUND;
//		~GIS();
	private:
		ifstream in;
		string fileName;
		int numShapes = 0;
		Polygon *shapes;
		Point *coords;
};
#endif 

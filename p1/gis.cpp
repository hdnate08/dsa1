#include "gis.hpp"
#include <iostream>
using namespace std;
bool GIS::ReadFile(string fileName){
	in.open(fileName);
	if(in.is_open()){
		createArray();
		return true;
	}
	return false;
}
string GIS::GetParcel(Point testPoint){
	string name = NOT_FOUND;
	for(int i = 0; i < numShapes; i++){
		if(shapes[i].Contains(testPoint)){
			name = shapes[i].GetName();
		}
	}
	return name;
}
void GIS::createArray(){
	getnumShapes();
	shapes = new Polygon[numShapes];
	in.clear();
	in.seekg(0);
	fillArray();
}
void GIS::getnumShapes(){
	string unused;
	while(getline(in, unused)){
		numShapes++;
	}
}
void GIS::fillArray(){
	int count = 0, p = 0, vertices, x = 0;
	string name;
	in >> name;
	while(!in.fail()){
		while(!in.fail()){
			in >> x;
			if(in.fail()){
				continue;
			}
			else{
				count++;
			}
		}
		vertices = count / 2;
		shapes[p].setName(name);
		shapes[p].setVertices(vertices);
		count = 0;
		in.ignore();
		in.clear();
		p++;
		in >> name;
	}
	fillPts();
}

void GIS::fillPts(){
	int j = 0, x = 0, y = 0;
	string unused;
	in.clear();
	in.seekg(0);
	in >> unused;
	for(int i = 0; i < numShapes; i++){
		coords = new Point[shapes[i].GetVertexCount()];
		while(!in.fail()){
			in >> x;
			if(in.fail()){
				continue;
			}
			in >> y;
			coords[j] = Point(x,y);
			j++;
		}
		shapes[i].setPoints(coords);
		j = 0;
		x = 0;
		y = 0;
		in.clear();
		in.ignore();
		in >> unused;
	}
}

void GIS::printAll(){
	for(int i = 0; i < numShapes; i++){
	shapes[i].outPoints();
	cout << endl;
	}
}
string GIS::NOT_FOUND = "Query point not present in any known parcel";

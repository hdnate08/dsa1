#include <iostream>
#include <string>
#include "gis.hpp"
using namespace std;

int main(){
	int x,y;
	GIS input;
	string fileName;

	cout << "Please enter the file with the polygon data: ";
	cin >> fileName;
	if(input.ReadFile(fileName) == true){
		input.createArray();
	}
	else{
		while(input.ReadFile(fileName) == false){
			cout << "Invalid file name!" << endl;
			cout << "Please enter the file with the polygon data: ";
			cin >> fileName;
			input.ReadFile(fileName);
		}
		input.createArray();
	}
	cout << endl <<endl;
	cout << "Coordinates of query point (non-integer quits)" << endl;
	cout << "x: ";
	cin >> x;
	cout << endl;
	while(!cin.fail()){
		cout << "y: ";
		cin >> y;
		cout << endl;
		cout << "Query point is inside: ";
		cout <<	input.GetParcel(Point(x,y)) << endl << endl;
		cout << "Coordinates of query point (non-integer quits)" << endl;
		cout << "x: ";
		cin >> x;
		cout << endl;
	}
	input.CloseFile();
	return 0;
}

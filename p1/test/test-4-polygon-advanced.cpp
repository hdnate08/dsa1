#include "catch/catch.hpp"
#include "../polygon.hpp"

TEST_CASE ("Advanced polygon tests")
{
	// prepare list of points to create square
	Point points[] = {Point(0,0), Point(0,2), Point(2,2), Point(2,0)};
	Polygon square("Awesome square", points, 4);
	Polygon empty;

	SECTION ("Check for point inside polygon with no vertices")
	{
		CHECK(false == empty.Contains(Point(1,1)));
	}

	SECTION ("Check for point inside polygon")
	{
		CHECK(true == square.Contains(Point(1,1)));
	}

	SECTION ("Check for point outside polygon")
	{
		CHECK(false == square.Contains(Point(-1,-1)));
	}

	SECTION ("Edge cases")
	{
		// at a vertex of the square
		CHECK(true == square.Contains(Point(0,2)));

		// on an edge of the square
		CHECK(true == square.Contains(Point(0,1)));
	}
}

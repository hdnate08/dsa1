#include "catch/catch.hpp"
#include "../gis.hpp"

TEST_CASE ("Testing container (GIS) operations")
{
	GIS taxMap;
	SECTION ("Check file availability")
	{
		REQUIRE(false == taxMap.ReadFile("zzzzz.zzzz"));
		REQUIRE(true == taxMap.ReadFile("simple-polygons.txt"));
	}

	SECTION ("Check point that isn't inside any of the polygons")
	{
		taxMap.ReadFile("simple-polygons.txt");
		CHECK(GIS::NOT_FOUND == taxMap.GetParcel(Point(-1,-1)));
	}

	SECTION ("Check for point inside polygon")
	{
		taxMap.ReadFile("simple-polygons.txt");
		CHECK("squareParcel" == taxMap.GetParcel(Point(1,1)));
		CHECK("wideRectangleParcel" == taxMap.GetParcel(Point(5,4)));
	}
}

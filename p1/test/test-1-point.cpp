#include "catch/catch.hpp"
#include "../point.hpp"

TEST_CASE ("Point Default Constructor")
{
	Point p; // default point - at origin (0,0)
	CHECK(0 == p.GetX());
	CHECK(0 == p.GetY());
}

TEST_CASE ("Point Parameterized Constructor")
{
	Point p(3,2);
	CHECK(3 == p.GetX());
	CHECK(2 == p.GetY());
}

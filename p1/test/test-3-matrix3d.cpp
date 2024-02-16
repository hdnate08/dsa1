#include "catch/catch.hpp"
#include "../matrix3d.hpp"

TEST_CASE ("Default Matrix")
{
	Matrix3D m;
	CHECK(0 == m.GetValue(0, 0));
}

TEST_CASE ("Specified Matrix")
{
	
	/*1 0 2
	1 2 0
	1 0 0*/
	

	Matrix3D m(1,0,2, 1,2,0, 1,0,0);
	CHECK(1 == m.GetValue(0, 0));
	CHECK(2 == m.GetValue(0, 2));
}

TEST_CASE ("Determinant for default matrix")
{
	Matrix3D m;
	CHECK(0 == m.Determinant());
}

TEST_CASE ("Determinant for specified matrix")
{
	Matrix3D m(1,0,2, 1,2,0, 1,0,0);
	// https://www.wolframalpha.com/input/?i=%7B%7B1%2C0%2C2%7D%2C%7B1%2C2%2C0%7D%2C%7B1%2C0%2C0%7D%7D
	CHECK(-4 == m.Determinant());
}


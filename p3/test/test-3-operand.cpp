#include "catch/catch.hpp"
#include "../node.hpp"
#include "../stack.hpp"
#include "../operand.hpp"

TEST_CASE("class Operand")
{
	Operand o("1234567");
	CHECK(false == o.IsNegative());
	CHECK("1234567" == o.GetValue());
	CHECK(7 == o.GetLengthOfString());

	o.Pad(4);
	CHECK("00001234567" == o.GetValue());

	o.SetValue("7654321");
	CHECK("7654321" == o.GetValue());

	Operand o2("-1234567");
	CHECK(true == o2.IsNegative());
	CHECK(8 == o2.GetLengthOfString());

	// need to be able to flip sign for subtracting negative
	o2.FlipSign();
	CHECK(false == o2.IsNegative());
	CHECK(7 == o2.GetLengthOfString());
}

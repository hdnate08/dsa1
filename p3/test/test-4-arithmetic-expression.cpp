#include<sstream>

#include "catch/catch.hpp"
#include "../node.hpp"
#include "../stack.hpp"
#include "../operand.hpp"
#include "../arithmetic-expression.hpp"

TEST_CASE("class ArithmeticExpression")
{
	ArithmeticExpression ae("1234567","23456",'+');
	std::ostringstream oss;
	oss << ae;
	CHECK("1234567 0023456 +" == oss.str());

	// clear output stream
	oss.str("");
	ArithmeticExpression aeNegative("1234567","-23456",'+');
	oss << aeNegative;
	CHECK("1234567 0023456 -" == oss.str());

	// clear output stream
	oss.str("");
	ArithmeticExpression aeDoubleNeg("1234567","-23456",'-');
	oss << aeDoubleNeg;
	CHECK("1234567 0023456 +" == oss.str());
}

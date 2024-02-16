#include<sstream>

#include "catch/catch.hpp"
#include "../node.hpp"
#include "../stack.hpp"
#include "../operand.hpp"
#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"
#include "../expression-reader.hpp"


TEST_CASE("class ExpressionReader")
{
	ExpressionReader er("expressions.txt");
	CHECK(true == er.ReadNextExpression());
	CHECK("12\n+5\n17" == er.ShowResult());

	er.ReadNextExpression();
	CHECK("  5\n+12\n 17" == er.ShowResult());

	er.ReadNextExpression();
	CHECK("12\n-5\n 7" == er.ShowResult());

	er.ReadNextExpression();
	CHECK("  5\n-12\n -7" == er.ShowResult());

	er.ReadNextExpression();
	CHECK(" 364287463834623846283426384\n+923742938742934723947239847\n1288030402577558570230666231" == er.ShowResult());

	er.ReadNextExpression();
	CHECK(" 364287463834623846283426384\n-923742938742934723947239847\n-559455474908310877663813463" == er.ShowResult());

	// no more expressions in file. Bad read should be safe
	CHECK(false == er.ReadNextExpression());
}

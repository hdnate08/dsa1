#include<sstream>

#include "catch/catch.hpp"
#include "../node.hpp"
#include "../stack.hpp"
#include "../operand.hpp"
#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"

TEST_CASE("class BigIntegerArithmetic")
{
	ArithmeticExpression * ae;

	if (std::stoi(std::getenv("PART")) == 1)
	{
		SECTION ("Simple sum")
		{
			ae = new ArithmeticExpression("200","100",'+');
			BigIntegerArithmetic bia(ae);
			CHECK(true == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
			CHECK(" 200\n+100\n 300" == bia.ShowResults());
			delete ae;
		}

		SECTION ("Bigger operand second")
		{
			ae = new ArithmeticExpression("100","200",'+');
			BigIntegerArithmetic bia(ae);
			CHECK(false == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
			delete ae;
		}

		SECTION ("Operands are equal")
		{
			ae = new ArithmeticExpression("200","200",'+');
			BigIntegerArithmetic bia(ae);
			CHECK(true == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
			delete ae;
		}

		SECTION ("1st operand much larger")
		{
			ae = new ArithmeticExpression("10000","900",'+');
			BigIntegerArithmetic bia(ae);
			CHECK(true == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
			delete ae;
		}

		SECTION ("2nd operand much larger")
		{
			ae = new ArithmeticExpression("200","1000",'+');
			BigIntegerArithmetic bia(ae);
			CHECK(false == bia.Op1IsBigger(ae->GetOp1()->GetValue(),ae->GetOp2()->GetValue()));
			delete ae;
		}
	}

	else if (std::stoi(std::getenv("PART")) == 2)
	{
		SECTION ("Large sum")
		{
			ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'+');
			BigIntegerArithmetic bia(ae);
			CHECK(" 364287463834623846283426384\n+923742938742934723947239847\n1288030402577558570230666231" == bia.ShowResults());
			delete ae;
		}

		SECTION ("Large subtraction")
		{
			ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'-');
			BigIntegerArithmetic bia(ae);
			CHECK(" 364287463834623846283426384\n-923742938742934723947239847\n-559455474908310877663813463" == bia.ShowResults());
			delete ae;
		}

		SECTION ("Subtracting larger - negative result")
		{
			ae = new ArithmeticExpression("200","-1000",'+');
			BigIntegerArithmetic bia(ae);
			REQUIRE("  200\n-1000\n -800" == bia.ShowResults());
			delete ae;
		}

		SECTION ("Double negative")
		{
			ae = new ArithmeticExpression("200","-1000",'-');
			BigIntegerArithmetic bia(ae);
			REQUIRE("  200\n+1000\n 1200" == bia.ShowResults());
			delete ae;
		}
	}
}

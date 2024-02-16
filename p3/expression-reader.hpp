#ifndef EXPRESSION_READER_HPP
#define EXPRESSION_READER_HPP
#include <string>
#include <fstream>
#include "arithmetic-expression.hpp"
#include "big-integer-arithmetic.hpp"

class ExpressionReader
{
	public:
		ExpressionReader();
		ExpressionReader(std::string inputFile);
		bool ReadNextExpression();
		std::string ShowResult();
	private:
		std::ifstream inFS;
		std::string op1;
		std::string op2;
		char op;
		ArithmeticExpression* ae;
		BigIntegerArithmetic* bia;
};
#endif

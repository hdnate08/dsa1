#ifndef BIG_INTEGER_ARITHMETIC_HPP
#define BIG_INTEGER_ARITHMETIC_HPP
#include "stack.hpp"
#include "arithmetic-expression.hpp"
#include <string>
#include <iomanip>
#include <iostream>

class BigIntegerArithmetic
{
	public:
		BigIntegerArithmetic();
		BigIntegerArithmetic(const ArithmeticExpression* input);//constructor which takes (ArithmeticExpression) as argument
		bool Op1IsBigger(std::string op1, std::string op2);//compare op1 and op2 -> decide which is bigger
		std::string ShowResults();
		void makeNegative(bool input) {this->negative = input;};
		bool GetNegative() {return this->negative;};
		int findLargest(std::string op1, std::string op2, std::string ans);
	private:
		Stack* operand1;
		Stack* operand2;
		Stack* answer;
		char op;
		std::string op1;
		std::string op2;
		std::string ans;
		bool negative;
};

#endif

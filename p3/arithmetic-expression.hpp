#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP
#include "operand.hpp"
#include <string>
#include <sstream>
class ArithmeticExpression
{
	public:
		ArithmeticExpression();
		ArithmeticExpression(std::string numOne, std::string numTwo, char op);
		~ArithmeticExpression();
		friend std::ostream& operator<<(std::ostream& os, const ArithmeticExpression& rhs);
		char GetOp() const {return this->op;};
		void problemSetup();
		Operand* GetOp1() const {return this->A;};
		Operand* GetOp2() const {return this->B;};
	private:
		char op;
		Operand* A;
		Operand* B;
};

#endif

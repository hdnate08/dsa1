#include "arithmetic-expression.hpp"
#include <iostream>
ArithmeticExpression::ArithmeticExpression()
{
	this->A = new Operand(0);
	this->B = new Operand(0);
	this->op = 'o';
}

ArithmeticExpression::ArithmeticExpression(std::string numOne, std::string numTwo, char op)
{
	this-> op = op;
	this->A = new Operand(numOne);
	this->B = new Operand(numTwo);
	problemSetup();
}

ArithmeticExpression::~ArithmeticExpression()
{
	delete this->A;
	delete this->B;
}

void ArithmeticExpression::problemSetup()
{
	
	if((A->IsNegative() && B->IsNegative()) || (!A->IsNegative() && B->IsNegative() && op == '+'))
	{	
		B->FlipSign();
		op = '-';
	}
	else if(!A->IsNegative() && B->IsNegative() && op == '-')
	{
		B->FlipSign();
		op = '+';
	}

	if(A->GetLengthOfString() > B->GetLengthOfString())
	{
		int temp = A->GetLengthOfString() - B->GetLengthOfString();
		B->Pad(temp);
	}
	else
	{
		int temp = B->GetLengthOfString() - A->GetLengthOfString();
		A->Pad(temp);
	}
}

std::ostream& operator<<(std::ostream& os, const ArithmeticExpression& rhs)
{
	os << rhs.A->GetValue() << " " << rhs.B->GetValue() << " " << rhs.op;
	return os;
}

#include "expression-reader.hpp"

ExpressionReader::ExpressionReader()
{
	this->op1 = "";
	this->op2 = "";
	this->op = '+';
	this->ae = new ArithmeticExpression;
	this->bia = new BigIntegerArithmetic;	
}

ExpressionReader::ExpressionReader(std::string inputFile)
{
	inFS.open(inputFile);

	if(!inFS.is_open())
	{	
		inFS.close();
	}
}

bool ExpressionReader::ReadNextExpression()
{
	//read first line into arithmetic expression then pass into big integer arithmetic
		std::string temp;
		std::getline(inFS, op1, ' ');
		if(inFS.eof())
		{
			return false;
		}

		std::getline(inFS, temp, ' '); //pull operator out as a string in order to use getline
		op = temp[0]; //convert operator string into char
		std::getline(inFS, op2);
		ae = new ArithmeticExpression(op1, op2, op);
		bia = new BigIntegerArithmetic(ae);
		return true;
}

std::string ExpressionReader::ShowResult()
{
	//call ShowResult() from big integer arithmetic
	return bia->ShowResults();
}

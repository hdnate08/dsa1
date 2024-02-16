#include "big-integer-arithmetic.hpp"

BigIntegerArithmetic::BigIntegerArithmetic()
{
	this->operand1 = new Stack;
	this->operand2 = new Stack;
	this->answer = new Stack;
	this->op = '+';
	this->op1 = "";
	this-> op2 = "";
	this-> ans = "";
}

BigIntegerArithmetic::BigIntegerArithmetic(const ArithmeticExpression* input)
{
	//take in AE, store operator and separate operands into two stacks (operand1 and operand2).
	this->operand1 = new Stack;
	this->operand2 = new Stack;
	this->answer = new Stack;
	this->op = input->GetOp();
	this->op1 = input->GetOp1()->GetValue();
	this->op2 = input->GetOp2()->GetValue();
	this->ans = "";

	//create stack from operand1
	int length = input->GetOp1()->GetValue().length();
	int a = 0;
	for(int i = 0; i < length; ++i)
	{
		a = (input->GetOp1()->GetValue().at(i) - '0'); //convert from char to int
		operand1->Push(a); //add each digit to the stack
	}

	//create stack from operand2
	length = input->GetOp2()->GetValue().length();
	for(int i = 0; i < length; ++i)
	{
		a = (input->GetOp2()->GetValue().at(i) - '0');
		operand2->Push(a);
	}
}

bool BigIntegerArithmetic::Op1IsBigger(std::string op1, std::string op2)
{
	//compare op1 and op2 leading digits because they will always be the same size due to padding.
	if(op1.at(0) > op2.at(0) || op1 == op2)
	{
		return true;
	}
	return false;
}

std::string BigIntegerArithmetic::ShowResults()
{
	int temp = 0;
	int carry = 0;

	if(Op1IsBigger(op1, op2)) //if op1 is the larger number
	{
		makeNegative(false);
		if(op == '+') //and the numbers are being added
		{
			while(!operand1->IsEmpty())
			{
				temp = operand1->Pop() + operand2->Pop() + carry; // add two stacks plus carry
				carry = 0;
				if(temp >=10) // set carry if needed
				{
					answer->Push(temp % 10);
					carry = 1;
				}
				else
				{
					answer->Push(temp);
					carry = 0;
				}
			}
			if(carry != 0) //push carry onto answer stack if it is 1
			{
				answer->Push(1);
				carry = 0;
			}
		}
		else //and the numbers are being subtracted
		{
			while(!operand1->IsEmpty())
			{
				temp = (operand1->Pop() - carry) - operand2->Pop();
				carry = 0;
				if(temp < 0)
				{
					temp = temp + 10;
					answer->Push(temp);
					carry = 1;
				}
				else
				{
					answer->Push(temp);
					carry = 0;
				}
			}
		}
	}
	else //if op2 is the larger number
	{
		if(op == '+') //and the numbers are being added
		{
			makeNegative(false);
			while(!operand2->IsEmpty())
			{
				temp = operand1->Pop() + operand2->Pop() + carry;
				carry = 0;
				if(temp >=10)
				{
					answer->Push(temp % 10);
					carry = 1;
				}
				else
				{
					answer->Push(temp);
					carry = 0;
				}
			}
			if(carry != 0)
			{
				answer->Push(1);
				carry = 0;
			}
		}
		else //and the numbers are being subtracted
		{
			makeNegative(true);
			while(!operand2->IsEmpty())
			{		
				temp = (operand2->Pop() - carry) - operand1->Pop();
				carry = 0;
				if(temp < 0)
				{
					temp = temp + 10;
					answer->Push(temp);
					carry = 1;
				}
				else
				{
					answer->Push(temp);
					carry = 0;
				}
			}
		}
	}


	while(!answer->IsEmpty()) //Pop answer stack into answer string
	{
		ans = ans + std::to_string(answer->Pop());
	}

	ans.erase(0, ans.find_first_not_of('0')); //delete leading zeroes
	op1.erase(0, op1.find_first_not_of('0'));
	op2.erase(0, op2.find_first_not_of('0'));

	if(GetNegative())//add '-' to answer if it needs it
	{
		ans = '-' + ans;
	}

	std::ostringstream oss;

	int width = findLargest(op1, op2, ans); //return width of largest number

	oss << std::setw(width) << op1 << '\n' << std::setw(width) << op + op2 << '\n' << std::setw(width) << ans;
	std::string total = oss.str();


	return total;
}

int BigIntegerArithmetic::findLargest(std::string op1, std::string op2, std::string ans)
{
	int temp = op1.length();

	if(temp < op2.length() + 1)
	{
		temp = op2.length() + 1;
		if(temp < ans.length())
		{
			temp = ans.length();
			return temp;
		}
		else
		{
			return temp;
		}
	}
	else if(temp < ans.length())
	{
		temp = ans.length();
		return temp;
	}
	else
	{
		return temp;
	}
}















#include "operand.hpp"

Operand::Operand()
{
	this->payload = "";
}

Operand::Operand(std::string payload)
{
	this->payload = payload;
}

Operand& Operand::operator=(const Operand& rhs)
{
	this->payload = rhs.payload;
	return* this;
}

bool Operand::IsNegative()
{
	if(this->payload.find('-') != std::string::npos)
	{
		return true;
	}
	return false;
}

int Operand::GetLengthOfString()
{
	return this->payload.length();
}

void Operand::Pad(int pad)
{
	for(int i = 0; i < pad; i++)
	{
		this->payload = "0" + payload;
	}
}

void Operand::FlipSign()
{
	if(IsNegative())
	{
		int i = this->payload.find('-');
		this->payload.erase(i, i+1);
	}
	else
	{
		this->payload = '-' + payload;
	}
}

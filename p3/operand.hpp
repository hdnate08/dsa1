#ifndef OPERAND_HPP
#define OPERAND_HPP
#include <string>
class Operand
{
	public:
		Operand();
		Operand(std::string payload);
		bool IsNegative();
		std::string GetValue() {return this->payload;};
		int GetLengthOfString();
		void Pad(int pad);
		void SetValue(std::string newValue) {this->payload = newValue;};
		void FlipSign();
		Operand& operator=(const Operand& rhs);
	private:
		std::string payload;
};

#endif

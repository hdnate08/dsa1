#include "expression-reader.hpp"

int main()
{
	ExpressionReader er("expressions.txt");
	
	while(er.ReadNextExpression())
	{
		std::cout << er.ShowResult();
		std::cout << std::endl << "----------" << std::endl;
	}
	return 0;
}

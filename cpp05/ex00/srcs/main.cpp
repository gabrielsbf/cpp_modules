#include "Bureaucrat.hpp"

int main(void)
{

	const Bureaucrat defaultConst = Bureaucrat("Claudin", -1561);
	std::cout << defaultConst;
	Bureaucrat errorConst = Bureaucrat("Claudin", 155);
	std::cout << errorConst;
	Bureaucrat copyConst = errorConst;
	std::cout << copyConst;
	std::cout << "Ending sentence" << std::endl;
}
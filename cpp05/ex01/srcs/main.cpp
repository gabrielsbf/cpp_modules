#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat buone = Bureaucrat("Claudin", 20);
	std::cout << buone;
	// const Bureaucrat & errone = Bureaucrat("Claudin", -1);
	std::cout << "Ending sentence" << std::endl;
	Form form("FORM 1", 19, 5);
	buone.signForm(form);

}
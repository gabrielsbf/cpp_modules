#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat buone = Bureaucrat("Claudin", 20);
	std::cout << buone;
	const Bureaucrat & errone = Bureaucrat("Jeffin", -1);
	std::cout <<errone;
	Form form("FORM 1", 50, 25);
	std::cout << form;
	buone.signForm(form);
	errone.signForm(form);

}
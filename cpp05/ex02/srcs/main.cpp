#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
	PresidentialPardonForm formOne = PresidentialPardonForm("Percy Jackson");
	RobotomyRequestForm formTwo = RobotomyRequestForm("Robin");

	std::cout << formOne << std::endl;
	std::cout << formTwo << std::endl;

	Bureaucrat god("Zeus", 1);
	Bureaucrat teenTitans("Ciborg", 13);

	std::cout << god << std::endl;
	std::cout << teenTitans << std::endl;

	try {
		god.signForm(formOne);
		teenTitans.signForm(formTwo);

		formOne.execute(god);
		formTwo.execute(teenTitans);
	}
	catch (AForm::CouldNotSignException &e)
	{
		std::cerr << "Couldn't continue due exception: " << e.what() <<std::endl <<std::endl;
	}
	catch (AForm::CouldNotExecException &e)
	{
		std::cerr << "Couldn't continue due exception: " << e.what() <<std::endl<<std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << "Couldn't continue due exception: " << e.what() <<std::endl<<std::endl;
	}
	catch (...)	{
		std::cerr << "Couldn't continue due unexpected exception " << std::endl<<std::endl;
	}
}
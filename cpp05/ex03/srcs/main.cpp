#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm *formOne;
	Intern test;

	Bureaucrat god("Zeus", 1);
	Bureaucrat teenTitans("Ciborg", 13);

	std::cout << god << std::endl;
	std::cout << teenTitans << std::endl;

	try
	{
		formOne = test.makeForm("robotomy", "Herald of Rivia");
		// std::cout << formOne << std::endl;
		god.signForm(*formOne);
		formOne->execute(god);
		delete formOne;
	}
	catch (AForm::CouldNotSignException &e)
	{
		delete formOne;
		std::cerr << "Couldn't continue due exception: " << e.what() << std::endl
				  << std::endl;
	}
	catch (AForm::CouldNotExecException &e)
	{
		delete formOne;
		std::cerr << "Couldn't continue due exception: " << e.what() << std::endl
				  << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		delete formOne;
		std::cerr << "Couldn't continue due exception: " << e.what() << std::endl
				  << std::endl;
	}
	catch (Intern::CouldNotMakeForm &e)
	{
		std::cerr << "Couldn't continue due exception: " << e.what() << std::endl
				  << std::endl;
	}
	catch (...)
	{
		delete formOne;
		std::cerr << "Couldn't continue due unexpected exception " << std::endl
				  << std::endl;
	}
}
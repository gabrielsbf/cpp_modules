#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Instance of Bureaucrat is being created | Standard Parameters " << std::endl;
	applyValidation();
}

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1)
{
	std::cout << "Instance of Bureaucrat is being created | Without Parameters " << std::endl;
	applyValidation();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Instance of Bureaucrat is being created | Copy Method " << std::endl;
	applyValidation();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Instance of Bureaucrat is being created | Assignment Operator Method " << std::endl;
	if (this != &copy)
	{
		this->_grade = copy._grade;
		applyValidation();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Instance of Bureaucrat | Name : " << this->getName() << " is being Destroyed" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int value)
{
	this->_grade = value;
}

void Bureaucrat::applyValidation(void)
{
	try
	{
		validateException(this->getGrade());
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERRO: [" << e.what() << "] grade now setted as '1'" << std::endl;
		this->setGrade(1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERRO: [GRADE " << e.what() << "] grade now setted as '150'" << std::endl;
		this->setGrade(150);
	}
}

void Bureaucrat::validateException(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "You grade is too high (↥) for the specified class - try again with a number between 1~150";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "You grade is too low (↧) for the specified class - try again with a number between 1~150";
}

#include "AForm.hpp"

AForm::AForm(const std::string name,
		   int grade_sign,
		   int grade_execute) : _name(name),
								_signedForm(false),
								_grade_to_sign(grade_sign),
								_grade_to_execute(grade_execute)
{
	std::cout << "[INFO]: Instance of Abstract Form is Being Created | Standard Parameters" << std::endl << std::endl;
	applyValidation();
}

AForm::AForm(void) : _name("default"),
				   _signedForm(false),
				   _grade_to_sign(0),
				   _grade_to_execute(0)
{
	std::cout << "[INFO]: Instance of Abstract Form is Being Created | Default Method" << std::endl << std::endl;
	applyValidation();
}

AForm::AForm(AForm const &src):
	_name(src.getName()),
	_signedForm(src.getSignedForm()),
	_grade_to_sign(src.getGradeToSign()),
	_grade_to_execute(src.getGradeToExecute())
{
	std::cout << "[INFO]: Instance of Abstract Form is Being Created | Copy Method" << std::endl << std::endl;
	applyValidation();
}

AForm &AForm::operator=(AForm const &copy)
{
	std::cout << "[INFO]: Instance of Abstract Form is Being Created | Assignment Operator Method" << std::endl << std::endl;
	if (this != &copy)
	{

		this->_signedForm = copy.getSignedForm();
		this->_grade_to_execute = copy.getGradeToExecute();
		this->_grade_to_sign = copy.getGradeToSign();
		applyValidation();
	}
	return (*this);
}

AForm::~AForm() {
	std::cout << "[INFO]: Instance of Abstract Form | Name : " << this->getName() << " is being Destroyed" << std::endl << std::endl;
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSignedForm(void) const
{
	return (this->_signedForm);
}

int AForm::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

void AForm::setSignedForm(bool value)
{
	this->_signedForm = value;
}

void AForm::setGradeToSign(int value)
{
	this->_grade_to_sign = value;
}

void AForm::setGradeToExecute(int value)
{
	this->_grade_to_execute = value;
}

bool AForm::beSigned(const Bureaucrat & beau)
{
	bool result;

	result = beau.getGrade() <= this->getGradeToSign() || this->getGradeToSign() == true;
	if (result == false)
		throw CouldNotSignException();
	this->setSignedForm(result);
	return (result);
}

void	AForm::FormExecution(void) const{}


void	AForm::execute(Bureaucrat const & executor)
{
	if (!getSignedForm())
		throw FormNotSignedException();
	
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << "[INFO]: " << this->getName() << " executed " << this->getName() << std::endl;
	FormExecution();
}

void AForm::applyValidation(void)
{
	try
	{
		validateException(this->getGradeToSign());
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		std::cerr << "[ERRO]: (GRADE TO SIGN " << this->getGradeToSign() << ") [" << e.what() << "] now setted as '1'" << std::endl;
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		this->setGradeToSign(1);
		std::cout << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		std::cerr << "[ERRO]: (GRADE TO SIGN " << this->getGradeToSign() << ") [" << e.what() << "] now setted as '150'" << std::endl;
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		this->setGradeToSign(150);
		std::cout << std::endl;
	}
	try
	{
		validateException(this->getGradeToExecute());
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		std::cerr << "ERRO: (GRADE TO SIGN " << this->getGradeToExecute() << ") [" << e.what() << "] now setted as '1'" << std::endl;
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		this->setGradeToExecute(1);
		std::cout << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		std::cerr << "ERRO: (GRADE TO SIGN " << this->getGradeToExecute() << ") [" << e.what() << "] now setted as '150'" << std::endl;
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		this->setGradeToExecute(150);
		std::cout << std::endl;
	}

}

void AForm::validateException(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "You grade is too high (↥) for the specified class - try again with a number between 1~150";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "You grade is too low (↧) for the specified class - try again with a number between 1~150";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "You tried to execute the form but you didn't assign";
}

const char *AForm::CouldNotSignException::what() const throw()
{
	return "A Bureaucrat whose tried to sign the Form doesn't have the necessary grade.";
}

const char *AForm::CouldNotExecException::what() const throw()
{
	return "A Bureaucrat whose tried to execute the Form doesn't have the necessary grade.";
}
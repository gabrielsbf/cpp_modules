#include "Form.hpp"

Form::Form(const std::string name,
		   int grade_sign,
		   int grade_execute) : _name(name),
								_signedForm(false),
								_grade_to_sign(grade_sign),
								_grade_to_execute(grade_execute)
{
	std::cout << "Instance of Form is Being Created | Standard Parameters" << std::endl;
	applyValidation();
}

Form::Form(void) : _name("default"),
				   _signedForm(false),
				   _grade_to_sign(0),
				   _grade_to_execute(0)
{
	std::cout << "Instance of Form is Being Created | Default Method" << std::endl;
	applyValidation();
}

Form::Form(Form const &src): _name(src.getName()),
	_signedForm(src.getSignedForm()),
	_grade_to_sign(src.getGradeToSign()),
	_grade_to_execute(src.getGradeToExecute())
{
	std::cout << "Instance of Form is Being Created | Copy Method" << std::endl;
	applyValidation();
}

Form &Form::operator=(Form const &copy)
{
	std::cout << "Instance of Form is Being Created | Assignment Operator Method" << std::endl;
	if (this != &copy)
	{

		this->_signedForm = copy.getSignedForm();
		this->_grade_to_execute = copy.getGradeToExecute();
		this->_grade_to_sign = copy.getGradeToSign();
		applyValidation();
	}
	return (*this);
}

Form::~Form() 
{
	std::cout << "Instance of Form | Name : " << this->getName() << " is being Destroyed" << std::endl;
}

const std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSignedForm(void) const
{
	return (this->_signedForm);
}

int Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

void Form::setSignedForm(bool value)
{
	this->_signedForm = value;
}

void Form::setGradeToSign(int value)
{
	this->_grade_to_sign = value;
}

void Form::setGradeToExecute(int value)
{
	this->_grade_to_execute = value;
}

bool Form::beSigned(const Bureaucrat & beau)
{
	bool result;

	result = beau.getGrade() <= this->getGradeToSign();
	this->setSignedForm(result);
	return (result);
}

void Form::applyValidation(void)
{
	try
	{
		validateException(this->getGradeToSign());
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "ERRO: (GRADE TO SIGN " << this->getGradeToSign() << ") [" << e.what() << "] now setted as '1'" << std::endl;
		this->setGradeToSign(1);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "ERRO: (GRADE TO SIGN " << this->getGradeToSign() << ") [" << e.what() << "] now setted as '150'" << std::endl;
		this->setGradeToSign(150);
	}

	try
	{
		validateException(this->getGradeToExecute());
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		std::cerr << "ERRO: (GRADE TO SIGN " << this->getGradeToExecute() << ") [" << e.what() << "] now setted as '1'" << std::endl;
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		this->setGradeToExecute(1);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		std::cerr << "ERRO: (GRADE TO SIGN " << this->getGradeToExecute() << ") [" << e.what() << "] now setted as '150'" << std::endl;
		std::cerr << "----------------------------------------------------------------------------" << std::endl;
		this->setGradeToExecute(150);
	}
}

void Form::validateException(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "You grade is too high (↥) for the specified class - try again with a number between 1~150";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "You grade is too low (↧) for the specified class - try again with a number between 1~150";
}

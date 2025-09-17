#include "Form.hpp"

Form::Form(const std::string name,
		   int grade_sign,
		   int grade_execute) : _name(name),
								_signedForm(false),
								_grade_to_sign(grade_sign),
								_grade_to_execute(grade_execute)
{
	validateException(this->_grade_to_sign);
}

Form::Form(void) : _name("default"),
				   _signedForm(false),
				   _grade_to_sign(0),
				   _grade_to_execute(0)
{
	validateException(this->_grade_to_sign);
}

Form::Form(Form const &src)
{
	if (&src != this)
	{
		*this = src;
		validateException(this->_grade_to_sign);
	}
}

Form &Form::operator=(Form const &copy)
{
	if (this != &copy)
	{

		this->_signedForm = copy.getSignedForm();
		this->_grade_to_execute = copy.getGradeToExecute();
		this->_grade_to_sign = copy.getGradeToSign();
		validateException(this->_grade_to_sign);
	}
	return (*this);
}

Form::~Form() {}

const 	std::string Form::getName(void) const
{
	return(this->_name);
}

bool	Form::getSignedForm(void) const
{
	return(this->_signedForm);
}

int 	Form::getGradeToSign(void) const
{
	return(this->_grade_to_sign);
}

int 	Form::getGradeToExecute(void) const
{
	return(this->_grade_to_execute);
}

void	Form::setSignedForm(bool value)
{
	this->_signedForm = value;
}

void	Form::setGradeToSign(int value)
{
	this->_grade_to_sign = value;
}

void	Form::setGradeToExecute(int value)
{
	this->_grade_to_execute = value;
}

bool	Form::beSigned(Bureaucrat &beau)
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
			validateException(this->getGradeToExecute());
        }
        catch(Form::GradeTooHighException &e)
        {
            std::cerr << "ERRO: Algum dos dois valores: [GRADE TO SIGN" << this->getGradeToSign() << "] | << [GRADE TO EXECUTE" << this->getGradeToExecute() << "muito grande! Agora estabelecida como '1'" << std::endl;
			if (this->getGradeToExecute() < 1)
				this->setGradeToExecute(1);
			if (this->getGradeToSign() < 1)
				this->setGradeToSign(1);
        }
        catch(Form::GradeTooLowException &e)
        {
            std::cerr << "ERRO: Algum dos dois valores: [GRADE TO SIGN" << this->getGradeToSign() << "] | << [GRADE TO EXECUTE" << this->getGradeToExecute() << "muito baixo! Agora estabelecida como '150'" << std::endl;
            if (this->getGradeToExecute() > 150)
				this->setGradeToExecute(150);
			if (this->getGradeToSign() > 150)
				this->setGradeToSign(150);
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

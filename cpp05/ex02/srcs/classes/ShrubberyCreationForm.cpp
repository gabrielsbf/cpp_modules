#include "ShrubberyCreationForm.hpp"

// TODO: Need to understand what is supposed to be the output of this shrubbery tree
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("Shrubbery Creation Form",
	145,
	137),
	target(target)
{
	std::cout << "[INFO]: Instance of Shrubbery Creation Form is Being Created | Standard Parameters" << std::endl << std::endl;
	applyValidation();
}

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("Shrubbery Creation Form",
	145,
	137),
	target("Default")
{
	std::cout << "[INFO]: Instance of Shrubbery Creation Form is Being Created | Default Method" << std::endl << std::endl;
	this->applyValidation();
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy):
	AForm(copy.getName(),
		  copy.getGradeToSign(),
		  copy.getGradeToExecute()),
	target(copy.getTarget())
{
	std::cout << "[INFO]: Instance of Shrubbery Creation Form is Being Created | Copy Method" << std::endl << std::endl;
	this->applyValidation();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & copy)
{
	std::cout << "[INFO]: Instance of Shrubbery Creation Form is Being Created | Assignment Operator Method" << std::endl << std::endl;
	if (&copy != this)
	{
		this->setTarget(copy.getTarget());
		this->setGradeToExecute(copy.getGradeToExecute());
		this->setGradeToSign(copy.getGradeToSign());
		this->setSignedForm(copy.getSignedForm());
		this->applyValidation();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[INFO]: Shrubbery Creation Form | Target : " << this->getTarget() << " is being Destroyed" << std::endl << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	this->target = target;
}

void 	ShrubberyCreationForm::FormExecution(void) const
{
	std::cout << "[INFO]: Shrubbery Creation Form Exec Called" << std::endl << std::endl;
}
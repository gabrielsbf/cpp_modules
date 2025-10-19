#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Presidential Pardon Form", 25, 5),
	target(target)
{
	std::cout << "[INFO]: Instance of Presidential Pardon Form is Being Created | Standard Parameters" << std::endl << std::endl;
	applyValidation();
}

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon Form", 25, 5),
	target("Default")
{
	std::cout << "[INFO]: Instance of Presidential Pardon Form is Being Created | Default Method" << std::endl << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	AForm(copy.getName(),
		  copy.getGradeToSign(),
		  copy.getGradeToExecute()),
	target(copy.getTarget())
{
	std::cout << "[INFO]: Instance of Presidential Pardon Form is Being Created | Copy Method" << std::endl << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & src)
{
	std::cout << "[INFO]: Instance of Presidential Pardon Form is Being Created | Assignment Operator Method" << std::endl << std::endl;
	if (this != &src)
	{
		this->setTarget(src.getTarget());
		this->setGradeToExecute(src.getGradeToExecute());
		this->setGradeToSign(src.getGradeToSign());
		this->setSignedForm(src.getSignedForm());
		this->applyValidation();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[INFO]: Presidential Pardon Form | Target : " << this->getTarget() << " is being Destroyed" << std::endl << std::endl;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	this->target = target;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void 	PresidentialPardonForm::FormExecution(void) const
{
	std::cout << "[INFO]: "<<this->getTarget() << " was forgiven by Zaphod Beeblebrox" << std::endl << std::endl;
}
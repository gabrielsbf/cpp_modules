#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("Robotomy Request Form", 72, 45),
	target(target)
{
	std::cout << "[INFO]: Instance of Robotomy Request Form is Being Created | Standard Parameters" << std::endl << std::endl;
	applyValidation();
}

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request Form", 72, 45),
	target("Default")
{
	std::cout << "[INFO]: Instance of Robotomy Request Form is Being Created | Default Method" << std::endl << std::endl;
	applyValidation();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm(copy.getName(),
		  copy.getGradeToSign(),
		  copy.getGradeToExecute()),
	target(copy.getTarget())
{
	std::cout << "[INFO]: Instance of Robotomy Request Form is Being Created | Copy Method" << std::endl << std::endl;
	applyValidation();
	
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & src)
{
	std::cout << "[INFO]: Instance of Robotomy Request Form is Being Created | Assignment Operator Method" << std::endl << std::endl;
	if (this != &src)
	{
		this->setTarget(src.getTarget());
		this->setGradeToExecute(src.getGradeToExecute());
		this->setGradeToSign(src.getGradeToSign());
		this->setSignedForm(src.getSignedForm());
		applyValidation();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[INFO]: Robotomy Request Form | Target : " << this->getTarget() << " is being Destroyed" << std::endl << std::endl;
}

void RobotomyRequestForm::setTarget(std::string target)
{
	this->target = target;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void 	RobotomyRequestForm::FormExecution(void) const
{
	std::srand(static_cast<unsigned int>(time(NULL)));
	int randomNumb = std::rand() % 2;
	std::string robotomize_res = randomNumb == 0 ? " could'not be robotomized" : " was robotomized with success";
	std::cout <<"[INFO]: " <<this->target << robotomize_res << std::endl << std::endl;
}

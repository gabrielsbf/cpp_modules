#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream& operator<<( std::ostream& os, const Bureaucrat & beau)
{
	os << beau.getName() << ", bureaucrat grade " << beau.getGrade() << "." << std::endl << std::endl;
	return (os);
}

std::ostream& operator<<( std::ostream& os, const AForm & form)
{
	std::string bool_form_sign = "False";
	if (form.getSignedForm())
		bool_form_sign = "True";
	os << "-----------------------------AForm Data-----------------------------" << std::endl;
	os << form.getName() << ", AForm Signed: " << bool_form_sign << "." << std::endl;
	os << "Grade to Execute >> " << form.getGradeToExecute() << ", Grade to Sign >> " << form.getGradeToSign() << "." << std::endl;
	os << "-------------------------------------------------------------------" << std::endl << std::endl;
	return (os);
}

std::ostream& operator<<( std::ostream& os, const ShrubberyCreationForm & form)
{
	std::string bool_form_sign = "False";
	if (form.getSignedForm())
		bool_form_sign = "True";
	os << "--------------------Shrubbery Creation Form Data--------------------" << std::endl;
	os << form.getName() << ", Shrubbery Creation Form Signed: " << bool_form_sign << "." << std::endl;
	os << "Grade to Execute >> " << form.getGradeToExecute() << ", Grade to Sign >> " << form.getGradeToSign() << "." << std::endl;
	os << "--------------------------------------------------------------------" << std::endl << std::endl;
	return (os);
}

std::ostream& operator<<( std::ostream& os, const PresidentialPardonForm & form)
{	
	std::string bool_form_sign = "False";
	if (form.getSignedForm())
		bool_form_sign = "True";
	os << "--------------------Presidential Pardon Form Data--------------------" << std::endl;
	os << form.getName() << ", Presidential Pardon Form Signed: " << bool_form_sign << "." << std::endl;
	os << "Grade to Execute >> " << form.getGradeToExecute() << ", Grade to Sign >> " << form.getGradeToSign() << "." << std::endl;
	os << "---------------------------------------------------------------------" << std::endl << std::endl;
	return (os);
}

std::ostream& operator<<( std::ostream& os, const RobotomyRequestForm & form)
{
	std::string bool_form_sign = "False";
	if (form.getSignedForm())
		bool_form_sign = "True";
	os << "---------------------Robotomy Request Form Data---------------------" << std::endl;
	os << form.getName() << ", Robotomy Request Form Signed: " << bool_form_sign << "." << std::endl;
	os << "Grade to Execute >> " << form.getGradeToExecute() << ", Grade to Sign >> " << form.getGradeToSign() << "." << std::endl;
	os << "---------------------------------------------------------------------" << std::endl << std::endl;
	return (os);
}
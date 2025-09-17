#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<( std::ostream& os, const Bureaucrat & beau)
{
	os << beau.getName() << ", bureaucrat grade " << beau.getGrade() << "." << std::endl;
	return (os);
}

std::ostream& operator<<( std::ostream& os, const Form & form)
{
	os << "-----------------------------Form Data-----------------------------" << std::endl;
	os << form.getName() << ", Form signed :" << form.getSignedForm() << "." << std::endl;
	os << "Grade to Execute >> " << form.getGradeToExecute() << ", Grade to Sign :" << form.getGradeToSign() << "." << std::endl;
	os << "-------------------------------------------------------------------" << std::endl;
	return (os);
}
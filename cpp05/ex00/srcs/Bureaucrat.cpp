#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(void): _name("default"), _grade(0){}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    if (&src != this)
        *this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & copy)
{
    if (this != &copy)
    {
        this->_grade = copy.getGrade();
    }
    return (*this);
}

const std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "You grade is too high (↥) for the specified class - try again with a number between 1~150";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "You grade is too low (↧) for the specified class - try again with a number between 1~150";
}

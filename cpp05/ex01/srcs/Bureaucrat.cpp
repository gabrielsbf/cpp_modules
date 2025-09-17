#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    applyValidation();
}

Bureaucrat::Bureaucrat(void): _name("default"), _grade(0)
{    
    applyValidation();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    if (&src != this)
    {
        *this = src;
    }

}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & copy)
{
    if (this != &copy)
    {
        this->_grade = copy._grade;
        applyValidation();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void	Bureaucrat::setGrade(int value)
{
    this->_grade = value;
}

void Bureaucrat::signForm(Form& formToSign)
{
    bool isSigned = formToSign.beSigned(*this);
    if (isSigned)
        std::cout << this->getName() << " signed " << formToSign.getName() << std:: endl;
    else
        std::cout << this->getName() << " couldn't sign " << formToSign.getName() << " because grade is lower than the grade to sign" << std:: endl;
    
}

void Bureaucrat::applyValidation(void)
{
        try
        {
            validateException(this->getGrade());
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "ERRO: [GRADE " << this->getGrade() << "] muito grande! Agora estabelecida como '1'" << std::endl;
            this->setGrade(1);
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "ERRO: [GRADE " << this->getGrade() << "] muito baixa! Agora estabelecida como '150'" << std::endl;
            this->setGrade(150);
        }
}

void Bureaucrat::validateException(int grade){
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

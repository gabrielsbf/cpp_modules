#ifndef INTERN_HPP
 #define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
    private:
        AForm *form;
    public:
        // Constructors and Destructor;
        Intern(void);
        Intern(Intern & src);
        Intern & operator=(Intern &copy);
        ~Intern(void);

        AForm & getForm(void);

        AForm * makeForm(std::string form_name, std::string target);

};

#endif
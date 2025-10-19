#ifndef INTERN_HPP
 #define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <map>

class AForm;

class Intern
{
    private:
        AForm *form;
        static AForm * ReturnPresidential(std::string target);
        static AForm * ReturnShrubbery(std::string target);
        static AForm * ReturnRobotomy(std::string target);
        struct FormPair {
            const char* name;
            AForm* (*creator)(std::string);
        };

    public:
        // Constructors and Destructor;
        Intern(void);
        Intern(Intern & src);
        Intern & operator=(Intern &copy);
        ~Intern(void);

        AForm & getForm(void);
        AForm * makeForm(std::string form_name, std::string target);
        
        class CouldNotMakeForm: std::exception {
			public:
				const char *what() const throw();

		};
};

#endif
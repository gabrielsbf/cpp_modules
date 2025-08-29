#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>


class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    
    public:
        //Cannonical Form
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat & operator=(Bureaucrat const & copy);
        ~Bureaucrat();

        //Functions
        const std::string getName(void) const;
        int getGrade(void) const;
        
        // Exceptions
        class GradeTooHighException: std::exception {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException: std::exception {
            public:
                const char *what() const throw();

        };
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat & beau);


#endif
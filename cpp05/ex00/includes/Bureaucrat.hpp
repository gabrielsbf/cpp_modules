#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat & operator=(Bureaucrat const & copy);
        ~Bureaucrat();

};

#endif
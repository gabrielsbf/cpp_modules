#ifndef ROBOTOMY_REQUEST_FORM
 #define ROBOTOMY_REQUEST_FORM

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string target;
    
    public:
        //Cannonical RobotomyRequestForm
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & src);
        virtual ~RobotomyRequestForm();

        //Getters & Setters
        void setTarget(std::string target);
        std::string getTarget(void) const;
        
        //Overrinding FormExecution.
        virtual void FormExecution(void) const;
};

std::ostream& operator<<( std::ostream& os, const RobotomyRequestForm & form);

#endif
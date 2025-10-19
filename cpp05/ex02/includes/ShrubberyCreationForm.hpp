#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{	
	private:
		std::string target;

	public:
		//Cannonical ShrubberyCreationForm
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & copy);
		virtual ~ShrubberyCreationForm();

		//Getters & Setters
		std::string	getTarget(void) const;
		void		setTarget(std::string target);
		
		//Overrinding FormExecution.
		virtual void FormExecution(void) const;

};

std::ostream& operator<<( std::ostream& os, const ShrubberyCreationForm & form);


#endif
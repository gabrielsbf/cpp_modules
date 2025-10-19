#ifndef PRESIDENTIALPARDONFFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{	
	private:
		std::string target;

	public:
		//Cannonical PresidentialPardonForm
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & copy);
		virtual ~PresidentialPardonForm();

		//Getters & Setters
		std::string	getTarget(void) const;
		void		setTarget(std::string target);
		
		//Overrinding FormExecution.
		virtual void FormExecution(void) const;

};

std::ostream& operator<<( std::ostream& os, const PresidentialPardonForm & form);


#endif
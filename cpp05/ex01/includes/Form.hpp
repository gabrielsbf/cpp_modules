#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signedForm;
		int					_grade_to_sign;
		int					_grade_to_execute;

	
	public:
		//Cannonical Form
		Form(const std::string name, int grade_sign, int grade_execute);
		Form(void);
		Form(Form const & src);
		Form & operator=(Form const & copy);
		~Form();

		//Functions
		//Getters
		const 	std::string getName(void) const;
		bool	getSignedForm(void) const;
		int 	getGradeToSign(void) const;
		int 	getGradeToExecute(void) const;

		//Setters
		void	setSignedForm(bool value);
		void	setGradeToSign(int value);
		void	setGradeToExecute(int value);

		//Others
		bool	beSigned(Bureaucrat &beau);
		
		// Exceptions
		void validateException(int grade);
		void applyValidation(void);

		class GradeTooHighException: std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: std::exception {
			public:
				const char *what() const throw();

		};
};

std::ostream& operator<<( std::ostream& os, const Form & form);


#endif
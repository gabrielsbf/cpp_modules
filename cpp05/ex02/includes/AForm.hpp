#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signedForm;
		int					_grade_to_sign;
		int					_grade_to_execute;

	
	public:
		//Cannonical AForm
		AForm(const std::string name, int grade_sign, int grade_execute);
		AForm(void);
		AForm(AForm const & src);
		AForm & operator=(AForm const & copy);
		virtual ~AForm();

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
		bool	beSigned(const Bureaucrat & beau);
		void	execute(Bureaucrat const & executor);
		virtual void	FormExecution(void) const;
		// Exceptions
		void validateException(int grade);
		void applyValidation(void);

		class FormNotSignedException: std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooHighException: std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: std::exception {
			public:
				const char *what() const throw();

		};
		
		class CouldNotSignException: std::exception {
			public:
				const char *what() const throw();

		};
		
		class CouldNotExecException: std::exception {
			public:
				const char *what() const throw();

		};
		
};

std::ostream& operator<<( std::ostream& os, const AForm & form);


#endif
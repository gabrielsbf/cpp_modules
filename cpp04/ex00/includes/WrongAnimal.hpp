#ifndef WRONG_ANIMAL_CLASS_H
# define WRONG_ANIMAL_CLASS_H

# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string const type);
		~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);

		std::string const &	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
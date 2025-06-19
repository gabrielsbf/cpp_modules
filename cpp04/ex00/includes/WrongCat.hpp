#ifndef WRONG_CAT_CLASS_H
# define WRONG_CAT_CLASS_H

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		WrongCat &	operator=(WrongCat const & src);

		void	makeSound(void) const;
};

#endif
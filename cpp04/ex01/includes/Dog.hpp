#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:

		Dog(void);
		Dog(Dog const & src);
		Dog &	operator=(Dog const & src);
		virtual ~Dog(void);

		Brain *getBrain();

		virtual void makeSound(void);
	private:
		Brain *_brain;
};
#endif
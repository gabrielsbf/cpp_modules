#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    public:

        Cat(void);
		Cat(Cat const & src);
		Cat &	operator=(Cat const & src);
		~Cat(void);
		virtual void makeSound(void);
	private:
		Brain *_brain;


};


#endif


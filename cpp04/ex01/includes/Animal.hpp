#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:

        Animal(void);
		Animal(std::string an_type);
		Animal(Animal const & src);
		virtual ~Animal(void);
		Animal &	operator=(Animal const & src);
        virtual void makeSound(void);
        std::string getType(void);
};

#endif
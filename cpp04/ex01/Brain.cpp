#include "includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
	return ;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
	return ;
}

Brain &	Brain::operator=(Brain const & src)
{
	std::cout << "Brain Operator Constructor called." << std::endl;
	for (int i = 0; i < this->nb_ideas; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
}

std::string const & Brain::getIdea(int index) const
{
	if (index < 0)
		index = 0;
	return (this->_ideas[index % (nb_ideas - 1)]);
}

void	Brain::setIdea(int index, std::string const & idea)
{
	if (index < 0)
		return ;
	this->_ideas[index % (nb_ideas - 1)] = idea;
	return ;
}
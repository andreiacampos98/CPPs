#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain default created." << std::endl;
}

Brain::Brain(std::string type)
{
	(void)type;
	std::cout << "Copy Cat constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	(void)copy;
	std::cout << "Copy Brain constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	(void)src;
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed." << std::endl;
}

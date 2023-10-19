#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain default created." << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Copy Brain constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	std::copy(src._ideas, src._ideas + 100, this->_ideas);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed." << std::endl;
}

void Brain::set_idea(std::string const &ideas, int const index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = ideas;
}

std::string 	Brain::get_idea(int const index) const
{
	if (index >= 0 && index< 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}

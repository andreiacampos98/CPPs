#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &copy)
{
	std::cout << "IMateriaSource copy constructor" << std::endl;
	*this=copy;
}

IMateriaSource const &IMateriaSource::operator=(IMateriaSource const &copy)
{
	std::cout << "IMateriaSource copy assignment constructor" << std::endl;
	(void) copy;
	return (*this);
}

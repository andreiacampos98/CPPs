#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain
{
	public:
		Brain();
		Brain(std::string type);
		Brain(const Brain &copy);
		Brain &operator=(const Brain &src);
		~Brain();

		
};

#endif

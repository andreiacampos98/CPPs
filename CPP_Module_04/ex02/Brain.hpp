#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &src);
		~Brain();

		void			set_idea(std::string const &ideas, int const index);
		std::string 	get_idea(int const index) const;
};

#endif

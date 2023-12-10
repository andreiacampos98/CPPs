#include "RPN.hpp"

void	calculate(std::stack<int> &stack, char character)
{
	int	first;
	int second;

	if(!stack.empty())
	{
		second = stack.top();
		stack.pop();
	}
	if(!stack.empty())
	{
		first = stack.top();
		stack.pop();
		if(character == '+')
			stack.push(first + second);
		if(character == '-')
			stack.push(first - second);
		if(character == '*')
			stack.push(first * second);
		if(character == '/')
		{
			if(second == 0)
				throw std::invalid_argument(" It isn't possible divide by 0.\n");
			stack.push(first / second);
		}
		std::cout << first << " " << character << " " << second << " = " << stack.top() << std::endl;
	}
}

void parser(std::string arg)
{
    std::stringstream	stream(arg);
    char				character;
	std::stack<int>			stack;

    while(stream >> character)
    {
        if(!isdigit(character) && character != '+' && character != '-' && character != '*' && character != '/')
        {
			std::cout << "Not a digit" << std::endl;
			return ;
		}
		if(character != '+' && character != '-' && character != '*' && character != '/')
		{
			stack.push(character - '0');
			continue;
		}
        else
		{
			calculate(stack, character);
		}
    }
}


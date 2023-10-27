/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/27 20:07:52 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


bool	is_int(char const *str)
{
	long nb = strtol(str, NULL, 10);
	
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				continue;
			return false;
		}
	}
	if (nb > 2147483647 || nb < -2147483648)
	{
		std::cout << "It is higher than int." << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong inputs! ./scalar_convert <char>/<int>/<double>/<float>" << std::endl;
	}
	else
	{
		const char* str;
		str = argv[1];
		//ScalarConverter	scalarConverter(str);
		std::cout << "Is int? " << is_int(str) << std::endl;
		ScalarConverter *A;
		A = new ScalarConverter();
		A->converter(str);
		delete A;
	}
}

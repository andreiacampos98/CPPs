/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 11:05:22 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
		ScalarConverter::converter(str);
	}
}

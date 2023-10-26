/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:53 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/26 21:37:07 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(): i_int(0), c_char(0), f_float(0), d_double(0)
{
	std::cout << "Scalar Converter constructor created." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	this->i_int = src.i_int;
	this->c_char = src.c_char;
	this->f_float = src.f_float;
	this->d_double = src.d_double;
}

ScalarConverter  &ScalarConverter::operator=(const ScalarConverter &src)
{
	this->i_int = src.i_int;
	this->c_char = src.c_char;
	this->f_float = src.f_float;
	this->d_double = src.d_double;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar Converter destroyed." << std::endl;
}

void	ScalarConverter::converter(const char* str)
{
	if (is_int(str))
		return;
}

bool	ScalarConverter::is_int(const char* str)
{
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if(!isdigit(str[i]))
			return 0;
	}
	return 1;
}

bool	ScalarConverter::is_char(const char* str)
{
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if(!isdigit(str[i]))
			return 0;
	}
	return 1;
}

bool	ScalarConverter::is_double(const char* str)
{
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if(!isdigit(str[i]))
			return 0;
	}
	return 1;
}

bool	ScalarConverter::is_float(const char* str)
{
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if(!isdigit(str[i]))
			return 0;
	}
	return 1;
}

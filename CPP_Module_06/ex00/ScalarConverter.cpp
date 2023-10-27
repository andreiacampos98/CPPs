/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:53 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/28 00:01:59 by anaraujo         ###   ########.fr       */
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
	//this->_type = src._type;
}

ScalarConverter  &ScalarConverter::operator=(const ScalarConverter &src)
{
	this->i_int = src.i_int;
	this->c_char = src.c_char;
	this->f_float = src.f_float;
	this->d_double = src.d_double;
	//this->_type = src._type;
	std::cout << "Scalar Converter assignment operator overload called." << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar Converter destroyed." << std::endl;
}

void	ScalarConverter::converter(const char* str)
{
	if (is_int(str))
		convertFromInt();
	if(is_char(str))
		convertFromChar();
	if(is_double(str))
		convertFromDouble();
	if(is_float(str))
		convertFromFloat();
}

void ScalarConverter::convertFromInt()
{
	this->f_float =static_cast<float>(this->i_int);
	this->d_double =static_cast<double>(this->i_int);
	this->c_char =static_cast<char>(this->i_int);
	std::cout << "int: " << this->i_int << std::endl;
	std::cout << "float: " << this->f_float << std::endl;
	std::cout << "double: " << this->d_double << std::endl;
	std::cout << "char: " << this->c_char << std::endl;
}

void ScalarConverter::convertFromChar()
{
	this->f_float =static_cast<float>(this->c_char);
	this->d_double =static_cast<double>(this->c_char);
	this->i_int =static_cast<int>(this->c_char);
}

void ScalarConverter::convertFromDouble()
{
	this->f_float =static_cast<float>(this->d_double);
	this->i_int =static_cast<int>(this->d_double);
	this->c_char =static_cast<char>(this->d_double);
	std::cout << "int: " << this->i_int << std::endl;
	std::cout << "float: " << this->f_float << std::endl;
	std::cout << "double: " << this->d_double << std::endl;
	std::cout << "char: " << this->c_char << std::endl;
}

void ScalarConverter::convertFromFloat()
{
	this->i_int =static_cast<int>(this->f_float);
	this->d_double =static_cast<double>(this->f_float);
	this->c_char =static_cast<char>(this->f_float);
}

bool	ScalarConverter::is_int(char const *str)
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
	if (nb > INT_MAX || nb < INT_MIN)
	{
		std::cout << "It is higher than int." << std::endl;
		return false;
	}
	this->i_int = static_cast<int>(nb);
	return true;
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
	long nb = strtol(str, NULL, 10);
	bool decimal;

	decimal = 0;	
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if (str[i] == '.')
		{
			if (decimal == 0)
				decimal = 1;
			else
				return 0;
		}
		else if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				continue;
			return false;
		}
	}
	if (nb > DBL_MAX || nb < DBL_MIN)
	{
		std::cout << "It is higher than int." << std::endl;
		return false;
	}
	this->d_double = nb;
	return true;
}

bool	ScalarConverter::is_float(const char* str)
{
	//float f = strtof(str, end);
	for (int i = 0; i < (int)strlen(str); i++) 
	{
		if(!isdigit(str[i]))
			return 0;
	}
	return 1;
}

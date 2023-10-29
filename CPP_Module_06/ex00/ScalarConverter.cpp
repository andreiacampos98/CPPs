/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:53 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 11:26:47 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Scalar Converter constructor created." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	this->i_int = src.i_int;
	this->c_char = src.c_char;
	this->f_float = src.f_float;
	this->d_double = src.d_double;
	this->_arg = src._arg;
	std::cout << "Scalar Converter copy constructor called." << std::endl;
}

ScalarConverter  &ScalarConverter::operator=(const ScalarConverter &src)
{
	this->i_int = src.i_int;
	this->c_char = src.c_char;
	this->f_float = src.f_float;
	this->d_double = src.d_double;
	this->_arg = src._arg;
	std::cout << "Scalar Converter assignment operator overload called." << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Scalar Converter destroyed." << std::endl;
}

void	ScalarConverter::converter(std::string str)
{
	if (is_nan(str))
		convertFromNan(str);
	else if (is_inf(str))
		convertFromInf(str);
	else if (is_int(str))
		convertFromInt(str);
	else if(is_double(str))
		convertFromDouble(str);
	else if(is_float(str))
		convertFromFloat(str);
	else if(is_char(str))
		convertFromChar(str);
}

void ScalarConverter::convertFromInt(std::string str)
{
	long nb = strtol(str.c_str(), NULL, 10);
	float f =static_cast<float>(nb);
	double d =static_cast<double>(nb);
	char c =static_cast<char>(nb);
	if (c <= CHAR_MAX && c >= CHAR_MIN)
	{
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << nb << std::endl;
	if (nb < 1000000)
	{
		std::cout << "float: " << f << ".0f"<< std::endl;
		std::cout << "double: " << d << ".0"<< std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f"<< std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::convertFromChar(std::string str)
{
	char c = str[0];
	float f =static_cast<float>(c);
	double d =static_cast<double>(c);
	int i =static_cast<int>(c);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f <<  ".0f" << std::endl;
	std::cout << "double: " << d << ".0" <<std::endl;
}

void ScalarConverter::convertFromDouble(std::string str)
{
	double d = strtod(str.c_str(), NULL);
	float f =static_cast<float>(d);
	int i =static_cast<int>(d);
	char c =static_cast<char>(d);
	if (d <= CHAR_MAX && d >= CHAR_MIN)
	{
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	if ( d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	double tmp;
	std::cout << "float: " << f;
	if (modf(d, &tmp) == 0 && d < 999999.5)
		std::cout << ".0f" << std::endl;
	else 
		std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (modf(d, &tmp) == 0 && d < 999999.5)
		std::cout << ".0" << std::endl;
	else
		std::cout << "\n";
}

void ScalarConverter::convertFromFloat(std::string str)
{
	float f = strtof(str.c_str(), NULL);
	int i =static_cast<int>(f);
	double d =static_cast<double>(f);
	char c =static_cast<char>(f);
	if (f <= CHAR_MAX && f >= CHAR_MIN)
	{
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	if (f > (double)INT_MAX || f < (double)INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	double tmp;
	std::cout << "float: " << f;
	if (modf(f, &tmp) == 0 && f < 999999.5)
		std::cout << ".0f" << std::endl;
	else 
		std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (modf(f, &tmp) == 0 && f < 999999.5)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::convertFromInf(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (!str.compare(1, 4, "inf")) 
	{
		double d = std::numeric_limits<double>::infinity();
		if (str.at(0) == '-') d = -d;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (!str.compare(1, 5, "inff")) {
		float f = std::numeric_limits<float>::infinity();
		if (str.at(0) == '-') f = -f;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::convertFromNan(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan")
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (str == "nanf") 
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

bool	ScalarConverter::is_int(std::string str)
{
	long nb = strtol(str.c_str(), NULL, 10);
	
	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
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
		std::cout << "It is higher or lower than int max or min." << std::endl;
		return false;
	}
	std::cout << "Is int" << std::endl;
	return true;
}

bool	ScalarConverter::is_char(std::string str)
{
	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
	{
		if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				return false;
		}
	}
	std::cout << "Is char" << std::endl;
	return true;
}

bool	ScalarConverter::is_double(std::string str)
{
	long nb = strtol(str.c_str(), NULL, 10);
	bool decimal;

	decimal = 0;
	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
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
		std::cout << "It is higher or lower than double max or min." << std::endl;
		return false;
	}
	std::cout << "Is double" << std::endl;
	return true;
}

bool	ScalarConverter::is_float(std::string str)
{
	float f = strtof(str.c_str(), NULL);
	bool decimal;

	decimal = 0;
	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
	{
		if (str[i] == '.')
		{
			if (decimal == 0)
				decimal = 1;
			else
				return 0;
		}
		else if (str[i] == 'f')
		{
			if(i == (int)strlen(str.c_str()) - 1)
				break;
			else
				return false;
		}
		else if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				continue;
			return false;
		}
	}
	if (f > FLT_MAX || f < FLT_MIN)
	{
		std::cout << "It is higher or lower than float max or min." << std::endl;
		return false;
	}
	std::cout << "Is float" << f<< std::endl;
	return true;
}

bool	ScalarConverter::is_nan(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		return true;
	}
	return false;
}

bool	ScalarConverter::is_inf(std::string str)
{
	if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		return true;
	}
	return false;
}

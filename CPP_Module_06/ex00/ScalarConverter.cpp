/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:53 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/28 22:58:51 by anaraujo         ###   ########.fr       */
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
	this->_arg = src._arg;
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
		convertFromNan();
	else if (is_inf(str))
		convertFromInf();
	else if (is_int(str))
		convertFromInt();
	else if(is_double(str))
		convertFromDouble();
	else if(is_float(str))
		convertFromFloat();
	else if(is_char(str))
		convertFromChar();
}

void ScalarConverter::convertFromInt()
{
	this->f_float =static_cast<float>(this->i_int);
	this->d_double =static_cast<double>(this->i_int);
	this->c_char =static_cast<char>(this->i_int);
	if (this->c_char <= CHAR_MAX && this->c_char >= CHAR_MIN)
	{
		if (std::isprint(this->c_char))
			std::cout << "char: " << this->c_char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << this->i_int << std::endl;
	if (this->i_int < 1000000)
	{
		std::cout << "float: " << this->f_float << ".0f"<< std::endl;
		std::cout << "double: " << this->d_double << ".0"<< std::endl;
	}
	else
	{
		std::cout << "float: " << this->f_float << "f"<< std::endl;
		std::cout << "double: " << this->d_double << std::endl;
	}
}

void ScalarConverter::convertFromChar()
{
	this->f_float =static_cast<float>(this->c_char);
	this->d_double =static_cast<double>(this->c_char);
	this->i_int =static_cast<int>(this->c_char);
	if (std::isprint(this->c_char))
		std::cout << "char: " << this->c_char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << this->i_int << std::endl;
	std::cout << "float: " << this->f_float <<  ".0f" << std::endl;
	std::cout << "double: " << this->d_double << ".0" <<std::endl;
}

void ScalarConverter::convertFromDouble()
{
	double d = strtod(this->_arg.c_str(), NULL);
	this->f_float =static_cast<float>(this->d_double);
	this->i_int =static_cast<int>(this->d_double);
	this->c_char =static_cast<char>(this->d_double);
	if (d <= CHAR_MAX && d >= CHAR_MIN)
	{
		if (std::isprint(this->c_char))
			std::cout << "char: " << this->c_char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	if ( d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->i_int << std::endl;
	double tmp;
	std::cout << "float: " << this->f_float;
	if (modf(d, &tmp) == 0 && d < 999999.5)
		std::cout << ".0f" << std::endl;
	else 
		std::cout << "f" << std::endl;
	std::cout << "double: " << this->d_double;
	if (modf(d, &tmp) == 0 && d < 999999.5)
		std::cout << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat()
{
	float f = strtof(this->_arg.c_str(), NULL);
	this->i_int =static_cast<int>(this->f_float);
	this->d_double =static_cast<double>(this->f_float);
	this->c_char =static_cast<char>(this->f_float);
	if (f <= CHAR_MAX && f >= CHAR_MIN)
	{
		if (std::isprint(this->c_char))
			std::cout << "char: " << this->c_char << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	if (f > (double)INT_MAX || f < (double)INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->i_int << std::endl;
	double tmp;
	std::cout << "float: " << this->f_float;
	if (modf(f, &tmp) == 0 && f < 999999.5)
		std::cout << ".0f" << std::endl;
	else 
		std::cout << "f" << std::endl;
	std::cout << "double: " << this->d_double;
	if (modf(f, &tmp) == 0 && f < 999999.5)
		std::cout << ".0" << std::endl;
}

void ScalarConverter::convertFromInf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (!this->_arg.compare(1, 4, "inf")) 
	{
		double d = std::numeric_limits<double>::infinity();
		if (this->_arg.at(0) == '-') d = -d;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (!this->_arg.compare(1, 5, "inff")) {
		float f = std::numeric_limits<float>::infinity();
		if (this->_arg.at(0) == '-') f = -f;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::convertFromNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (this->_arg == "nan")
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (this->_arg == "nanf") 
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

bool	ScalarConverter::is_int(std::string str)
{
	long nb = strtol(str.c_str(), NULL, 10);
	
	this->_arg = str;
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
	this->i_int = static_cast<int>(nb);
	std::cout << "Is int" << std::endl;
	return true;
}

bool	ScalarConverter::is_char(std::string str)
{
	this->_arg = str;

	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
	{
		if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				return false;
		}
	}
	this->c_char = str[0];
	std::cout << "Is char" << std::endl;
	return true;
}

bool	ScalarConverter::is_double(std::string str)
{
	long nb = strtol(str.c_str(), NULL, 10);
	bool decimal;

	decimal = 0;
	this->_arg = str;
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
	this->d_double = nb;
	std::cout << "Is double" << std::endl;
	return true;
}

bool	ScalarConverter::is_float(std::string str)
{
	float f = strtof(str.c_str(), NULL);
	bool decimal;

	decimal = 0;
	this->_arg = str;
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
	this->f_float = f;
	std::cout << "Is float" << f<< std::endl;
	return true;
}

bool	ScalarConverter::is_nan(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		this->_arg = str;
		return true;
	}
	return false;
}

bool	ScalarConverter::is_inf(std::string str)
{
	if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		this->_arg = str;
		return true;
	}
	return false;
}

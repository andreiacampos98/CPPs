/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:06:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/28 22:59:21 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <limits>
#include <float.h>
#include <climits>
#include <math.h>

class ScalarConverter
{
	private:
		int			i_int;
		char		c_char;
		float		f_float;
		double		d_double;
		std::string	_arg;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter  &operator=(const ScalarConverter &src);
		~ScalarConverter();

		void	converter(std::string str);

		bool	is_int(std::string str);
		bool	is_char(std::string str);
		bool	is_double(std::string str);
		bool	is_float(std::string str);
		bool	is_nan(std::string str);
		bool	is_inf(std::string str);

		void	convertFromInt();
		void	convertFromChar();
		void	convertFromDouble();
		void	convertFromFloat();
		void	convertFromInf();
		void	convertFromNan();
};

#endif

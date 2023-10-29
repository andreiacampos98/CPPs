/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:06:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 11:23:35 by anaraujo         ###   ########.fr       */
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
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter  &operator=(const ScalarConverter &src);
		virtual ~ScalarConverter();

		static void	converter(std::string str);

		static bool	is_int(std::string str);
		static bool	is_char(std::string str);
		static bool	is_double(std::string str);
		static bool	is_float(std::string str);
		static bool	is_nan(std::string str);
		static bool	is_inf(std::string str);

		static void	convertFromInt(std::string str);
		static void	convertFromChar(std::string str);
		static void	convertFromDouble(std::string str);
		static void	convertFromFloat(std::string str);
		static void	convertFromInf(std::string str);
		static void	convertFromNan(std::string str);
};

#endif

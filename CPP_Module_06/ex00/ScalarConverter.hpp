/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:06:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/26 21:37:18 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
class ScalarConverter
{
	private:
		int		i_int;
		char	c_char;
		float	f_float;
		double	d_double;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter  &operator=(const ScalarConverter &src);
		~ScalarConverter();

		void	converter(const char* str);

		bool	is_int(const char* str);
		bool	is_char(const char* str);
		bool	is_double(const char* str);
		bool	is_float(const char* str);
};

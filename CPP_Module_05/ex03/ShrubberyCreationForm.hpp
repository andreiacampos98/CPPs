/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 11:39:39 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm: public AForm
{
	private:
		std::string const 	_target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
		
		void executeForm(void) const;
	
	class openFile: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Error opening a file";
			}
	};
};

#endif

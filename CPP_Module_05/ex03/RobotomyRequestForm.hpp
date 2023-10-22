/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 11:41:29 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "AForm.hpp"


class RobotomyRequestForm: public AForm
{
	private:
		std::string const 	_target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
		
		void executeForm(void) const;

	class RobotomizedFailed: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Failure on robotomize!";
			}
	};
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/20 22:32:31 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const 	_name;
		bool 				_signed;
		int const			_grade;
		int const			_reqGrade;
	public:
		Form();
		~Form();
		Form(std::string const name, bool s, int grade, int reqGrade);
		Form(Form const &src);
		Form &operator=(Form const &src);
		
		std::string getFormName(void);
		bool		getFormSigned(void);
		int			getFormGrade(void);
		int			getFormReqGrade(void);

		void		beSigned(const Bureaucrat &Bur);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade too high";
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Grade too low";
				}
		};
};

#endif

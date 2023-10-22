/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 20:18:27 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const 	_name;
		bool 				_signed;
		int const			_grade;
		int const			_reqGrade;
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string &name, int grade, int reqGrade);
		AForm(AForm const &src);
		
		AForm &operator=(AForm const &src);
		
		std::string getFormName(void) const;
		bool		getFormSigned(void) const;
		int			getFormGrade(void) const;
		int			getFormReqGrade(void) const;

		void		beSigned(Bureaucrat const &Bur);
		void 		execute(Bureaucrat const & executor) const;

		virtual void executeForm(void) const = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form error - Grade too high";
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form error - Grade too low";
				}
		};
		class FormNotSigned: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form not signed";
				}
		};
		class GradeExecuteTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Execute Grade too low!";
				}
		};
};

std::ostream& operator<<(std::ostream& os, AForm const& src);

#endif

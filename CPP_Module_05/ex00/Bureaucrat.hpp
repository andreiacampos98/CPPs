/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:44:28 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/20 19:47:31 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string		_name;
		int				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
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

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src);

#endif

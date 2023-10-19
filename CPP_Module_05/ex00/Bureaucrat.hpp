/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:44:28 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/19 19:30:18 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

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

		std::string getName(void);
		std::int getGrade(void);
		void incrementGrade(void);
		void decrementGrade(void);
	class GradeTooHighException: public exception
	{
		virtual const char* what() const no exception
		{
			std::cout << "Grade too high" << std::endl;
		}
	}
	class GradeTooLowException:public exception
	{
		virtual const char* what() const no exception
		{
			std::cout << "Grade too low" << std::endl;
		}
	}
}

#endif
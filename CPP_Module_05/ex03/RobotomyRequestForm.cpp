/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:22:45 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 11:40:40 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "Default RobotomyRequestForm constructor created." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor with target equal to " << _target << " created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src.getFormName(), src.getFormGrade(), src.getFormReqGrade()), _target(src._target)
{
	std::cout << "RobotomyRequestForm Copy constructor." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	std::cout << "RobotomyRequestForm Copy assignment operator constructor." << std::endl;
	if (this != &src)
	{
		//this->_target = src._target;
	}
	return (*this);
}

void RobotomyRequestForm::executeForm(void) const
{
	int	randomNb;

	srand(time(0)); 
  	randomNb = (rand() % 2) + 1;
	try
	{
		if (randomNb == 1)
		{
			std::cout << _target << " has been robotomized successfully" << std::endl;
		}
		else
			throw RobotomyRequestForm::RobotomizedFailed();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

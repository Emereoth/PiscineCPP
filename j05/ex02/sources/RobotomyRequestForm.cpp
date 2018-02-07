/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:26:57 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 09:37:27 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequest.hpp"

RobotomyRequest::RobotomyRequest(std::string name, std::string target) : Form(name, target, 72, 45)
{
}

RobotomyRequest::~RobotomyRequest(void)
{
}

void						RobotomyRequest::execute(Bureaucrat const & executor)
{
	srand(time(NULL));
	int			seed = rand() % 15;
	 
	try
	{
		std::cout << "Bureaucrat " << executor.getName() << " tries to execute a RobotomyRequest form..." << std::endl;
		if (executor.getGrade() > _minExec)
			throw ExecutionFailException();
		std::cout << " * drill noises * " << std::endl;
		if (((rand() + seed++) % 20) / 2 == 0)
			std::cout << "The robotomy has succeeded!" << std::endl;
		else
			std::cout << "Robotomy failed." << std::endl;
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

// PRIVATE

RobotomyRequest::RobotomyRequest(void)
{
}

RobotomyRequest(RobotomyRequest const & src)
{
	(void)src;
}

RobotomyRequest &		RobotomyRequest::operator=(RobotomyRequest const & rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &			operator<<(std::ostream & o, RobotomyRequest const & rhs)
{
	o << rhs.getName() << " is a RobotomyRequest form of grade (sign " << rhs.getSignReq() << "; exec" << rhs.getSignReq() << ") and is currently " << (rhs.getState() ? "SIGNED." : "NOT SIGNED.") << std::endl;
	return (o);
}
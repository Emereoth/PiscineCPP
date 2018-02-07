/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:30:23 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 10:10:32 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardon::PresidentialPardon(std::string name, std::string target) : Form(name, target, 25, 5)
{
}

PresidentialPardon::~PresidentialPardon(void)
{
}

void						PresidentialPardon::execute(Bureaucrat const & executor)
{
	try
	{
		std::cout << "Bureaucrat " << executor.getName() << " tries to execute a PresidentialPardon form..." << std::endl;
		if (executor.getGrade() > 5)
			throw PresidentialPardon::ExecutionFailedException();
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

// PRIVATE

PresidentialPardon::PresidentialPardon(void)
{
}

PresidentialPardon::PresidentialPardon(PresidentialPardon const & src)
{
	(void)src;
}

PresidentialPardon &		PresidentialPardon::operator=(PresidentialPardon const & rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &			operator<<(std::ostream & o, PresidentialPardon const & rhs)
{
	o << rhs.getName() << " is a PresidentialPardon form of grade (sign " << rhs.getSignReq() << "; exec" << rhs.getSignReq() << ") and is currently " << (rhs.getState() ? "SIGNED." : "NOT SIGNED.") << std::endl;
	return (o);
}
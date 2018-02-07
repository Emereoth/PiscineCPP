/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:52:41 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 18:11:24 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Form.hpp"

Form::Form(std::string name, int requirement) : _name(name), _minGrade(requirement)
{
	if (requirement < 1)
		throw Form::GradeTooHighException();
	else if (requirement > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
}

Form &			Form::operator=(Form const & rhs)
{
	(void)rhs;
	return (*this);
}

std::string		Form::getName(void) const
{
	return (_name);
}

bool			Form::getState(void) const
{
	return (_signed);
}

int				Form::getRequirements(void) const
{
	return (_minGrade);
}

void			Form::beSigned(Bureaucrat const & target)
{
	try
	{
		if (_minGrade < 1)
			throw Form::GradeTooHighException();
		else if (_minGrade > 150)
			throw Form::GradeTooLowException();
		_signed = target.signForm(_minGrade, _name, _signed);
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

Form::Form(void)
{
}

Form::Form(Form const & src)
{
	(void)src;
}


std::ostream &			operator<<(std::ostream & o, Form const & rhs)
{
	o << rhs.getName() << " is a form of grade " << rhs.getRequirements() << " and is currently " << (rhs.getState() ? "SIGNED." : "NOT SIGNED.") << std::endl;
	return (o);
}
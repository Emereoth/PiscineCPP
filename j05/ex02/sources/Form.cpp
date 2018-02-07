/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:52:41 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 09:48:12 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Form.hpp"

Form::Form(std::string name, std::string target, int minSign, int minExec) : _name(name), _target(target), _minSign(minSign), _minExec(minExec)
{
	if (minSign < 1 || minExec < 1)
		throw Form::InitGradeTooHighException();
	else if (minSign > 150 || minExec > 150)
		throw Form::InitGradeTooLowException();
}

Form::~Form(void)
{
}

Form &			Form::operator=(Form const & rhs)
{
	(void)rhs;
	return (*this);
}

std::string		Form::getTarget(void) const
{
	return (_target);
}

bool			Form::getState(void) const
{
	return (_signed);
}

int				Form::getSignReq(void) const
{
	return (_minSign);
}

int				Form::getExecReq(void) const
{
	return (_minExec);
}


void			Form::beSigned(Bureaucrat const & target)
{
	try
	{
		if (_minSign < 1)
			throw Form::InitGradeTooHighException();
		else if (_minSign > 150)
			throw Form::InitGradeTooLowException();
		std::cout << "Bureaucrat" << target.getName() << " is trying to sign " << _name << " on " << _target << std::endl;
		_signed = target.signForm(_minSign, _target, _signed);
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
	o << rhs.getName() << " is a form of grade (sign " << rhs.getSignReq() << "; exec" << rhs.getSignReq() << ") and is currently " << (rhs.getState() ? "SIGNED." : "NOT SIGNED.") << std::endl;
	return (o);
}
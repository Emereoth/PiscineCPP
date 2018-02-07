/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:58:50 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 18:06:08 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string				Bureaucrat::getName(void) const
{
	return (_name);
}

int						Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void					Bureaucrat::upgrade(void)
{
	_grade--;
	try
	{
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void					Bureaucrat::downgrade(void)
{
	_grade++;
	try
	{
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}


// PRIVATE

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	(void)src;
}

Bureaucrat &			Bureaucrat::operator=(Bureaucrat const & src)
{
	(void)src;
	return (*this);
}


//EXTERN

std::ostream &			operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat of grade " << rhs.getGrade() << std::endl;
	return (o);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:58:50 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 09:28:13 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::InitGradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::InitGradeTooLowException();
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
			throw Bureaucrat::InitGradeTooHighException();
		else if (_grade > 150)
			throw Bureaucrat::InitGradeTooLowException();
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
			throw Bureaucrat::InitGradeTooHighException();
		else if (_grade > 150)
			throw Bureaucrat::InitGradeTooLowException();
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

bool					Bureaucrat::signForm(int requirement, std::string const & name, bool state) const
{
	if (requirement >= _grade && _grade > 0)
	{
		std::cout << _name << " signs " << name << std::endl;
		return (true);
	}
	else if (_grade > 0)
		std::cout << _name << " cannot sign " << name << " because his grade is too low (" << _grade << ")" << std::endl;
	else
		std::cout << _name << "cannot sign anything because his grade doesn't makes any sense (" << _grade << ")" << std::endl;
	return (state ? true : false);
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
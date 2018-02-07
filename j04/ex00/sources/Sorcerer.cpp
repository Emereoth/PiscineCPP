/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:14:32 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 13:09:58 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sorcerer.hpp"

// CONSTRUCTORS

Sorcerer::Sorcerer(std::string const & name, std::string const & title) : _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer &			Sorcerer::operator=(Sorcerer const & rhs)
{
	_name = rhs._name;
	_title = rhs._title;
	return (*this);
}

Sorcerer::Sorcerer(void)
{
}

// OTHER FUNCTIONS

std::string			Sorcerer::getName(void) const
{
	return (_name);
}

std::string			Sorcerer::getTitle(void) const
{
	return (_title);
}

void				Sorcerer::polymorph(Victim const & target) const
{
	target.getPolymorphed();
}

std::ostream &		operator<<(std::ostream & o, Sorcerer const & rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies!" << std::endl;
	return (o);
}
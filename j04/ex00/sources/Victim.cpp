/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:37:20 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 13:11:16 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Victim.hpp"

// CONSTRUCTORS

Victim::Victim(std::string const & name) : _name(name)
{
	std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim &			Victim::operator=(Victim const & rhs)
{
	_name = rhs._name;
	return (*this);
}

Victim::Victim(void)
{
}

// OTHER FUNCTIONS

std::string			Victim::getName(void) const
{
	return (_name);
}

void				Victim::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &		operator<<(std::ostream & o, Victim const & rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return (o);
}
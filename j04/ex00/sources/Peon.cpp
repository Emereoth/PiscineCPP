/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:49:29 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 13:12:17 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Peon.hpp"

// CONSTRUCTORS

Peon::Peon(std::string const & name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src) : Victim(src)
{
	*this = src;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &				Peon::operator=(Peon const & rhs)
{
	_name = rhs._name;
	return (*this);
}

Peon::Peon(void)
{
}

// OTHER FUNCTIONS

void				Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}

std::ostream &		operator<<(std::ostream & o, Peon const & rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return (o);
}
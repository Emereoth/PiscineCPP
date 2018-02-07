/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:16:44 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 18:49:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(this->getName(), this->getAPCost(), this->getDamage())
{
	*this = src;
}

PowerFist::~PowerFist(void)
{
}

PowerFist &		PowerFist::operator=(PowerFist const & rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

void				PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
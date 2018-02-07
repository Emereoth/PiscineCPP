/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:31:44 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 15:21:00 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AWeapon.hpp"

AWeapon::AWeapon(void)
{
}

AWeapon::AWeapon(std::string const & name, int apCost, int dmg) : _name(name), _apCost(apCost), _dmg(dmg)
{
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::~AWeapon(void)
{
}

AWeapon &			AWeapon::operator=(AWeapon const & rhs)
{
	_name = rhs._name;
	_apCost = rhs._apCost;
	_dmg = rhs._dmg;
	return (*this);
}

std::string	const		AWeapon::getName(void) const
{
	return (_name);
}

int					AWeapon::getAPCost(void) const
{
	return (_apCost);
}

int					AWeapon::getDamage(void) const
{
	return (_dmg);
}
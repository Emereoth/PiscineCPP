/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:42:17 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 18:49:13 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(this->getName(), this->getAPCost(), this->getDamage())
{
	*this = src;
}

PlasmaRifle::~PlasmaRifle(void)
{
}

PlasmaRifle &		PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

void				PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
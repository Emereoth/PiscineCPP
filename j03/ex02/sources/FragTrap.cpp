/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:59:28 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 17:11:35 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FR4G-TP", 100, 100, 100, 100, 1, "Anon", 30, 20, 5)
{
	std::cout << "Building a new FR4G-TP called Anon" << std::endl;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap("FR4G-TP", 100, 100, 100, 100, 1, name, 30, 20, 5)
{
	std::cout << "Building a new FR4G-TP called " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;	
	std::cout << "Building a new FR4G-TP called " << this->_name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destroying FR4G-TP " << this->_name << std::endl;
	ClapTrap::~ClapTrap();
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	this->_hp = rhs._hp;
	this->_hpMax = rhs._hpMax;
	this->_energy = rhs._energy;
	this->_energyMax = rhs._energyMax;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_meleeDmg = rhs._meleeDmg;
	this->_rangedDmg = rhs._rangedDmg;
	this->_armor = rhs._armor;
	return (*this);
}

int			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int			(FragTrap::*f[5])(std::string const &) = {&FragTrap::electrocute, &FragTrap::missileShot, &FragTrap::hammerBlow,
														&FragTrap::backflip, &FragTrap::selfDestruct};
	int			attack;
	static int	salt = rand() % 10;

	if (this->_energy < 25)
	{
		std::cout << "FR4G-TP " << this->_name << " has run out of energy. Too bad!" << std::endl;
		return (0);
	}
	this->_energy -= 25;
	srand(time(NULL));
	attack = (rand() + salt++) % 5;
	(this->*f[attack])(target);
	return (attack == 4 ? 1 : 0);
}

int			FragTrap::electrocute(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " launches a deadly bolt of electricity at " << target << "! Smells like burnt toast..." << std::endl;
	return (0);
}

int			FragTrap::missileShot(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " shoots a missile at " << target << "! Only a crater remains..." << std::endl;
	return (0);	
}

int			FragTrap::hammerBlow(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " hits " << target << " with a HUUUGE hammer. Rest in pieces." << std::endl;
	return (0);
}

int			FragTrap::backflip(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " backflips and smacks " << target << " across the head." << std::endl;
	return (0);
}

int			FragTrap::selfDestruct(std::string const & target)
{
	(void)target;
	std::cout << "FR4G-TP " << this->_name << " charges an attack, overheats and... Oh shit. It just disappeared in a nuclear fireball." <<std::endl;
	return (1);
}

std::ostream	&operator<<(std::ostream & o, FragTrap const & rhs)
{
	o << rhs.getHp();
	return (o);
}
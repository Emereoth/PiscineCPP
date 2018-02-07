/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:31:31 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 18:15:24 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/NinjaTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("NINJ4-TP", 60, 60, 120, 120, 1, "Anon", 60, 5, 0)
{
	std::cout << "Building a new NINJ4-TP called Anon" << std::endl;
}

NinjaTrap::NinjaTrap(std::string const & name) : ClapTrap("NINJ4-TP", 60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << "Building a new NINJ4-TP called " << name << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;	
	std::cout << "Building a new NINJ4-TP called " << this->_name << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "Destroying NINJ4-TP " << this->_name << std::endl;
	ClapTrap::~ClapTrap();
}

NinjaTrap &	NinjaTrap::operator=(NinjaTrap const & rhs)
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

std::string	NinjaTrap::getName(void) const
{
	return (this->_name);
}

void		NinjaTrap::ninjaShoebox(ClapTrap & src) const
{
	(void)src;
	std::cout << "Seeing that his enemy is just a harmless ClapTrap, " << this->_model << " " << this->_name << " doesn't attack." << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap & src) const
{
	src.breakArmor();
	std::cout << this->_model << " " << this->_name << " breaks " << src.getName() << "'s armor!" << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap & src) const
{
	std::cout << this->_model << " " << this->_name << " backstabs " << src.getName() << "! A brutal strike!" << std::endl;
	src.takeDamage(99);
}

void		NinjaTrap::ninjaShoebox(NinjaTrap & src) const
{
	std::cout << this->_model << " " << this->_name << " tries to backstab the enemy NinjaTrap, but " << src.getName() << " dodges the attack." << std::endl;
}
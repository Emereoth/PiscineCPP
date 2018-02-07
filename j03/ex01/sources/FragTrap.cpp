/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:59:28 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 14:08:07 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void) : _hp(100), _hpMax(100), _energy(100), _energyMax(100), _level(1),
							_name("Anon"), _meleeDmg(30), _rangedDmg(20), _armor(5)
{
	std::cout << "Building a new FR4G-TP called Anon" << std::endl;
}

FragTrap::FragTrap(std::string const & name) : _hp(100), _hpMax(100), _energy(100), _energyMax(100), _level(1),
							_name(name), _meleeDmg(30), _rangedDmg(20), _armor(5)
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

void		FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, inflicting " << this->_rangedDmg << " damage!" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " in melee, inflicting " << this->_meleeDmg << " damage!" << std::endl;
}

int			FragTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage = amount - this->_armor;

	this->_hp -= damage;
	std::cout << "FR4G-TP " << this->_name << " suffers " << damage << " damage! Aouch!" << std::endl;
	if (this->_hp <= 0)
	{
		std::cout << "FR4G-TP " << this->_name << " is dead!" << std::endl;
		if (this->_hp + 100 <= 0)
			std::cout << "OVERKILL! What did that poor Claptrap do to you? :(" << std::endl;
		return (1);
	}
	return (0);
}

void		FragTrap::beRepaired(unsigned int amount)
{
	unsigned int const	maxHeals = this->_hpMax - this->_hp;

	if (amount > maxHeals)
		amount = maxHeals;
	this->_hp += amount;
	std::cout << "FR4G-TP " << this->_name << " self-repairs for " << amount << "!" << std::endl;
}

int			FragTrap::getHp(void) const
{
	return (this->_hp);
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
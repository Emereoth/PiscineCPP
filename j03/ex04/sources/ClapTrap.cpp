/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:18:39 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 15:40:32 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "M D R" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name)
{
	std::cout << "Building a new CL4P-TP called " << name << std::endl;
}

ClapTrap::ClapTrap(std::string model, int hp, int hpMax, int energy, int energyMax, int level, std::string name, int meleeDmg, int rangedDmg, int armor) :
					_model(model), _hp(hp), _hpMax(hpMax), _energy(energy), _energyMax(energyMax), _level(level), _name(name), _meleeDmg(meleeDmg), _rangedDmg(rangedDmg), _armor(armor)
{
	std::cout << "lololol " << hp << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;	
}

ClapTrap::~ClapTrap(void)
{
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
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

void		ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->_model << " " << this->_name << " attacks " << target << " at range, inflicting " << this->_rangedDmg << " damage!" << std::endl;
}

void		ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << this->_model << " " << this->_name << " attacks " << target << " in melee, inflicting " << this->_meleeDmg << " damage!" << std::endl;
}

int			ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage = amount - this->_armor;

	std::cout << "damage : " << amount << std::endl;
	std::cout << "health: " << this->_hp << std::endl;
	std::cout << "armor: " << this->_armor << std::endl;
	if ((unsigned int)this->_hp + this->_armor >= amount)
		this->_hp -= damage;
	else
		this->_hp = 0;
	std:: cout << "hp : " << this->_hp << std::endl;
	std::cout << this->_model << " " << this->_name << " suffers " << damage << " damage! Aouch!" << std::endl;
	if (this->_hp <= 0)
	{
		std::cout << this->_model << " " << this->_name << " is dead!" << std::endl;
		if (this->_hp + 100 <= 0)
			std::cout << "OVERKILL! What did that poor Claptrap do to you? :(" << std::endl;
		return (1);
	}
	return (0);
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int const	maxHeals = this->_hpMax - this->_hp;

	if (amount > maxHeals)
		amount = maxHeals;
	this->_hp += amount;
	std::cout << this->_model << "." << this->_name << " self-repairs for " << amount << "!" << std::endl;
}

int			ClapTrap::getHp(void) const
{
	return (this->_hp);
}
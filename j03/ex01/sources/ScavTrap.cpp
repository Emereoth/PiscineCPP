/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:59:28 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 15:31:18 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _hp(100), _hpMax(100), _energy(50), _energyMax(50), _level(1),
							_name("Anon"), _meleeDmg(20), _rangedDmg(15), _armor(3)
{
	std::cout << "Building a new SC4V-TP called Anon" << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) : _hp(100), _hpMax(100), _energy(50), _energyMax(50), _level(1),
							_name(name), _meleeDmg(20), _rangedDmg(15), _armor(3)
{
	std::cout << "Building a new SC4V-TP called " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;	
	std::cout << "Building a new SC4V-TP called " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destroying SC4V-TP " << this->_name << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
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

void		ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range, inflicting " << this->_rangedDmg << " damage!" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " in melee, inflicting " << this->_meleeDmg << " damage!" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int	damage = amount - this->_armor;

	this->_hp -= damage;
	std::cout << "SC4V-TP " << this->_name << " suffers " << damage << " damage! Aouch!" << std::endl;
	if (this->_hp <= 0)
	{
		std::cout << "SC4V-TP " << this->_name << " is dead!" << std::endl;
		if (this->_hp + 100 <= 0)
			std::cout << "OVERKILL! What did that poor Claptrap do to you? :(" << std::endl;
	}
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int const	maxHeals = this->_hpMax - this->_hp;

	if (amount > maxHeals)
		amount = maxHeals;
	this->_hp += amount;
	std::cout << "SC4V-TP " << this->_name << " self-repairs for " << amount << "!" << std::endl;
}

int			ScavTrap::getHp(void) const
{
	return (this->_hp);
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	void		(ScavTrap::*f[5])(std::string const &) = {&ScavTrap::comeAtMe, &ScavTrap::dieScum, &ScavTrap::neverEnter,
														&ScavTrap::evilLaugh, &ScavTrap::dance};
	int			challenge;
	static int	salt = rand() % 10;

	srand(time(NULL));
	challenge = (rand() + salt++) % 5;
	(this->*f[challenge])(target);
}

void			ScavTrap::comeAtMe(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " shouts at " << target << ": \"Come at me, bot-... err, I meant 'bro'.\"" << std::endl;
}

void			ScavTrap::dieScum(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " shouts at " << target << ": \"Die, human scum!\"" << std::endl;
}

void			ScavTrap::neverEnter(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " shouts at " << target << ": \"Heh, you'll never enter into the Master's lair!\"" << std::endl;
}

void			ScavTrap::evilLaugh(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " laughs at " << target << "." << std::endl;
}

void			ScavTrap::dance(std::string const & target)
{
	std::cout << "SC4V-TP " << this->_name << " dances mockingly with " << target << "." <<std::endl;
}

std::ostream	&operator<<(std::ostream & o, ScavTrap const & rhs)
{
	o << rhs.getHp();
	return (o);
}
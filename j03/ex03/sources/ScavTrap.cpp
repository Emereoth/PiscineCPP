/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:59:28 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 17:51:50 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("SC4V-TP", 100, 100, 50, 50, 1, "Anon", 20, 15, 3)
{
	std::cout << "Building a new SC4V-TP called Anon" << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap("SC4V-TP", 100, 100, 50, 50, 1, name, 20, 15, 3)
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
	ClapTrap::~ClapTrap();
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

std::string		ScavTrap::getName(void) const
{
	return (this->_name);
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
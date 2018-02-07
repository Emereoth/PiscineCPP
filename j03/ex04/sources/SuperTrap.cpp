/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:51:42 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 15:45:39 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	this->_model = "SUP3R-TP";
    this->_name = "Anon";
    this->_hp = FragTrap::_hp;
    this->_hpMax = FragTrap::_hpMax;
    this->_energy = NinjaTrap::_energy;
    this->_energyMax = NinjaTrap::_energyMax;
    this->_level = 1;
    this->_meleeDmg = NinjaTrap::_meleeDmg;
    this->_rangedDmg = FragTrap::_rangedDmg;
    this->_armor = FragTrap::_armor;
   	std::cout << "Building a new SUP3R-TP called Anon" << std::endl;
}

SuperTrap::SuperTrap(std::string const & _name) : ClapTrap("SUP3R-TP", FragTrap::_hp, FragTrap::_hpMax
), FragTrap(), NinjaTrap()
{
	this->_model = "SUP3R-TP";	
    this->_name = _name;
    this->_hp = FragTrap::_hp;
    this->_hpMax = FragTrap::_hpMax;
    this->_energy = NinjaTrap::_energy;
    this->_energyMax = NinjaTrap::_energyMax;
    this->_level = 1;
    this->_meleeDmg = NinjaTrap::_meleeDmg;
    this->_rangedDmg = FragTrap::_rangedDmg;
    this->_armor = FragTrap::_armor;
    std::cout << "Building a new SUP3R-TP called " << this->_name << std::endl;
	std::cout << "base health : " << this->_hp << std::endl;
	std::cout << "wtf " << FragTrap::_hp << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src) : FragTrap(), NinjaTrap()
{
    std::cout << "Building a new SUP3R-TP called " << this->_name << std::endl;
    *this = src;
    return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "Destroying SUP3R-TP " << this->_name << std::endl;
	FragTrap::~FragTrap();
	NinjaTrap::~NinjaTrap();
}

SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs)
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
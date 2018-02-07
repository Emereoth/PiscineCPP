/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:21:48 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 18:51:02 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void)
{
}

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL)
{
	std::cout << "Here comes a new challenger: " << name << "!" << std::endl;
}

Character::Character(Character const & src) : _name(src.getName()), _ap(40), _weapon(src.getWeapon())
{
	std::cout << "Here comes a new challenger: " << src.getName() << "!" << std::endl;
}

Character::~Character(void)
{
	std::cout << _name << " leaves the realm of the living..." << std::endl;
}

Character &					Character::operator=(Character const & rhs)
{
	_name = rhs._name;
	_ap = rhs._ap;
	_weapon = rhs._weapon;
	return (*this);
}

void						Character::recoverAP(void)
{
	if (_ap >= 30)
		_ap = 40;
	else
		_ap += 10;
}

void						Character::equip(AWeapon * weapon)
{
	_weapon = weapon;
}

void						Character::attack(Enemy * target)
{
	if (_ap < _weapon->getAPCost())
		return ;
	_ap -= _weapon->getAPCost();
	std::cout << _name << " attacks " << target->getType() << " with " << _weapon->getName() << std::endl;
	_weapon->attack();
	target->takeDamage(_weapon->getDamage());
	if (target->getHP() <= 0)
		delete target;
}

std::string					Character::getName(void) const
{
	return (_name);
}

int							Character::getAP(void) const
{
	return (_ap);
}

AWeapon *					Character::getWeapon(void) const
{
	return (_weapon);
}

std::ostream &				operator<<(std::ostream & o, Character const & src)
{
	std::string			str;
	std::string			weaponInfo;
	std::string			wields = "wields a ";

	weaponInfo = src.getWeapon() ? wields.append(src.getWeapon()->getName()) : "is unarmed";
	o << src.getName() << " has " << src.getAP() << " AP and " << weaponInfo << "." << std::endl;
	return (o);
}
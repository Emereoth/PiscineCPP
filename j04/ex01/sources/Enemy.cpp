/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:23:30 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 18:56:12 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.hpp"

Enemy::Enemy(void)
{
}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type)
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy(void)
{
}

Enemy &		Enemy::operator=(Enemy const & rhs)
{
	_hp = rhs._hp;
	_type = rhs._type;
	return (*this);
}

std::string	Enemy::getType(void) const
{
	return (_type);
}

int			Enemy::getHP(void) const
{
	return (_hp);
}

void		Enemy::takeDamage(int dmg)
{
	if (dmg > 0)
	{
		if (dmg >= this->_hp)
			this->_hp = 0;
		else
			_hp -= dmg;
	}
}
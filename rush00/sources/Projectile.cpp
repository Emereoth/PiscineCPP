/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:11:17 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:06:40 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Projectile.hpp"
#include "../includes/Arena.hpp"
#include "../includes/Player.hpp"
#include "../includes/Enemy.hpp"
#include "../includes/Time.hpp"

Projectile::Projectile(int const x, int const y, int const speed, int const dmg, bool alive, Arena * arena) : AEntity(x, y), _speed(speed), _dmg(dmg), _alive(alive), _arena(arena), _yf(y)
{
}

Projectile::~Projectile(void)
{
}

int				Projectile::getX(void) const
{
	return (_x);
}

int				Projectile::getY(void) const
{
	return (_y);
}

int				Projectile::getSpeed(void) const
{
	return (_speed);
}

int				Projectile::getDmg(void) const
{
	return (_dmg);
}

bool			Projectile::getState(void) const
{
	return (_alive);
}

Arena *			Projectile::getArena(void) const
{
	return (_arena);
}

void			Projectile::activate(int const x, int const y, int const speed, int const dmg)
{
	this->_x = x;
	this->_y = y;
	this->_yf = y;
	this->_speed = speed;
	this->_dmg = dmg;
	this->_alive = true;
}

void			Projectile::advance(void)
{
	int				hit;
	float			destination = _yf - ((float)_speed * Time::deltaTime());

	if ((hit = _arena->checkMissileCollision(_x, (int)destination)) != -1)
	{
		_arena->getEnemy(hit)->takeDmg(_dmg);
		this->disableMissile();
	}
	else if ((int)destination < 0)
		this->disableMissile();
	else
	{
		_yf = destination;
		_y = (int)destination;
	}
}

Projectile::Projectile(void) : _arena((new Arena))
{
}

Projectile::Projectile(Projectile const & src) : _arena(src.getArena())
{
}

Projectile &	Projectile::operator=(Projectile const & src)
{
	_x = src.getX();
	_y = src.getY();
	_speed = src.getSpeed();
	_dmg = src.getDmg();
	_alive = src.getState();
	_arena = src.getArena();
	return (*this);
}

void			Projectile::disableMissile(void)
{
	this->_x = -1;
	this->_y = -1;
	this->_yf = -1;
	this->_speed = 0;
	this->_dmg = 0;
	this->_alive = false;
}
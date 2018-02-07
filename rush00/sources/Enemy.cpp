/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:02:17 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:55:54 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Enemy.hpp"
#include "../includes/Time.hpp"

Enemy::Enemy(int const x, int const y, int const hp, Arena * map) : AEntity(x, y), _yf(y), _startingX(x), _startingY(y), _hp(hp), _startHp(hp), _arena(map), _alive(true), _speed(3)
{
	_isAliveAtStart = false;
}

Enemy::~Enemy(void)
{
}

void			Enemy::setX(int x) {

	if (x < 0 || x >= LINES)
		return ;
	_x = x;
}

void			Enemy::setY(int y) {

	if (y < 0 || y >= COLS)
		return ;
	_y = y;
}

int				Enemy::getX(void) const
{
	return (_x);
}

int				Enemy::getY(void) const
{
	return (_y);
}

bool			Enemy::getState(void) const
{
	return (_alive);
}

Arena *			Enemy::getArena(void) const
{
	return (_arena);
}

int				Enemy::move()
{
	float		destination = _yf + ((float) _speed * Time::deltaTime());

	for (int i = 0 ; (unsigned int)i < _arena->_totalUsedEnemies ; i++)
	{
		if ((int)destination >= LINES)
		{
			// decrement
			_arena->decrementAliveEnemiesCount();
			_alive = false;
		}
		else
		{
			_yf = destination;
			_y = (int)destination;
		}
	}
	return (0);
}

void			Enemy::takeDmg(int const dmg)
{
	_hp -= dmg;
	if (_hp <= 0)
	{
		// decrement
		_arena->decrementAliveEnemiesCount();
		_alive = false;
	}
}

void			Enemy::resetPos(void)
{
	_x = _startingX;
	_y = _startingY;
}

void			Enemy::respawn(void)
{
	_hp = _startHp;
	_alive = true;
}

void			Enemy::buff(void)
{
	_hp++;
	_startHp++;
	_speed++;
}

void			Enemy::setIsAliveAtStart(bool value) {

	_isAliveAtStart = value;
}

void			Enemy::resetAlive(void) {

	_alive = _isAliveAtStart;
}

Enemy::Enemy(void) : _arena((new Arena))
{
}

Enemy::Enemy(Enemy const & src) : _arena(src.getArena())
{
	*this = src;
}

Enemy & 			Enemy::operator=(Enemy const & rhs)
{
	this->_startingX = rhs._startingX;
	this->_startingY = rhs._startingY;
	this->_hp = rhs._hp;
	this->_startHp = rhs._startHp;
	this->_arena = rhs._arena;
	this->_alive = rhs._alive;
	this->_isAliveAtStart = rhs._isAliveAtStart;

	return (*this);
}
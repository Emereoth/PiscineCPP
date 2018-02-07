/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:38:25 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:57:12 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include <ncurses.h>

Player::Player(int const x, int const y, Arena * map) : AEntity(x, y), _dmg(DAMGES), _projSpd(PROJ_SPEED), _arena(map), _isAlive(true)
{
	_xf = _x;
	_yf = _y;
}

Player::~Player(void)
{
}

int				Player::getX(void) const
{
	return (_x);
}

int				Player::getY(void) const
{
	return (_y);
}

Arena *			Player::getArena(void) const
{
	return (_arena);
}

int				Player::move(int const x, int const y, int const cols)
{
	float targetX = _xf + ((float)x * ((float)(PLAYER_X_SPEED) * Time::deltaTime()));
	float targetY = _yf + ((float)y * ((float)(PLAYER_Y_SPEED) * Time::deltaTime()));

	if ((ABS(x) - ABS(y)) == 0)
	{
		targetX /= SQRT2;
		targetY /= SQRT2;
	}
	if (((int)targetX >= COLS / 2 + cols - 10) || ((int)targetX <= COLS / 2 - cols + 6)
		|| ((int)targetY == 0) || ((int)targetY >= LINES - 1))
		return (-1);
	if (_arena->checkShipCollision((int)targetX, (int)targetY) == true)
	{
		_isAlive = false;
		return (1);
	}
	
	_xf = targetX;
	_yf = targetY;

	_x = (int)targetX;
	_y = (int)targetY;
	return (0);
}

int			Player::fire(void)
{
	Projectile		*missile;

	missile = this->_arena->getAvailableMissile();
	if (missile == NULL)
		return (0);
	missile->activate(_x + 1, _y - 1, _projSpd, _dmg);
	return (200);

}

bool				Player::isAlive( void ) const {

	return _isAlive;
}

void				Player::buff(void)
{
	_dmg++;
	_projSpd += 10;
}

// Private

Player::Player(void) : _arena((new Arena)), _isAlive(true)
{
}

Player::Player(Player const & src) : _arena(src.getArena()), _isAlive(true)
{
}

Player & 		Player::operator=(Player const & src)
{
	(void)src;
	return (*this);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arena.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:24:11 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:23:53 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Arena.hpp"
#include "../includes/Enemy.hpp"
#include "../includes/Projectile.hpp"
#include "../includes/AEntity.hpp"
#include "../includes/Time.hpp"

Arena::Arena(void) : _aliveEnemiesCount(0)
{
	_waveManager = new WaveManager(this);
	for (int i = 0; i < MISSILE_MAX; i++)
	{
		_missiles[i] = new Projectile(-1, -1, 0, 0, false, this);
	}
}

Arena::~Arena(void)
{
}

void			Arena::addEntity(Enemy * src)
{
	_fleet[_aliveEnemiesCount] = src;
	_aliveEnemiesCount++;
}

Projectile		*Arena::getAvailableMissile(void)
{
	int			newIndex = -1;

	for (int i = 0; i < MISSILE_MAX; i++)
	{
		if (!_missiles[i]->getState())
		{
			newIndex = i;
			break;
		}
	}
	if (newIndex != -1)
		return (_missiles[newIndex]);
	return (NULL);
}

Projectile *	Arena::getMissile(int index) const
{
	return (_missiles[index]);
}

Enemy *			Arena::getEnemy(int index) const
{
	return (_fleet[index]);
}

bool			Arena::checkShipCollision(int const x, int const y) const
{
	unsigned int	i = 0;

	while (i < _totalUsedEnemies)
	{	
		// if the enemie isn't alive, dont check collision with it
		if (_fleet[i]->getState() == false)
		{
			i++;
			continue ;
		}
		if (ABS(x - _fleet[i]->getX()) < 3 && ABS(y - _fleet[i]->getY()) < 2)
			return true;
		i++;
	}
	return (false);
}
int				Arena::checkMissileCollision(int const x, int const y) const
{
	int		i = 0;
	int 	xF;
	int 	yF;
	
	while (i < (int)_totalUsedEnemies)
	{
		xF = _fleet[i]->getX();
		yF = _fleet[i]->getY();

		if ((x >= xF && x < xF + 3) && yF >= y && _fleet[i]->getState() == true)
			return (i);
		i++;
	}
	return (-1);
}

void			Arena::moveAll()
{
	for (unsigned int i = 0; i < _totalUsedEnemies ; i++)
	{
		if (_fleet[i]->getState())
			_fleet[i]->move();
	}
	for	(int j = 0 ; j < MISSILE_MAX ; j++)
	{
		if (_missiles[j]->getState())
			_missiles[j]->advance();
	}
}

void			Arena::respawnEnemies(void)
{
	for (int i = 0 ; i < ENEMY_MAX ; i++)
	{
		_fleet[i]->resetPos();
		_fleet[i]->respawn();
	}
}

Enemy *const*	Arena::getEnemyFleet( void ) const {

	return _fleet;
}

void			Arena::setAliveEnemiesCount( unsigned int value ) {

	_aliveEnemiesCount = value;
}

unsigned int	Arena::getAliveEnemiesCount( void ) const {

	return _aliveEnemiesCount;
}

void			Arena::decrementAliveEnemiesCount( void ) {

	spawned--;
	if (spawned == 0)
		_waveManager->spawnNextWave();
}

Arena::Arena(Arena const & src)
{
	*this = src;
}

Arena * 		Arena::operator=(Arena const & src)
{
	for (int i = 0; i < ENEMY_MAX; i++)
		this->_fleet[i] = src._fleet[i];
	for (int i = 0; i < MISSILE_MAX; i++)
		this->_missiles[i] = src._missiles[i];
	this->_waveManager = src._waveManager;
	this->_aliveEnemiesCount = src._aliveEnemiesCount;
	return (this);
}

WaveManager		*Arena::getWaveManager(void)
{
	return _waveManager;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arena.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:20:43 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:22:04 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_HPP
# define ARENA_HPP

#include "AEntity.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"
#include "WaveManager.hpp"

#define ABS(value)  ( (value) >= 0 ? (value) : -(value) )

class Enemy;
class WaveManager;

class Arena 
{
	public:
		Arena(void);
		~Arena(void);
		Arena * 		operator=(Arena const & src);
		void			addEntity(Enemy * src);
		void			addEntity(Projectile const & src);
		bool			checkShipCollision(int const x, int const y) const;
		int				checkMissileCollision(int const x, int const y) const;
		void			moveAll();
		Projectile		*getAvailableMissile(void);
		Projectile *	getMissile(int index) const;
		Enemy *			getEnemy(int index) const;
		Enemy *const*	getEnemyFleet( void ) const;
		void			setAliveEnemiesCount( unsigned int value );
		unsigned int	getAliveEnemiesCount( void ) const;
		unsigned int    _totalUsedEnemies;
		void			decrementAliveEnemiesCount( void );
		unsigned int    _aliveEnemiesCount;
		int				spawned;
		WaveManager *	getWaveManager( void );

	private:
		Arena(Arena const & src);
		void			respawnEnemies(void);

		Enemy *			_fleet[ENEMY_MAX];
		Projectile *	_missiles[MISSILE_MAX];
		WaveManager	*	_waveManager;
};

#endif
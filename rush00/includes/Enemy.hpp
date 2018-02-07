/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:56:35 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:22:28 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Arena.hpp"
#include "Windows.hpp"

#define ENEMY_MODEL1 "/V\\"
#define ENEMY_MODEL2 "\\O/"

class Arena;

class Enemy: public AEntity
{
	public:
		Enemy(int const x, int const y, int const hp, Arena * map);
		Enemy(Enemy const & src);
		~Enemy(void);
		Enemy & operator=(Enemy const & rhs);

		int			getX(void) const;
		int			getY(void) const;
		void		setX(int x);
		void		setY(int y);
		bool		getState(void) const;
		Arena *		getArena(void) const;
		int			move();
		void		takeDmg(int const dmg);
		void		resetPos(void);
		void		setIsAliveAtStart(bool value);
		void		resetAlive(void);
		void		respawn(void);
		void		buff(void);

	private:
		Enemy(void);

		float		_yf;
		int			_startingX;
		int			_startingY;
		int			_hp;
		int			_startHp;
		Arena *		_arena;
		bool		_alive;
		bool		_isAliveAtStart;
		int			_speed;
};

#endif
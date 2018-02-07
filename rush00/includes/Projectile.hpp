/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:58:01 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 18:50:58 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

class Player;
class Arena;

#include "AEntity.hpp"

class Projectile: public AEntity
{
	public:
		Projectile(int const x, int const y, int const speed, int const dmg, bool alive, Arena * arena);
		~Projectile(void);
		Projectile & 	operator=(Projectile const & src);

		int				getX(void) const;
		int				getY(void) const;
		int				getSpeed(void) const;
		int				getDmg(void) const;
		bool			getState(void) const;
		Arena *			getArena(void) const;
		void			advance(void);
		void			activate(int const x, int const y, int const speed, int const dmg);

	private:
		Projectile(void);
		Projectile(Projectile const & src);

		void			disableMissile(void);

		int				_speed;
		int				_dmg;
		bool			_alive;
		Arena *			_arena;
		float			_yf;
};

#endif
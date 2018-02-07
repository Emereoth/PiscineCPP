/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:35:18 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:56:35 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Arena.hpp"
#include "Projectile.hpp"
#include "Time.hpp"

#define PLAYER_MODEL1 "/|\\"
#define PLAYER_MODEL2 "\\_/"
#define PROJ_SPEED 50
#define DAMGES 1
#define PLAYER_X_SPEED 2000.0
#define PLAYER_Y_SPEED 2000.0
#define SQRT2 1.4142

class Player: public AEntity
{
	public:
		Player(int const x, int const y, Arena * map);
		~Player(void);

		int			getX(void) const;
		int			getY(void) const;
		Arena *		getArena(void) const;
		int			move(int const x, int const y, int const cols);
		int			fire(void);
		bool		isAlive( void ) const;
		void		buff(void);
		
	private:
		Player(void);
		Player(Player const & src);
		Player & operator=(Player const & rhs);

		float						_xf;
		float						_yf;
		int							_dmg;
		int							_projSpd;
		Arena *						_arena;
		bool						_isAlive;
};

#endif
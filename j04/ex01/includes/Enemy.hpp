/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:17:52 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 17:03:27 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual ~Enemy(void);

		Enemy & 			operator=(Enemy const & rhs);

		std::string			getType(void) const;
		int					getHP(void) const;
		virtual void		takeDamage(int dmg);
		
	private:
		Enemy(void);

		int					_hp;
		std::string			_type;
};

#endif
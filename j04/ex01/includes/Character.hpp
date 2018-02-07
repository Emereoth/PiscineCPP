/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:17:01 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 18:05:12 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character 
{
	public:
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);

		Character & 				operator=(Character const & rhs);

		void						recoverAP(void);
		void						equip(AWeapon * weapon);
		void						attack(Enemy * target);
		std::string					getName(void) const;
		int							getAP(void) const;
		AWeapon *					getWeapon(void) const;

	private:
		Character(void);

		std::string					_name;
		int							_ap;
		AWeapon *					_weapon;
};

std::ostream &			operator<<(std::ostream & o, Character const & src);

#endif
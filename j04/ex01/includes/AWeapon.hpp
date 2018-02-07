/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:24:20 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 17:39:25 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>
#include <iostream>

class AWeapon
{
	public:
		AWeapon(std::string const & name, int apCost, int dmg);
		AWeapon(AWeapon const & src);
		virtual ~AWeapon(void);

		AWeapon &			operator=(AWeapon const & rhs);

		virtual void		attack(void) const = 0;
		std::string	const 	getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;

	private:
		AWeapon(void);
	
		std::string			_name;
		int					_apCost;
		int					_dmg;

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:47:15 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 13:55:08 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>

class FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		FragTrap &	operator=(FragTrap const & rhs);
		

		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
		int			takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		int			vaulthunter_dot_exe(std::string const & target);

		int			getHp(void) const;

	private:
		int			_hp;
		int			_hpMax;
		int			_energy;
		int			_energyMax;
		int			_level;
		std::string	_name;
		int			_meleeDmg;
		int			_rangedDmg;
		int			_armor;

		int			electrocute(std::string const & target);
		int			missileShot(std::string const & target);
		int			hammerBlow(std::string const & target);
		int			backflip(std::string const & target);
		int			selfDestruct(std::string const & target);
};

std::ostream		&operator<<(std::ostream & o, FragTrap const & rhs);

#endif
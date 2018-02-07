/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:14:49 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 19:57:52 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const & name);
		ClapTrap(std::string model, int hp, int hpMax, int energy, int energyMax, int level, std::string name, int meleeDmg, int rangedDmg, int armor);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap &	operator=(ClapTrap const & rhs);

		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
		int			takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		int			getHp(void) const;

	protected:

		std::string	_model;
		int			_hp;
		int			_hpMax;
		int			_energy;
		int			_energyMax;
		int			_level;
		std::string	_name;
		int			_meleeDmg;
		int			_rangedDmg;
		int			_armor;
};

#endif
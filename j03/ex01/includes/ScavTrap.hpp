/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:47:15 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 15:24:38 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>

class ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		ScavTrap &	operator=(ScavTrap const & rhs);

		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		
		void		challengeNewcomer(std::string const & target);

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

		void		comeAtMe(std::string const & target);
		void		dieScum(std::string const & target);
		void		neverEnter(std::string const & target);
		void		evilLaugh(std::string const & target);
		void		dance(std::string const & target);
};

std::ostream		&operator<<(std::ostream & o, ScavTrap const & rhs);

#endif
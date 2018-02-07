/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:47:15 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 16:28:25 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
		ScavTrap &	operator=(ScavTrap const & rhs);

		void		challengeNewcomer(std::string const & target);

	private:
		void		comeAtMe(std::string const & target);
		void		dieScum(std::string const & target);
		void		neverEnter(std::string const & target);
		void		evilLaugh(std::string const & target);
		void		dance(std::string const & target);
};

std::ostream		&operator<<(std::ostream & o, ScavTrap const & rhs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:20:14 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 18:13:46 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string const & name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap(void);
		NinjaTrap &	operator=(NinjaTrap const & rhs);

		std::string	getName(void) const;
		void		ninjaShoebox(ClapTrap & src) const;
		void		ninjaShoebox(FragTrap & src) const;
		void		ninjaShoebox(ScavTrap & src) const;
		void		ninjaShoebox(NinjaTrap & src) const;
};

#endif
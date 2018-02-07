/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:47:15 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 18:14:29 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		FragTrap &	operator=(FragTrap const & rhs);

		int			vaulthunter_dot_exe(std::string const & target);
		std::string	getName(void) const;
		void		breakArmor(void);

	private:
		int			electrocute(std::string const & target);
		int			missileShot(std::string const & target);
		int			hammerBlow(std::string const & target);
		int			backflip(std::string const & target);
		int			selfDestruct(std::string const & target);
};

std::ostream		&operator<<(std::ostream & o, FragTrap const & rhs);

#endif
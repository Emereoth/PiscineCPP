/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:43:32 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 19:46:11 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap
{
	public:
		SuperTrap(void);
		SuperTrap(std::string const & name);
		SuperTrap(SuperTrap const & src);
		~SuperTrap(void);
		SuperTrap &	operator=(SuperTrap const & rhs);
};

std::ostream		&operator<<(std::ostream & o, SuperTrap const & rhs);

#endif
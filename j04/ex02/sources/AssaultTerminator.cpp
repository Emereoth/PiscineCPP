/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:58:30 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 21:55:13 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space  *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	*this = src;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "Ill be back ..." << std::endl;
}

AssaultTerminator & 			AssaultTerminator::operator=(AssaultTerminator const & src)
{
	(void)src;
	return (*this);
}

AssaultTerminator *			AssaultTerminator::clone(void) const
{
	AssaultTerminator * 	clone = new AssaultTerminator;

	return (clone);
}

void					AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void					AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void					AssaultTerminator::meleeAttack(void) const
{
	std::cout << "*  attacks with chainfists *" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:28:43 by acottier          #+#    #+#             */
/*   Updated: 2018/01/13 09:20:07 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle." << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	*this = src;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine & 			TacticalMarine::operator=(TacticalMarine const & src)
{
	(void)src;
	return (*this);
}

TacticalMarine *			TacticalMarine::clone(void) const
{
	TacticalMarine * 	clone = new TacticalMarine;

	return (clone);
}

void					TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void					TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void					TacticalMarine::meleeAttack(void) const
{
	std::cout << "*  attacks with chainsword *" << std::endl;
}
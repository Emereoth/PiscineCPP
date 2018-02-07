/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:26:58 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 21:01:17 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Squad.hpp"
#include "../includes/TacticalMarine.hpp"
#include "../includes/AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;

	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
	ISpaceMarine* cur = vlc->getUnit(i);
	cur->battleCry();
	cur->rangedAttack();
	cur->meleeAttack();
	}
	delete vlc;
	
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:53:21 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 19:29:57 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PlasmaRifle.hpp"
#include "../includes/PowerFist.hpp"
#include "../includes/SuperMutant.hpp"
#include "../includes/RadScorpion.hpp"
#include "../includes/Character.hpp"

int		main(void)
{
	Character* lw = new Character("The Lone Wanderer");

	std::cout << *lw;
	Enemy* sc = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	lw->equip(pr);
	lw->attack(sc);
	std::cout << *lw;
	lw->attack(sc);
	lw->attack(sc);
	lw->attack(sc);
	lw->equip(pf);
	std::cout << *lw;	
	Enemy* sm = new SuperMutant();
	lw->attack(sm);
	lw->attack(sm);
	lw->recoverAP();
	lw->recoverAP();
	std::cout << *lw;	
	lw->attack(sm);
	lw->attack(sm);
	return 0;
}
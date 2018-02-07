/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:29:40 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 15:45:45 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/NinjaTrap.hpp"
#include "../includes/SuperTrap.hpp"


int		main(void)
{
	// ClapTrap	clap("Skibidi");
	// FragTrap	frag;
	// ScavTrap	scav("jensaisrienmoi");
	// NinjaTrap	ninja("Bobi");
	SuperTrap	super("boss");

//	super.ninjaShoebox(frag);
//	frag.vaulthunter_dot_exe("mabite");
	super.takeDamage(100);
	std::cout << "remainin hp : " << super.getHp() << std::endl;
}

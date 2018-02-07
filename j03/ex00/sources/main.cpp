/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:29:40 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 13:55:21 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int		main(void)
{
	FragTrap	bob("Bob");
	std::string	target = "a random enemy";

	bob.meleeAttack(target);
	bob.rangedAttack(target);
	if (bob.takeDamage(100))
		return (1);
	std::cout << "(Remaining hp : " << bob << ")" << std::endl;
	bob.beRepaired(25);
	std::cout << "(Remaining hp : " << bob << ")" << std::endl;
	// if (bob.takeDamage(100))
	// 	return (1);
	if (bob.vaulthunter_dot_exe(target))
		return (1);
	if (bob.vaulthunter_dot_exe(target))
		return (1);
	if (bob.vaulthunter_dot_exe(target))
		return (1);
	if (bob.vaulthunter_dot_exe(target))
		return (1);
	if (bob.vaulthunter_dot_exe(target))
		return (1);
}
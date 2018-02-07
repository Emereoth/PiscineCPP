/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:29:40 by acottier          #+#    #+#             */
/*   Updated: 2018/01/11 17:16:50 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"


int		main(void)
{
	std::string	target = "a random enemy";
	
	FragTrap	bob("Bob");
	while (bob.getHp() > 0)
	{
		bob.meleeAttack(target);
		bob.rangedAttack(target);
		bob.takeDamage(100);
		std::cout << "(Remaining hp : " << bob << ")" << std::endl;
		bob.beRepaired(100);
		std::cout << "(Remaining hp : " << bob << ")" << std::endl;
		// bob.takeDamage(100);
		bob.vaulthunter_dot_exe(target);
		bob.vaulthunter_dot_exe(target);
		bob.vaulthunter_dot_exe(target);
		bob.vaulthunter_dot_exe(target);
		bob.vaulthunter_dot_exe(target);
		bob.takeDamage(9999);
	}

	std::cout << "----------" << std::endl;

	ScavTrap	bill("Bill");	
	while (bill.getHp() > 0)
	{
		bill.meleeAttack(target);
		bill.rangedAttack(target);
		bill.takeDamage(100);
		std::cout << "(Remaining hp : " << bill << ")" << std::endl;
		bill.beRepaired(100);
		std::cout << "(Remaining hp : " << bill << ")" << std::endl;
		// bill.takeDamage(100);
		bill.challengeNewcomer(target);
		bill.challengeNewcomer(target);
		bill.challengeNewcomer(target);
		bill.challengeNewcomer(target);
		bill.challengeNewcomer(target);
		bill.takeDamage(9999);
	}
}
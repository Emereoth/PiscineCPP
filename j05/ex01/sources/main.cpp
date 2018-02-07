/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:25:53 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 18:10:38 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#include <iostream>

int		main()
{
	try
	{
		Bureaucrat	genius("Einstein", 1);
		Form		ez("E. Z. form", 150);
		Form		hard("Hard form", 1);
		ez.beSigned(genius);
		hard.beSigned(genius);
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
	try
	{
		Bureaucrat	dumbass("Dumbass", 150);
		Form		ez("E. Z. form", 150);
		Form		hard("Hard form", 1);
		ez.beSigned(dumbass);
		hard.beSigned(dumbass);
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
	return (0);
}
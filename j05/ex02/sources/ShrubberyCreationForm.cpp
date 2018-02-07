/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:20:09 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 18:28:20 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreation.hpp"

ShrubberyCreation::ShrubberyCreation(std::string name, std::string target) : Form(name, target, 145, 137)
{
}

ShrubberyCreation::~ShrubberyCreation(void)
{
}

void						ShrubberyCreation::execute(Bureaucrat const & executor)
{
	std::ofstream		ofs;
	std::string			tree = "\\  |  /\n \\ | /\n  \\|/\n   |\n   |\n   |\n\n";

	ofs.open(_target + "_shrubbery", std:ofstream:app);
	try
	{
		std::cout << "Bureaucrat " << executor.getName() << " tries to execute a ShrubberyCreation form..." << std::endl;
		if (executor.getGrade() > _minExec)
			throw ExecutionFailException();
		ofs << tree << tree << std::endl;
		ofs.close();
	}
	catch (std::exception & exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

// PRIVATE

ShrubberyCreation::ShrubberyCreation(void)
{
}

ShrubberyCreation(ShrubberyCreation const & src)
{
	(void)src;
}

ShrubberyCreation &		ShrubberyCreation::operator=(ShrubberyCreation const & rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &			operator<<(std::ostream & o, ShrubberyCreation const & rhs)
{
	o << rhs.getName() << " is a ShrubberyCreation form of grade (sign " << rhs.getSignReq() << "; exec" << rhs.getSignReq() << ") and is currently " << (rhs.getState() ? "SIGNED." : "NOT SIGNED.") << std::endl;
	return (o);
}
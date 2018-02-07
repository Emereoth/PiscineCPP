/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:19:15 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 18:19:55 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_HPP
# define SHRUBBERY_CREATION_HPP

#include "Form.hpp"

class ShrubberyCreation : public Form
{
	public:
		ShrubberyCreation(std::string name, std::string target);
		virtual ~ShrubberyCreation(void);

		void						execute(Bureaucrat const & executor);

	private:
		ShrubberyCreation(void);
		ShrubberyCreation(ShrubberyCreation const & src);

		ShrubberyCreation &		operator=(ShrubberyCreation const & rhs);
};

std::ostream &			operator<<(std::ostream & o, Form const & rhs);

#endif
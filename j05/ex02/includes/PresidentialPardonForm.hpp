/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:19:25 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 09:46:38 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_HPP
# define PRESIDENTIAL_PARDON_HPP

#include "Form.hpp"

class PresidentialPardon : public Form
{
	public:
		PresidentialPardon(std::string name, std::string target);
		virtual ~PresidentialPardon(void);

		void						execute(Bureaucrat const & executor);

	private:
		PresidentialPardon(void);
		PresidentialPardon(PresidentialPardon const & src);

		PresidentialPardon &		operator=(PresidentialPardon const & rhs);
};

std::ostream &			operator<<(std::ostream & o, Form const & rhs);

#endif
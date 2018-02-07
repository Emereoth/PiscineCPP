/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:26:20 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 09:46:43 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_HPP
# define ROBOTOMY_REQUEST_HPP

#include "Form.hpp"

class RobotomyRequest : public Form
{
	public:
		RobotomyRequest(std::string name, std::string target);
		virtual ~RobotomyRequest(void);

		void						execute(Bureaucrat const & executor);

	private:
		RobotomyRequest(void);
		RobotomyRequest(RobotomyRequest const & src);

		RobotomyRequest &		operator=(RobotomyRequest const & rhs);
};

std::ostream &			operator<<(std::ostream & o, Form const & rhs);

#endif
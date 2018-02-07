/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:45:17 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 18:11:08 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, int requirement);
		virtual ~Form(void);
	

		std::string		getName(void) const;
		int				getRequirements(void) const;
		bool			getState(void) const;
		void			beSigned(Bureaucrat const & target);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade requirements are off-limits: form requirements too high.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade requirements are off-limits: form requirements too low.");
				}
		};

	private:
		Form(void);
		Form(Form const & src);
		Form &			operator=(Form const & rhs);

		std::string const	_name;
		bool				_signed;
		int					_minGrade;
};

std::ostream &			operator<<(std::ostream & o, Form const & rhs);

#endif
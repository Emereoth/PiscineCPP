/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:45:17 by acottier          #+#    #+#             */
/*   Updated: 2018/01/16 10:10:13 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
	public:
		Form(std::string name, std::string target, int minSign, int minExec);
		virtual ~Form(void);
	
		std::string		getName(void) const;
		std::string		getTarget(void) const;
		int				getSignReq(void) const;
		int				getExecReq(void) const;
		bool			getState(void) const;
		void			beSigned(Bureaucrat const & target);
		virtual void	execute(Bureaucrat const & executor);

		class InitGradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade requirements are off-limits: form requirements too high.");
				}
		};

		class InitGradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade requirements are off-limits: form requirements too low.");
				}
		};

		class SignatureFailedException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("I can't sign that form!");
				}
		};

		class ExecutionFailedException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("I can't execute that form!");
				}
		};
	
	protected:

		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		int					_minSign;
		int					_minExec;

	private:
		Form(void);
		Form(Form const & src);

		Form &			operator=(Form const & rhs);

};

std::ostream &			operator<<(std::ostream & o, Form const & rhs);

#endif
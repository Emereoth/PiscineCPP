/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:54:43 by acottier          #+#    #+#             */
/*   Updated: 2018/01/15 15:32:03 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	public:
		Bureaucrat(std::string const & name, int grade);
		virtual ~Bureaucrat(void);

		Bureaucrat &		operator=(Bureaucrat const & rhs);

		std::string			getName(void) const;
		int					getGrade(void) const;
		void				upgrade(void);
		void				downgrade(void);
		bool				signForm(int requirement, std::string const & name, bool state) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureaucrat grade is too high, we don't hire over qualified people here.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Bureaucrat grade is too low, get the hell ouf of here!");
				}
		};

	private:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);

		std::string const		_name;
		int						_grade;
};

std::ostream &			operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
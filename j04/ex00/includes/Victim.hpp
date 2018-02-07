/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:30:22 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 13:10:48 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
	public:
		Victim(std::string const & name);
		Victim(Victim const & src);
		~Victim(void);

		Victim &			operator=(Victim const & rhs);

		std::string			getName(void) const;
		virtual void		getPolymorphed(void) const;
		
	protected:
		Victim(void);

		std::string			_name;
};

std::ostream &	operator<<(std::ostream & o, Victim const & rhs);

#endif
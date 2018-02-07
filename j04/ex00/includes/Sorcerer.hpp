/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:25:43 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 13:08:47 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP 

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(std::string const & name, std::string const & title);
		Sorcerer(Sorcerer const & src);
		~Sorcerer(void);

		Sorcerer &			operator=(Sorcerer const & rhs);

		std::string			getName(void) const;
		std::string			getTitle(void) const;
		void				polymorph(Victim const & target) const;
		
	private:
		Sorcerer(void);

		std::string			_name;
		std::string			_title;
};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:44:48 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 13:11:48 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	public:
		Peon(std::string const & name);
		Peon(Peon const & src);
		~Peon(void);

		Peon &			operator=(Peon const & rhs);

		void			getPolymorphed(void) const;
		
	private:
		Peon(void);
};

std::ostream &	operator<<(std::ostream & o, Peon const & rhs);

#endif
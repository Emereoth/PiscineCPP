/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:21 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 20:41:50 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACE_MARINE_HPP
# define ISPACE_MARINE_HPP

#include <iostream>

class ISpaceMarine
{
	public:
		virtual ~ISpaceMarine() {}
		virtual ISpaceMarine* clone(void) const = 0;
		virtual void battleCry(void) const = 0;
		virtual void rangedAttack(void) const = 0;
		virtual void meleeAttack(void) const = 0;
};

#endif
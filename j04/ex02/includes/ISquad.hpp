/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:34:27 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 21:39:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ~ISquad(void);
		
		virtual int				getCount(void) const = 0;
		virtual ISpaceMarine *	getUnit(int id) const = 0;
		virtual int				push(ISpaceMarine * recruit) = 0;
};

#endif
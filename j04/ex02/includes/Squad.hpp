/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:42:35 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 21:36:24 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
	public:
		Squad(void);
		Squad(Squad const & src);
		virtual ~Squad(void);

		Squad & 					operator=(Squad const & rhs);
		virtual int					getCount(void) const;
		virtual ISpaceMarine *		getUnit(int id) const;
		virtual int					push(ISpaceMarine * recruit);

	private:
		ISpaceMarine **		_squad;

		bool				checkPresence(ISpaceMarine * recruit) const;
};

#endif
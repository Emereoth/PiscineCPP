/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:50:59 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 21:53:00 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const & src);
		virtual ~TacticalMarine(void);

		TacticalMarine & 			operator=(TacticalMarine const & src);
		virtual	TacticalMarine *			clone(void) const;
		virtual	void						battleCry(void) const;
		virtual	void						rangedAttack(void) const;
		virtual	void						meleeAttack(void) const;
};

#endif
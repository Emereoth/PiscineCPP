/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:27:27 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 18:56:55 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <iostream>
#include <string>

#define ENEMY_MAX 80
#define MISSILE_MAX 15

class AEntity 
{
	public:
		AEntity(int const x, int const y);
		virtual ~AEntity(void);
		AEntity & 		operator=(AEntity const & src);
		virtual int		getX(void) const = 0;
		virtual int		getY(void) const = 0;

	protected:
		AEntity(void);
		AEntity(AEntity const & src);
		
		int		_x;
		int		_y;
};

#endif
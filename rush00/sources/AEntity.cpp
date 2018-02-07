/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:26:33 by acottier          #+#    #+#             */
/*   Updated: 2018/01/13 18:57:52 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AEntity.hpp"

AEntity::AEntity(int const x, int const y) : _x(x), _y(y)
{
}

AEntity::~AEntity(void)
{
}

AEntity::AEntity(void)
{
}

AEntity::AEntity(AEntity const & src)
{
	*this = src;
}

AEntity &		AEntity::operator=(AEntity const & src)
{
	_x = src.getX();
	_y = src.getY();
	return (*this);
}
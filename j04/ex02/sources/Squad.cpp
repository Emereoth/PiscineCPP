/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:39:35 by acottier          #+#    #+#             */
/*   Updated: 2018/01/12 21:43:08 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Squad.hpp"

Squad::Squad(void)
{
	_squad = new ISpaceMarine*[1000];
	std::cout << "Assembling a new squad!" << std::endl;
}

Squad::Squad(Squad const & src)
{
	ISpaceMarine *	inTp;
	int				i = -1;

	while ((inTp = src.getUnit(++i)))
		this->push(inTp->clone());
	std::cout << "Squad teleported and ready for combat!" << std::endl;
}

Squad::~Squad(void)
{
	delete [] _squad;
	std::cout << "Squad broken!" << std::endl;
}

Squad &				Squad::operator=(Squad const & src)
{
	ISpaceMarine *	inTp;
	ISpaceMarine *	geneSeed;
	int				i = -1;

	while ((inTp = src.getUnit(++i)))
	{
		geneSeed = (inTp->clone());
		delete inTp;
		this->push(geneSeed);
	}
	std::cout << "Squad reassigned and ready for combat!" << std::endl;
	return (*this);
}

int					Squad::getCount(void) const
{
	int		i = 0;

	while (this->getUnit(i))
		i++;
	return (i);
}

ISpaceMarine *		Squad::getUnit(int id) const
{
	if (id < 0 || id > 999)
		return (NULL);
	return (_squad[id]);
}

int					Squad::push(ISpaceMarine * recruit)
{
	int		total = this->getCount();

	if (!recruit || !checkPresence(recruit))
		return (total);
	if (total == 1000)
	{
		std::cout << "Squad full!" << std::endl;
		return (total);
	}
	*_squad[total] = *recruit;
	return (total + 1);
}

bool				Squad::checkPresence(ISpaceMarine * recruit) const
{
	int			i = -1;

	while (_squad[++i])
	{
		if (&_squad[i] == &recruit)
			return (false);
	}
	return (true);
}
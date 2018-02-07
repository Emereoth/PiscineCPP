/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Windows.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:01:01 by fdavid            #+#    #+#             */
/*   Updated: 2018/01/14 18:12:46 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOWS_H
# define WINDOWS_H
# define ARROW_UP 140
# define ARROW_DOWN 141
# define ARROW_RIGHT 142
# define ARROW_LEFT 143
# define NO_INPUT 4294967295
# include <ncurses.h>
# include "Player.hpp"
# include "Arena.hpp"
#include "Time.hpp"

class Arena;
class Player;
class Time;

class Windows
{
	public:
		Windows(void);
		~Windows(void);
		Windows			&operator=(Windows const &src);
		Windows(Windows const &src);

	void				printEntities(void);
		
		WINDOW *		win;
		unsigned int	getChar(void);
		void			run(void);

	private:
		unsigned int	_lastch;
		unsigned int	_arrow;
		Player			*_player;
		Arena			*_arena;
		bool			_exit;
		int				_fire;
		void			_endGG(void);
};

#endif

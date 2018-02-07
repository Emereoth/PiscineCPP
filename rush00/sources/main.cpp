/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:01:04 by acottier          #+#    #+#             */
/*   Updated: 2018/01/14 22:14:30 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Windows.hpp"
#include <ncurses.h>
#include <fstream>
#include <iostream>

int		main(void)
{
	int			maxHeight;
	int			maxWidth;
	WINDOW *	WIN;

	initscr();
	timeout(0);
	curs_set(0);

	Windows 	win;
	
	getmaxyx(stdscr, maxHeight, maxWidth);
	WIN = newwin(maxHeight - 5, maxWidth - 5, 1, 1);
	nodelay(WIN, true);
	cbreak();
	noecho();

	win.run();
	
	return (0);
}
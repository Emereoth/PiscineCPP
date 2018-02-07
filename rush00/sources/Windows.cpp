/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Windows.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:05:02 by fdavid            #+#    #+#             */
/*   Updated: 2018/01/14 22:21:16 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Windows.hpp"
#include "../includes/Time.hpp"
#include <string>

Windows::Windows(void) : _arena((new Arena)), _exit(false)
{
	this->_lastch = 0;
	this->_arrow = 0;
	this->_player = new Player(COLS / 2 - 1, LINES - 2, this->_arena);
}

Windows::~Windows(void)
{
	endwin();
}

Windows						&Windows::operator=(Windows const &src)
{
	(void)src;
	return (*this);
}

Windows::Windows(Windows const &src) : _arena((new Arena))
{
	*this = src;
}

unsigned int				Windows::getChar(void)
{
	unsigned int			ch;

	ch = getch();
	if (ch == 27)
	{
		this->_arrow = 1;
		return (this->getChar());
	}
	else if (this->_arrow == 1 && ch == 91)
	{
		this->_arrow = 2;
		return (this->getChar());
	}
	else if (this->_arrow == 2 && (ch >= 65 && ch <= 68))
	{
		this->_arrow = 0;
		return (ch + 75);
	}
	else if (ch == 113)
		return (0);
	return (ch);
}

void						Windows::printEntities(void)
{
	int			playerX = this->_player->getX();
	int			playerY = this->_player->getY();
	int			missileX;
	int			missileY;
	int			enemyX;
	int			enemyY;
	Projectile	*missile;
	Enemy		*enemy;

	clear();
	
	if (this->_player->isAlive())
	{
		mvprintw(playerY, playerX, PLAYER_MODEL1);
		mvprintw(playerY + 1, playerX, PLAYER_MODEL2);
	}
	if (_fire > 0)
	{
		mvprintw(playerY - 1, playerX + 1, "*");
		_fire--;
	}
	for (int i = 0 ; i < MISSILE_MAX ; i++)
	{
		if ((missile = _arena->getMissile(i)) && missile->getState())
		{
			missileX = missile->getX();
			missileY = missile->getY();
			mvprintw(missileY, missileX, "|");
		}
	}
	
	for (int j = 0; j < (int)_arena->_totalUsedEnemies ; j++)
	{
		if ((enemy = _arena->getEnemy(j)) && enemy->getState())
		{			
			enemyX = enemy->getX();
			enemyY = enemy->getY();
			mvprintw(enemyY, enemyX, ENEMY_MODEL1);
			mvprintw(enemyY + 1, enemyX, ENEMY_MODEL2);
		}
	}
	refresh();
}

void						Windows::_endGG(void)
{
	std::string				endMsg = "YOU WIN THE GAME !";
	clear();
	timeout(-1);
	mvprintw(LINES / 2, COLS / 2 - endMsg.size() / 2, endMsg.c_str());
	refresh();
	getch();
}

void						Windows::run(void)
{
	unsigned int			ch;
	int						cols;
	printEntities();
	while (!_exit)
	{
		Time::calculDeltaTime();
		cols = _arena->getWaveManager()->_calcMaxEnemieByLine() * 3;
		if ((ch = this->getChar()) != 0)
		{
			if (ch == ARROW_RIGHT)
				this->_player->move(1, 0, cols);
			else if (ch == ARROW_LEFT)
				this->_player->move(-1, 0, cols);
			else if (ch == ARROW_UP)
				this->_player->move(0, -1, cols);
			else if (ch == ARROW_DOWN)
				this->_player->move(0, 1, cols);
			else if (ch == 32)
				_fire = this->_player->fire();
		}
		if (_arena->checkShipCollision(_player->getX(), _player->getY()))
			return ;
			if (_arena->getWaveManager()->getWave() == 3)
			{
				_endGG();
				return ;
			}
		_arena->moveAll();			
		printEntities();
		Time::sleepAsMuchAsNeeded();
	}
}
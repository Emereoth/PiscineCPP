/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaveManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:40:30 by hbock             #+#    #+#             */
/*   Updated: 2018/01/23 13:53:20 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAVE_MANAGER_H_
# define WAVE_MANAGER_H_

# define MIN_SPACE_X        2
# define MIN_SPACE_Y        1
# define MARGIN_X           140
# define MARGIN_Y           1
# define ENEMY_WIDTH        3
# define ENEMY_HEIGHT       2
# define ENEMY_START_HP     1
# define PLAYER_ZONE_HEIGHT 18
# include "Arena.hpp"
# include "Windows.hpp"
# include "Enemy.hpp"
# include <ncurses.h>
# include "random.hpp"

class Enemy;

class WaveManager {

	public:

		WaveManager( Arena * src );
		~WaveManager( void );

        unsigned int    _calcMaxEnemieByLine( void ) const;
        void            spawnNextWave( void );
        int getWave( void );


        private:

                WaveManager( void );
                WaveManager( WaveManager const & src );
                WaveManager & operator=( WaveManager const & rhs );

        void            _instantiateEnemyAndSetPosition( void );
        unsigned int    _calcMaxEnemieByCol( void ) const;

        Enemy *const*   _fleet;
        Arena *         _arena;
        unsigned int    _nbEnemies;
        unsigned int    _enemyByLine;
        unsigned int    _enemyByCol;
        int             _spawnPercent;
        int             _wave;
};


#endif

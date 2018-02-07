/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaveManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <acottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:40:37 by hbock             #+#    #+#             */
/*   Updated: 2018/01/14 16:44:48 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WaveManager.hpp"


WaveManager::WaveManager( Arena * src ) : _arena(src), _wave(1) {

    _instantiateEnemyAndSetPosition();
    return ;
}

WaveManager::~WaveManager( void ) {

    return ;
}

unsigned int    WaveManager::_calcMaxEnemieByLine( void ) const {

    // ( nb char by line + 1 - 2 x margin ) / (enemie width + MIN_SPACE_X)
    return (COLS + MIN_SPACE_X - 2 * MARGIN_X) / (3 + MIN_SPACE_X);
    // return (COLS - 2 * MARGIN) / 2;
}

unsigned int    WaveManager::_calcMaxEnemieByCol( void ) const {

    // ( nb char by col + 1 - 2 x margin - playerZoneHeight ) / (enemie height + MIN_SPACE_Y)
    return (LINES + MIN_SPACE_Y - 2 * MARGIN_Y - PLAYER_ZONE_HEIGHT) / (2 + MIN_SPACE_Y);
}

int             WaveManager::getWave( void )
{

    return _wave;
}
void            WaveManager::spawnNextWave( void ) {

    _wave++;
    _arena->spawned = 0;
    _spawnPercent += 5;
    int totEn = _arena->_totalUsedEnemies;
    if (_spawnPercent >= 80)
        _spawnPercent = 80;
    for (int i = 0; i < totEn; i++) {

        _fleet[i]->resetPos();
        _fleet[i]->respawn();
        if (Random::getRand() % 100 <= _spawnPercent)
        {
            _arena->spawned++;
            _fleet[i]->setIsAliveAtStart(true);
        }
        else
            _fleet[i]->setIsAliveAtStart(false);
        _fleet[i]->resetAlive();
        // _fleet[i]->buff();
    }

}

void            WaveManager::_instantiateEnemyAndSetPosition( void ) {
    int min;
    
    _arena->spawned = 0;
    _enemyByLine = _calcMaxEnemieByLine();
    _enemyByCol = _calcMaxEnemieByCol();
    _nbEnemies = (_nbEnemies = _enemyByLine * _enemyByCol) > ENEMY_MAX ? ENEMY_MAX : _nbEnemies;
    _spawnPercent = 25;

    int line = 0;
    min = _nbEnemies < ENEMY_MAX ? _nbEnemies : ENEMY_MAX;
    _arena->_totalUsedEnemies = min;
    for (int i = 0; i < (int)min; i++) {

        if (i % _enemyByLine == 0)
            line++;
            
        int x = ((i % _enemyByLine) * (ENEMY_WIDTH + MIN_SPACE_X) + MARGIN_X);
        int y = (line * (ENEMY_HEIGHT + MIN_SPACE_Y) + MARGIN_Y);
        Enemy * newEnemy = new Enemy(x, y, ENEMY_START_HP, _arena);
        if (Random::getRand() % 4 == 0)
        {
            _arena->spawned++;
            newEnemy->setIsAliveAtStart(true);
        }
        else
            newEnemy->setIsAliveAtStart(false);
        newEnemy->resetAlive();
        _arena->addEntity(newEnemy);

    }
    for (int i = min; i < ENEMY_MAX; i++)
    {
        Enemy * newEnemy = new Enemy(-10, -10, ENEMY_START_HP, _arena);
        newEnemy->setIsAliveAtStart(false);
        newEnemy->resetAlive();
        _arena->addEntity(newEnemy);
    }
    _fleet = _arena->getEnemyFleet();
}
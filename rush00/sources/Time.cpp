// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Time.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/01/13 15:36:38 by hbock             #+#    #+#             //
//   Updated: 2018/01/13 16:48:05 by hbock            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../includes/Time.hpp"

float		Time::_lastClock = clock();
float		Time::_deltaTime;

// Calcul the time (in second) since the last call to this function
// We must call this before using deltaTime( void ), once by frame (call it at the begining of the game loop)
void		Time::calculDeltaTime( void ) {

	float cl = clock();

	_deltaTime = (float)(cl - _lastClock) / CLOCKS_PER_SEC;
	_lastClock = cl;
}

// Return _deltaTime
float		Time::deltaTime( void ) {

	return _deltaTime;
}

// Return time since last update
float		Time::timeSinceLastUpdate( void ) {

	float cl = clock();

	return (float)(cl - _lastClock) / CLOCKS_PER_SEC;
}

void		Time::sleepAsMuchAsNeeded( void ) {

	float last = timeSinceLastUpdate();

	if (last < MIN_FRAME_LEN)
		usleep((unsigned int)((MIN_FRAME_LEN - last) * 1000));

}
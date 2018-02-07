// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Time.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/01/13 15:35:48 by hbock             #+#    #+#             //
//   Updated: 2018/01/13 16:47:45 by hbock            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIME_H_
# define TIME_H_

# define MIN_FRAME_LEN 0.04

# include <time.h>
# include <unistd.h>

class Time {

public:

	static void		calculDeltaTime( void );
	static float	deltaTime( void );
	static float	timeSinceLastUpdate( void );
	static void		sleepAsMuchAsNeeded( void );

private:

	Time( void );
	Time( Time const & src );
	~Time( void );
	Time &			operator=( Time const & rhs ); 

	static float	_lastClock;
	static float	_deltaTime;

};

#endif

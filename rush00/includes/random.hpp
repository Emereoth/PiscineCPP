// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   random.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/01/14 22:07:15 by hbock             #+#    #+#             //
//   Updated: 2018/01/14 22:07:16 by hbock            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RANDOM_H_
# define RANDOM_H_

# include <string>
# include <cstdlib>

class Random {

public:

    static int      getRand( void );

private:

	Random( void );
	Random( Random const & src );
	~Random( void );
	Random &		operator=( Random const & rhs );

	static int		initSeed( void );

    static int      _seed;

};

#endif

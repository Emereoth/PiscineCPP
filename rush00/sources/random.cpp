// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   random.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/01/14 22:07:10 by hbock             #+#    #+#             //
//   Updated: 2018/01/14 22:07:11 by hbock            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../includes/random.hpp"

int Random::_seed = Random::initSeed();

int        Random::initSeed( void ) {

    // initialize seed
        _seed = time(nullptr);
        _seed %= 100;
        _seed += _seed % 10 + _seed;
        _seed *= _seed;
        _seed *= _seed;
        _seed *= _seed;
        srand(_seed);
        return _seed;

}

int        Random::getRand( void ) {

    return std::rand();
}
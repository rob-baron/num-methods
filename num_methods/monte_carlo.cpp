//
//  monte_carlo.cpp
//  monte_carlo
//
//  Created by Robert Baron on 8/22/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <random>

#include "monte_carlo.hpp"

void monte_carlo(int iterations,
                 void (*initilize)(void *, void *),
                 bool (*take_turn)(double , void *),
                 void (*process)(void *),
                 void *init_struct,
                 void *data_struct)
    {
    std::random_device rd;
    std::uniform_real_distribution<> dist(0,1);

    for(int x=0; x<iterations; x++)
        {
        initilize(init_struct,data_struct);
        while(take_turn(dist(rd), data_struct));
        process(data_struct);
        }
    }

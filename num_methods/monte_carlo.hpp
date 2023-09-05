//
//  monte_carlo.hpp
//  monte_carlo
//
//  Created by Robert Baron on 8/22/23.
//

#ifndef num_methods_hpp
#define num_methods_hpp

void monte_carlo(int iterations,
                 void (*initilize)(void *, void *),
                 bool (*take_turn)(double , void *),
                 void (*process)(void *),
                 void *init_struct,
                 void *data_struct);

#endif /* num_methods_hpp */

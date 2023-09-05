#include <cstddef>
#include "monte_carlo.hpp"

typedef struct{
    //2r is the h and w of the square
    double r;
    double pos[2];
    int index;
    int inside_circle;
    int inside_square;
} pi_struct;

void pi_initilize(void *i, void *d){
    pi_struct *pi_data=(pi_struct *)d;
    pi_data->index=0;
}

bool pi_take_turn(double rnd_num, void *d){
    pi_struct *pi_data=(pi_struct *)d;
    pi_data->pos[pi_data->index]=rnd_num*2*pi_data->r;
    pi_data->index++;
    if(pi_data->index<2) return true;
    return false;
}

void pi_process(void *d){
    pi_struct *pi_data=(pi_struct *)d;

    //since it is always inside the square
    pi_data->inside_square++;
    if( pi_data->pos[0]*pi_data->pos[0] + pi_data->pos[1]*pi_data->pos[1] < pi_data->r*pi_data->r)
        pi_data->inside_circle++;
}

double test_monte_carlo_pi(int num_iterations) {
    pi_struct pi_data;
    pi_data.index=0;
    pi_data.inside_circle=0;
    pi_data.inside_square=0;
    pi_data.r=1.0;
    monte_carlo(num_iterations,pi_initilize,pi_take_turn,pi_process, NULL, &pi_data);
    // area of circle = pi*r^2
    // area of square = (2r)^2
    //
    // circle points    pi *r^2
    // ------------- =  --------
    // square points      4 r^2
    //
    // 4* circle_point
    // --------------- = pi
    // square points
    //
    // put them into in quadrant I
    double mc_pi=-1.0;
    if(pi_data.inside_circle > 0)
        mc_pi=16.0*(double)pi_data.inside_circle/pi_data.inside_square;
    return mc_pi;
}

#include "gtest/gtest.h"
namespace {
    TEST(test_monte_carlo_pi, Zero){
        EXPECT_EQ(-1.0, test_monte_carlo_pi(0));
    }
    TEST(test_monte_carlo_pi, Ten){
        EXPECT_LE(0.0, test_monte_carlo_pi(10));
    }
    TEST(test_monte_carlo_pi, E4_NEAR){
        EXPECT_NEAR(test_monte_carlo_pi(10000), 3.14, 0.25);
    }
}
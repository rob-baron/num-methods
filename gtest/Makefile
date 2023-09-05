cc = g++ -std=c++14 -I/app/src/h -Wall -g -pthread
libs = -lgtest_main  -lgtest /app/lib/num_methods.a

test_pi: test_pi.cpp
	$(cc) test_pi.cpp $(libs) -o test_pi

all: test_pi

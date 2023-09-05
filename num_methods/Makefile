# Just a simple Makefile to build the library
# expected to be run in a docker container
cc := gcc -std=c++14 -I/app/src/h

monte_carlo.o: monte_carlo.cpp
	$(cc) -c monte_carlo.cpp

num_methods.a: monte_carlo.o
	ar rvs num_methods.a monte_carlo.o

all: num_methods.a

clean:
	rm num_methods.a
	rm monte_carlo.0

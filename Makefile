CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic -O1

markov.o: markov.h markov.cpp
	g++ $(CXXFLAGS) -c markov.cpp -o markov.o

CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic -O1

markov.o: markov.h markov.cpp
	g++ $(CXXFLAGS) -c markov.cpp -o markov.o

Flur.o: Flur.h Flur.cpp
	g++ $(CXXFLAGS) -c Flur.cpp -o Flur.o

upGit:
	git add $^
	git commit -m "Update"
	git push

downGit:
	git pull
	

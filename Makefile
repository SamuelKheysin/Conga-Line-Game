all: conga

conga: conga.o zombie.o conga.h main.cpp
	g++ -Wall -o conga conga.o zombie.o main.cpp

conga.o: conga.h conga.cpp linkedlist.h node.h zombie.h   
	g++ -Wall -c conga.cpp

zombie.o: zombie.h zombie.cpp
	g++ -Wall -c zombie.cpp
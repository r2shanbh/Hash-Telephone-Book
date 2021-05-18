all: openhtdriver orderedhtdriver

openhtdriver: openhttest.cpp hashA.cpp
	g++ -std=c++11 -o openhtdriver openhttest.cpp hashA.cpp

orderedhtdriver: orderedhttest.cpp hashB.cpp
	g++ -std=c++11 -o orderedhtdriver orderedhttest.cpp hashB.cpp

clean:
	rm openhtdriver
	rm orderedhtdriver
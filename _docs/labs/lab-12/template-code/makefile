test: test.o
	./test.o
	#debug50 test.o
	rm test.o

test.o: test.cpp graph.cpp
	g++ -std=c++11 test.cpp graph.cpp -o test.o #-ggdb


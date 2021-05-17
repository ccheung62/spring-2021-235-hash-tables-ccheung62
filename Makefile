OBJECTS=main.o List.o Node.o HTable.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o HTable.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o HTable.o List.o Node.o
	g++ -o tests tests.o HTable.o List.o Node.o

tests.o: tests.cpp doctest.h
	g++ -c -std=c++11 tests.cpp

main.o: main.cpp HTable.h List.h Node.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS) main tests tests.o

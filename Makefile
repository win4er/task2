all: main.o task2.o task1.o
	g++ main.o task2.o task1.o

main.o: main.cpp
	g++ -c main.cpp

task1.o: task1.cpp
	g++ -c task1.cpp

task2.o: task2.cpp
	g++ -c task2.cpp

clean:
	rm *.out *.exe *.o

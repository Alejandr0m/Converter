output: main.o convert.o
	g++ main.o convert.o -o main
	rm *.o

main.o: ../main.cpp
	g++ -c ../main.cpp

convert.o: ../includes/convert.cpp ../includes/convert.h
	g++ -c ../includes/convert.cpp
test_DVD.o:  test_DVD.cpp
	g++ -Wall -c test_DVD.cpp

DVDDriver:  DVD.o test_DVD.o
	g++ -Wall DVD.o test_DVD.o -o DVDDriver

DVD.o:  DVD.cpp DVD.h
	g++ -Wall -c DVD.cpp
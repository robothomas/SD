DVDDriver.o:  DVDArrayPDriver.cpp DVDArrayP.cpp DVDArrayP.h
	g++ -Wall -c DVDArrayPDriver.cpp -o DVDDriver.o

DVDDriver:  DVD.o DVDDriver.o
	g++ -Wall DVD.o DVDDriver.o -o DVDDriver

DVD.o:  DVD.cpp DVD.h
	g++ -Wall -c DVD.cpp
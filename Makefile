CXX = g++
CPPFLAGS = -static -Wall

all: helloworld heartseeker

helloworld: helloworld.cpp

heartseeker: heartseeker.cpp

clean:
	rm -f *.exe helloworld heartseeker


.PHONY: all clean

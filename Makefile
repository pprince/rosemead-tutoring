CXX = g++
CPPFLAGS = -static -Wall

all: helloworld typewriter typewriter2 heartseeker

helloworld: helloworld.cpp

typewriter: typewriter.cpp

typewriter2: typewriter2.cpp

heartseeker: heartseeker.cpp

clean:
	rm -f *.exe helloworld heartseeker


.PHONY: all clean

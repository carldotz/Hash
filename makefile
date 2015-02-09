
CC = g++

CXXFLAGS = -g 
LDFLAGS = -g

HashTab:main.o HashTab.o
main.o:HashTab.h
HashTab.o:HashTab.h

.PHONY:clean
clean:
	rm *.o
	rm HashTab

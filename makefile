
CC = g++

CXXFLAGS = -g 
LDFLAGS = -g

HashTab:main.o HashTab.o

.PHONY:clean
clean:
	rm *.o
	rm HashTab

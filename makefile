
CC = g++

CXXFLAGS = -g 
LDFLAGS = -g

HashTab:main.cc HashTab.h
	$(CC) $(CXXFLAGS) -o HashTab main.cc

.PHONY:clean
clean:
	@rm -f *.o
	@rm -f HashTab
	@rm -rf HashTab.dSYM

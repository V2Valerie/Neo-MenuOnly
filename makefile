CXX=g++
CXXFLAGS=-Wall -Werror -lncurses

all: neomenu

neomenu: neomenu.cpp
	$(CXX) $(CXXFLAGS) neomenu.cpp -o neomenu
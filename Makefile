#Makefile
CXXFLAGS = -std=c++11 -g -O0

all: examheap

examheap: examheap.cpp heap.cpp
	g++ $(CXXFLAGS) examheap.cpp heap.cpp -o examheap

clean:
	rm examheap

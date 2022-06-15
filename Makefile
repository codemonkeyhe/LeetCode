src_cpp := $(wildcard *.cpp)  
src_exe := $(src_cpp:.cpp=.bin)

.PHONY: all test clean

%.bin: %.cpp
	g++ -g -std=c++0x  -Wall -o $@ $<

all: test

test: $(src_exe)
	@echo "make OK"

clean:
	rm -rf *.bin
	rm -rf *.bin.dSYM

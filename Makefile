all: chap01
chap01: src/chap01.cpp
	g++ src\\* -Iinclude -obin/chap-01 -std=c++11 -Wall -O3


clean:
	rm *.exe main
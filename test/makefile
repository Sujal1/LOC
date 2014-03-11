all: generate

generate: test.o
	g++ ../lib/test.o ../lib/LOC_test.o -o test_file

test.o: 
	g++ -c main_test.cpp -I ../src/ -o ../lib/test.o

install:
	mv test_file ../bin/


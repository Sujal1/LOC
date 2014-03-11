all: generate

generate: LOC_test.o main.o
	g++ ../lib/LOC_test.o ../lib/main.o -o exe_file

LOC_test.o: 
	g++ -c LOC_test.cpp -o ../lib/LOC_test.o

main.o:	
	g++ -c main.cpp -o ../lib/main.o

install: 
	mv exe_file ../bin/

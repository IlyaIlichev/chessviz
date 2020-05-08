.PHONY: all clean run test

GTESTDIR = thirdparty/googletest

all: build/main.o build/functions.o
	g++ -Wall build/main.o build/functions.o -o bin/main

build/main.o:
	g++ -c -Wall src/main.cpp -o $@

build/functions.o:
	g++ -c -Wall src/functions.cpp -o  $@

test: gtestlib bin/test
	bin/test

gtestlib:
	g++ -std=c++11 -isystem ${GTESTDIR}/include -I ${GTESTDIR} -pthread -c ${GTESTDIR}/src/gtest-all.cc -o build/gtest-all.o
	ar -rv build/libgtest.a build/gtest-all.o

bin/test: build/test.o build/functions.o
	g++ -std=c++11 -isystem ${GTESTDIR}/include -pthread $^ build/libgtest.a -o $@

build/test.o:
	g++ -std=c++11 -c -Wall test/test.cpp -I $(GTESTDIR)/include -o $@

clean:
	rm build/*.o

run:
	bin/main

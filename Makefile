

all:
	g++ -c -Wall src/main.cpp -o build/main.o
	g++ -c -Wall src/functions.cpp -o build/functions.o
	g++ -Wall build/main.o build/functions.o -o bin/main

clean:
	rm build/*.o

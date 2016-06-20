primenum: primenum.o
	g++ -o primenum primenum.o

primenum.o: primenum.cpp
	g++ -c primenum.cpp

clean:
	rm -f primenum *.o

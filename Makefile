CC = gcc

LIBS = -lstdc++

%:
	$(CC) -g -O0 -std=c++11 -fopenmp -o $*.out $*.cpp $(LIBS)
clean:
	rm -f *.out

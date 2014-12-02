CC = gcc

LIBS = -lstdc++

%:
	$(CC) -g -O0 -fopenmp -o $*.out $*.cpp $(LIBS)
clean:
	rm -f *.out

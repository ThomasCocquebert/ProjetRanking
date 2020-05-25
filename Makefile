# Compile
CC=gcc

# Linker
LINK=gcc

# Build vector.o
vector.o:	src/vector.c
	$(CC) -Wall -g -c src/vector.c -lm

# Build structure.o
structure.o:	src/structure.c
	$(CC) -Wall -g -c src/structure.c

# Build lecture.o
Lecture.o:	src/Lecture.c lib/structure.h
	$(CC) -Wall -g -c src/Lecture.c

# Build testVector.o
testVector.o:	src/testVector.c lib/vector.h
	$(CC) -Wall -g -c src/testVector.c -lm

# Build testVector executable
testVector:	testVector.o vector.o
	$(CC) -Wall -g -o testVector vector.o testVector.o -lm

# Run testVector executable
runTestVector: testVector
	./testVector

# Run testVEctor with valgrind
runTestVectorMemory: testVector
	valgrind ./testVector

# Clean .o files and executable
clean :
	rm *.o testVector
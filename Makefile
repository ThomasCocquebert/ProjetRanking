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

# Build calcul.o
calcul.o:	src/calcul.c lib/vector.h lib/structure.h lib/lecture.h
	$(CC) -Wall -g -c src/calcul.c -lm

# Build alteration.o
alteration.o:	src/alteration.c lib/structure.h
	$(CC) -Wall -g -c src/alteration.c

# Build testAlteration.o
testAlteration.o: src/testAlteration.c lib/alteration.h lib/structure.h
	$(CC) -Wall -g -c src/testAlteration.c

# Build testAlteration executable
testAlteration:	testAlteration.o alteration.o structure.o Lecture.o
	$(CC) -Wall -g -o testAlteration testAlteration.o alteration.o structure.o Lecture.o

# Build testVector executable
testVector:	testVector.o vector.o
	$(CC) -Wall -g -o testVector vector.o testVector.o -lm

# Build calcul executable
calcul:	calcul.o vector.o structure.o Lecture.o
	$(CC) -Wall -g -o calcul vector.o calcul.o Lecture.o structure.o -lm

# Run testVector executable
runTestVector: testVector
	./testVector

# Run testVEctor with valgrind
runTestVectorValgrind: testVector
	valgrind ./testVector

# Clean .o files and executable
clean :
	rm *.o testVector testAlteration calcul

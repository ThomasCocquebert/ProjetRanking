#############################################
# Parameters
# Compile
CC=gcc

# Linker
LINK=gcc

# Default goal
.DEFAULT_GOAL := all

#############################################
# Build of .o files

# Build vector.o
vector.o:	src/vector.c lib/structure.h
	$(CC) -Wall -g -c src/vector.c -lm

# Build structure.o
structure.o:	src/structure.c
	$(CC) -Wall -g -c src/structure.c

# Build lecture.o
lecture.o:	src/lecture.c lib/structure.h
	$(CC) -Wall -g -c src/lecture.c

# Build alteration.o
alteration.o:	src/alteration.c lib/structure.h
	$(CC) -Wall -g -c src/alteration.c

# Build calcul.o
calcul.o:	src/calcul.c lib/vector.h lib/structure.h lib/lecture.h
	$(CC) -Wall -g -c src/calcul.c -lm


#############################################
# Build Test .o files

# Build testVector.o
testVector.o:	test/testVector.c lib/vector.h lib/structure.h
	$(CC) -Wall -g -c test/testVector.c -lm

# Build testAlteration.o
testAlteration.o: test/testAlteration.c lib/alteration.h lib/structure.h
	$(CC) -Wall -g -c test/testAlteration.c

# Build testCalcul.o
testCalcul.o:	test/testCalcul.c lib/vector.h lib/structure.h lib/lecture.h lib/calcul.h
	$(CC) -Wall -g -c test/testCalcul.c -lm

#############################################
# Build Test executables

# Build testVector executable
testVector:	testVector.o vector.o structure.o
	$(CC) -Wall -g -o testVector vector.o testVector.o structure.o -lm

# Build testAlteration executable
testAlteration:	testAlteration.o alteration.o structure.o lecture.o
	$(CC) -Wall -g -o testAlteration testAlteration.o alteration.o structure.o lecture.o

# Build testCalcul executable
testCalcul:	testCalcul.o vector.o structure.o lecture.o calcul.o
	$(CC) -Wall -g -o testCalcul testCalcul.o vector.o structure.o lecture.o calcul.o -lm

allTest:	testVector testAlteration testCalcul
	$(CC) -Wall -g -o testVector vector.o testVector.o structure.o -lm
	$(CC) -Wall -g -o testAlteration testAlteration.o alteration.o structure.o lecture.o
	$(CC) -Wall -g -o testCalcul testCalcul.o vector.o structure.o lecture.o calcul.o -lm

#############################################
# Build main.o file
main.o:	src/main.c lib/*.h
	$(CC) -Wall -g -c src/main.c -lm

#############################################
# Build main executable
main:	main.o vector.o structure.o lecture.o alteration.o calcul.o
	$(CC) -Wall -g -o main main.o vector.o structure.o lecture.o alteration.o calcul.o -lm

#############################################
# Run executable

# Run main
runMain:	main
	./main Graphe/web1.txt

# Run testVector executable
runTestVector: testVector
	./testVector

# Run testVector executable
runTestAlteration: testAlteration
	./testAlteration

# Run testCalcul executable
runTestCalcul:	testCalcul
	./testCalcul

#############################################
# Run executables with Valgrind

# Run main executable with Valgrind
runMainVal:	main
	valgrind ./main Graphe/web1.txt

# Run testVector executable with Valgrind
runTestVectorVal: testVector
	valgrind ./testVector

# Run testVector executable with Valgrind
runTestAlterationVal: testAlteration
	valgrind ./testAlteration

# Run testCalcul executable with Valgrind
runTestCalculVal:	testCalcul
	valgrind ./testCalcul

#############################################
# Run executable with drmemory

# Run main executable with drMemory
runMainDr:	main
	drmemory.exe main.exe Graphe/web1.txt

# Run testVector executable with deMemory
runTestVectorDr: testVector
	drmemory.exe testVector.exe

# Run testVector executable with drMemory
runTestAlterationDr: testAlteration
	drmemory.exe testAlteration.exe

# Run testCalcul executable with drMemory
runTestCalculDr:	testCalcul
	drmemory.exe testCalcul.exe

#############################################
# Miscellous command

# Build all executable files
all:	main testVector testAlteration testCalcul
	$(CC) -Wall -g -o testVector vector.o testVector.o -lm
	$(CC) -Wall -g -o testAlteration testAlteration.o alteration.o structure.o lecture.o
	$(CC) -Wall -g -o testCalcul testCalcul.o vector.o structure.o lecture.o calcul.o -lm
	$(CC) -Wall -g -o main main.o vector.o structure.o lecture.o alteration.o calcul.o -lm

# Clean .o files and executable
clean :
	rm *.o testVector testAlteration testCalcul main


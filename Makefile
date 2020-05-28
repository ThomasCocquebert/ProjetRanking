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

# Build structure.o
structure.o:	src/structure.c
	$(CC) -Wall -g -c src/structure.c

# Build vector.o
vector.o:	src/vector.c lib/structure.h
	$(CC) -Wall -g -c src/vector.c -lm

# Build lecture.o
lecture.o:	src/lecture.c lib/structure.h
	$(CC) -Wall -g -c src/lecture.c

# Build alteration.o
alteration.o:	src/alteration.c lib/structure.h
	$(CC) -Wall -g -c src/alteration.c

# Build calcul.o
calcul.o:	src/calcul.c lib/structure.h lib/vector.h lib/lecture.h
	$(CC) -Wall -g -c src/calcul.c -lm


#############################################
# Build Test .o files

# Build testVector.o
testVector.o:	test/testVector.c lib/structure.h lib/vector.h
	$(CC) -Wall -g -c test/testVector.c -lm

# Build testAlteration.o
testAlteration.o: test/testAlteration.c lib/structure.h lib/alteration.h
	$(CC) -Wall -g -c test/testAlteration.c

# Build testCalcul.o
testCalcul.o:	test/testCalcul.c lib/structure.h lib/vector.h lib/lecture.h lib/calcul.h lib/alteration.h
	$(CC) -Wall -g -c test/testCalcul.c -lm

#############################################
# Build Test executables

# Build testVector executable
testVector:	testVector.o structure.o vector.o
	$(CC) -Wall -g -o testVector testVector.o structure.o vector.o -lm

# Build testAlteration executable
testAlteration:	testAlteration.o structure.o alteration.o lecture.o
	$(CC) -Wall -g -o testAlteration testAlteration.o structure.o alteration.o lecture.o

# Build testCalcul executable
testCalcul:	testCalcul.o structure.o vector.o lecture.o calcul.o alteration.o
	$(CC) -Wall -g -o testCalcul testCalcul.o structure.o vector.o lecture.o calcul.o alteration.o -lm

allTest:	testVector testAlteration testCalcul
	$(CC) -Wall -g -o testVector  testVector.o structure.o vector.o -lm
	$(CC) -Wall -g -o testAlteration testAlteration.o structure.o alteration.o lecture.o
	$(CC) -Wall -g -o testCalcul testCalcul.o structure.o vector.o lecture.o calcul.o alteration.o -lm

#############################################
# Build main.o file
main.o:	src/main.c lib/structure.h lib/vector.h lib/lecture.h lib/calcul.h lib/alteration.h
	$(CC) -Wall -g -c src/main.c -lm

#############################################
# Build main executable
main:	main.o structure.o vector.o lecture.o alteration.o calcul.o
	$(CC) -Wall -g -o main main.o structure.o vector.o lecture.o alteration.o calcul.o -lm

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
	$(CC) -Wall -g -o testVector  testVector.o structure.o vector.o -lm
	$(CC) -Wall -g -o testAlteration testAlteration.o structure.o alteration.o lecture.o
	$(CC) -Wall -g -o testCalcul testCalcul.o structure.o vector.o lecture.o calcul.o alteration.o -lm
	$(CC) -Wall -g -o main main.o structure.o vector.o lecture.o alteration.o calcul.o -lm

# Clean .o files and executable
clean:
	rm *.o testVector testAlteration testCalcul main

# Clean .o files and exe for Windowd
cleanW:	
	del *.o *.exe
#############################################
# Parameters
# Compile
CC=gcc

# Linker
LINK=gcc

#############################################
# Build of .o files

# Build vector.o
vector.o:	src/vector.c
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
testVector.o:	test/testVector.c lib/vector.h
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
testVector:	testVector.o vector.o
	$(CC) -Wall -g -o testVector vector.o testVector.o -lm

# Build testAlteration executable
testAlteration:	testAlteration.o alteration.o structure.o lecture.o
	$(CC) -Wall -g -o testAlteration testAlteration.o alteration.o structure.o lecture.o

# Build testCalcul executable
testCalcul:	testCalcul.o vector.o structure.o lecture.o calcul.o
	$(CC) -Wall -g -o testCalcul testCalcul.o vector.o structure.o lecture.o calcul.o -lm

allTest:	testVector testAlteration testCalcul
	$(CC) -Wall -g -o testVector vector.o testVector.o -lm
	$(CC) -Wall -g -o testAlteration testAlteration.o alteration.o structure.o lecture.o
	$(CC) -Wall -g -o testCalcul testCalcul.o vector.o structure.o lecture.o calcul.o -lm

#############################################
# Build main programm

#############################################
# Run executable

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

# Clean .o files and executable
clean :
	rm *.o testVector testAlteration testCalcul


vector.o:	src/vector.c
	gcc -Wall -g -c src/vector.c -lm

testVector.o:	src/testVector.c lib/vector.h
	gcc -Wall -g -c src/testVector.c -lm

testVector:	testVector.o vector.o
	gcc -Wall -g -o testVector vector.o testVector.o -lm

runTestVector: testVector
	./testVector

runTestVectorMemory: testVector
	valgrind ./testVector

clean :
	rm *.o
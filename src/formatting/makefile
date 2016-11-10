FILE = formatting.c

main:
	gcc -g -O -c $(FILE)

clean:
	rm -rf *.o test a.out

test: test.c $(FILE)
	gcc -std=c99 -g -DEBUG -o test test.c $(FILE) ../cunit/cunit.c -lm
	./test

testrun:
	./test

debug:
	gcc -std=c99 -g test.c $(FILE) ../cunit/cunit.c -lm
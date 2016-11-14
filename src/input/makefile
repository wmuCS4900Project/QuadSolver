FILE = input.c
CUNIT = ../../cunit/cunit.c
VALIDATE = ../validation/validation.c

main:
	gcc -g -O -c $(FILE)

clean:
	rm -rf *.o

test: test.c $(FILE)
	gcc -std=c99 -g -DEBUG -o test test.c $(FILE) $(CUNIT) $(VALIDATE) -lm

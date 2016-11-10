# makefile 
# John Kapenga, Sp 2008
# demonstration unit testing for a quadratic equation solver
# qsolve               - The interactive solver 
#   qsolve_sqrt.c      - wrapper mysqrt() for the math lib sqrt() function
#   qsolve_interface.c - The user interface to the function qsolve(), non GUI
#   qsolve_roots.h     - The prototypes for qsolve_roots 
#   qsolve_roots.c     - solver function qsolve_roots()
# t1                - unit tests for qsolve(), uses math library sqrt() 
# t2                - unit tests for qsolve(), uses mock_qsolve_sqrt
# t3                - unit tests for qsolve(), monkey tests
# t4                - unit tests for qsolve(), boundry tests
# t5                - unit tests for qsolve(), illconditionsd system tests
# t5                - unit tests for qsolve(), \IE non-numneric testsj
# 
# rstat                - target for getting the size (test and static) for qsolve
# rtest                - target for getting a time on 10000 calls to qsolve.
#
# Should add:
#            unit testing for for qsolve_interface(), 
#                 manual or automated using expect
#            function testing for the entire application, using expect.
#            test for run time space (memory leaks etc...)
#            logging off sucessfuly runs, space, and time
#            profiling using gprof
#            over all error report.

CFLAGS= -Wall -pedantic -std=c99
CC= gcc
LIBS= -lm
SRC = Makefile cunit.c cunit.h mock_qsolve_sqrt.c mock_qsolve_sqrt.h \
  qsolve_interface.c \
  qsolve_roots.c qsolve_roots.h \
  qsolve_sqrt.c qsolve_sqrt.h \
  t1.c t2.c

qsolve: qsolve_interface.o qsolve_roots.o qsolve_sqrt.o 
	${CC} -o qsolve qsolve_interface.o qsolve_roots.o qsolve_sqrt.o ${LIBS}

test: t1 t2
	t1
	t2

t1: t1.o qsolve_roots.o qsolve_sqrt.o cunit.o 
	${CC} -o t1 t1.o qsolve_roots.o qsolve_sqrt.o cunit.o ${LIBS}
# qsolve_roots.h 
t2: t2.o qsolve_roots.o mock_qsolve_sqrt.o cunit.o 
	${CC} -o t2 t2.o qsolve_roots.o mock_qsolve_sqrt.o cunit.o ${LIBS}

# Dependencies based on included header files. 
# These could all be automatically generated
# Note the make built in suffix rules provide a rule 
#     for .o files from .c files

mock_qsolve_sqrt.o: mock_qsolve_sqrt.h qsolve_sqrt.h 
cunit.o: cunit.h
t1.o: cunit.h qsolve_roots.h 
t2.o: cunit.h qsolve_roots.h mock_qsolve_sqrt.h

qsolve_sqrt.o: qsolve_sqrt.h
qsolve_roots.o: qsolve_roots.h qsolve_sqrt.h
qsolve_interface.o: qsolve_roots.h

# exanple of preprocessor macro useage
test_macros: test_macros.c

unit_tests.tar: ${SRC}
	tar cvf unit_tests.tar ${SRC}

clean:
	-rm -f ${EXES} core *.log *.o *.exe qsolve t1 *.tar

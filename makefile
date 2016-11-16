#root makefile

MAKE = make all
CLEAN = make clean
TEST = make test
SUBDIRS = src
INSDIR = install
INS = install/qsolver
OUTPUT = src/output/output.o
INPUT = src/input/input.o
FORMAT = src/formatting/formatting.o
QSOLV = src/qsolv/qsolv.o
QS = src/qs/qs.o
VALID = src/validation/validation.o
TESTDIR = tests
TESTFULL = make
RM = rm

#first command runs if make called alone


all:
	for dir in $(SUBDIRS); do \
		$(MAKE) all -C $$dir; \
	done

deploy: all
	gcc -std=c99 -g -o $(INS) $(QS) $(QSOLV) $(VALID) $(FORMAT) $(INPUT) $(OUTPUT) -lm


run: deploy
	$(INSDIR)/./qsolver

clean:
	rm -rf $(INS)
	for dir in $(SUBDIRS); do \
		$(CLEAN) -C $$dir; \
	done

test:
	for dir in $(SUBDIRS); do \
		$(TEST) -C $$dir; \
	done

testfull: deploy
	for dir in $(TESTDIR); do \
		$(TESTFULL) -C $$dir; \
	done

#root makefile

MAKE = make all
CLEAN = make clean
SUBDIRS = src
INSDIR = install
INS = install/qsolver
OUTPUT = src/output/output.o
INPUT = src/input/input.o
FORMAT = src/formatting/formatting.o
QSOLV = src/qsolv/qsolv.o
QS = src/qs/qs.o
VALID = src/validation/validation.o
RM = rm

#first command runs if make called alone

deploy: all
	gcc -g -o $(INS) $(QS) $(QSOLV) $(VALID) $(FORMAT) $(INPUT) $(OUTPUT)

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

run: deploy
	.$(INS)

clean:
	rm -rf $(INS)
	for dir in $(SUBDIRS); do \
		$(CLEAN) -C $$dir; \
	done
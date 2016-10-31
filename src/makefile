SUBDIRS = qsolv input output formatting validation qs
CLEAN = make clean
OUTPUT = output/output.o
INPUT = input/input.o
FORMAT = formatting/formatting.o
QSOLV = qsolv/qsolv.o
QS = qs/qs.o
VALID = validation/validation.o


main:
	gcc -g -o qsolver $(QS) $(QSOLV) $(VALID) $(FORMAT) $(INPUT) $(OUTPUT)

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(CLEAN) -C $$dir; \
	done
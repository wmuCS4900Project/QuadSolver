Description
---------------
Quadsolver is a command line program for solving quadratic equations in the form of ax^2 + bx + c = 0, where a, b, and c are unknown.


Installation
--------------
This is installed by make via the command line.


Commands
---------
make all: builds all object files required to install
make deploy: installs to the INSTALL folder
make clean: removes all unnecessary objects after installation
make test: runs unit tests
make testfull: runs production tests

Use
-----
The program takes no arguments from the command line directly. It will prompt the user for a single line containing three arguments separated by spaces, and return an error message if the input is in an incorrect format, or the answer(s) (if there are one or more).


FAQ
------
Who are you?
	Computer science students at Western Michigan University.
Why did you create this?
	For a class, obviously.
Why is the documentation so bad?
	Well that’s a bit rude. Have you seen our awesome FAQ?
What coding standard was used for this project?
	GNU's C stanard, found at https://www.gnu.org/prep/standards/html_node/index.html#SEC_Contents


Versions
--------
1.0
11-15-16
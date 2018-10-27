# Author: Alexander Johnson
# Date: October 26, 2018

COMPILER = gcc
FLAGS = -Wall -pedantic-errors -std=c99
EXECUTABLE = main
SOURCES = testme.c

all: $(SOURCES) $(HEADERS)
	$(COMPILER) $(SOURCES) -o $(EXECUTABLE) $(FLAGS)

clean:
	rm -f a.out *.o $(EXECUTABLE)
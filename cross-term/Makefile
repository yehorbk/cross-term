TITLE=crossterm
OUTDIR=build
INDIR=src

CC=g++
FLAGS=-Wall
SOURCES=main.cpp

OBJECTS=$(INDIR)/$(SOURCES:.cpp=.o)

all: clean compile remove-objects

compile: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTDIR)/$(TITLE);

remove-objects:
	rm src/*.o

clean:
	rm -r $(OUTDIR) ; mkdir build

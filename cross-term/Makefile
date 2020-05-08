TITLE=crossterm
OUTDIR=build
INDIR=src

CC=gcc
FLAGS=-Wall
SOURCES=main.c

OBJECTS=$(INDIR)/$(SOURCES:.cpp=.o)

all: $(INDIR)/$(SOURCES) $(TITLE)
	
$(TITLE): clean $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTDIR)/$@

clean:
	rm -r $(OUTDIR) ; mkdir build

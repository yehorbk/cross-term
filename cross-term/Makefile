CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c
OBJECTS=$(SOURCES:.cpp=.o)
TITLE=crossterm

all: $(SOURCES) $(TITLE)
	
$(TITLE): clean $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o ./build/$@

.cpp.o:
	$(CC) $(CFLAGS) $< -o ./build/$@

clean:
	rm -r ./build ; mkdir build

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Complex.cpp Matrix.cpp matrixDriver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=matrixTest

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
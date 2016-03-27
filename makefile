CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= BSTree.h BTNode.h BSTree.h DBInterface.cpp DBDemo.cpp MechPart.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core

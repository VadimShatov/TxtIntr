.PHONY all debug release clean

RELEASE_FLAGS = -02 -Wall -DNDEBUG
DEBUG_FLAGS = -g -O0 -Wall
RELEASE_EXEC = zadanie
DEBUG_EXEC = zadanie-dbg
SOURCE = zadanie.cpp

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): zadanie.cpp
	g++ $(DEBUG_FLAGS) zadanie.cpp -o $(DEBUG_EXEC)

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): zadanie.cpp
	g++ $(RELEASE_FLAGS) zadanie.cpp -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
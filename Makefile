CC = gcc
CPPFLAGS += -Isrc/c/
CFLAGS += -W -Wall -Werror -g -O2 -pipe
LDFLAGS += -lm -lgmp -g -O2

TARGETS = c-euler

SOURCES = $(wildcard src/c/*)
OBJECTS = $(shell echo $(wildcard src/c/*.c) | sed 's/\.c/\.o/g')
all: $(TARGETS)

c-euler: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

src/c/%.o: src/c/%.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<
clean:
	$(RM) $(TARGETS)
	$(RM) $(wildcard src/c/*.o)

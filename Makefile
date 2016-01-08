V = 0

REALCC = gcc

CC_1 = $(REALCC)
CC_0 = @echo "  CC    $@"; $(CC_1)
CC = $(CC_$(V))

LD_1 = $(REALCC)
LD_0 = @echo "  LD    $@"; $(LD_1)
LD = $(LD_$(V))

CPPFLAGS += -Isrc/c/
CFLAGS += -W -Wall -Werror -g -O2 -pipe
LDFLAGS += -lm -lgmp -g -O2

TARGETS = c-euler

SOURCES = $(wildcard src/c/*.c)
OBJECTS = $(shell echo $(wildcard src/c/*.c) | sed 's/\.c/\.o/g')

all: $(TARGETS)

c-euler: $(OBJECTS)
	$(LD) $(OBJECTS) -o $@ $(LDFLAGS)

src/c/%.o: src/c/%.c
	$(CC) -c $(CPPFLAGS) -o $@ $< $(CFLAGS)
clean:
	$(RM) $(TARGETS)
	$(RM) $(OBJECTS)

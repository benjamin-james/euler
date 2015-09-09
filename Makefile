CC = gcc
CFLAGS = -W -Wall -Werror
LDFLAGS = -lm

TARGETS = problem1 problem2 problem3

SOURCES = $(addprefix src/, $(addsuffix .c, $(TARGETS)))

all: $(TARGETS)

%: src/%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm $(TARGETS)

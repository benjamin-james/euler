CC = gcc
CFLAGS = -W -Wall -Werror -g -O2
LDFLAGS = -lm

TARGETS = problem1 problem2 problem3 problem4 problem5 problem6

SOURCES = $(addprefix src/, $(addsuffix .c, $(TARGETS)))

all: $(TARGETS)

%: src/%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm $(TARGETS)

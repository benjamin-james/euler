CC = gcc
CFLAGS = -W -Wall -Werror

TARGETS = problem1

SOURCES = $(addprefix src/, $(addsuffix .c, $(TARGETS)))

all: $(TARGETS)

%: src/%.c
	$(CC) $(CFLAGS) $< -o $@


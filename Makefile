CC = gcc
CFLAGS = -W -Wall -Werror

TARGETS = problem1 problem2

SOURCES = $(addprefix src/, $(addsuffix .c, $(TARGETS)))

all: $(TARGETS)

%: src/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(TARGETS)

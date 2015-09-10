CC = gcc
CFLAGS += -W -Wall -Werror -g -O2 -pipe
LDFLAGS += -lm -lgmp

TARGETS = problem1 problem2 problem3 problem4 problem5 problem6 problem7 problem8 problem9 problem10 \
	problem11 problem12 problem13 problem14

SOURCES = $(addprefix src/, $(addsuffix .c, $(TARGETS)))

all: $(TARGETS)

%: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ $(LDFLAGS)
clean:
	$(RM) $(TARGETS)

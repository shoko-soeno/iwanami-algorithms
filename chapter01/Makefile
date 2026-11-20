CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

all: gcd

gcd: gcd.c
	$(CC) $(CFLAGS) -o $@ $<

run: gcd
	./gcd

clean:
	rm -f gcd

.PHONY: all run clean

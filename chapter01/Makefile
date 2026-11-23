CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

all: gcd invariant

gcd: gcd.c
	$(CC) $(CFLAGS) -o $@ $<

invariant: invariant.c
	$(CC) $(CFLAGS) -o $@ $<

run: gcd
	./gcd

check: invariant
	./invariant

clean:
	rm -f gcd invariant

.PHONY: all run check clean

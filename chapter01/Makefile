CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99

all: gcd invariant factorial

gcd: gcd.c
	$(CC) $(CFLAGS) -o $@ $<

invariant: invariant.c
	$(CC) $(CFLAGS) -o $@ $<

factorial: factorial.c
	$(CC) $(CFLAGS) -o $@ $<

run: gcd
	./gcd

check: invariant
	./invariant

fact: factorial
	./factorial

clean:
	rm -f gcd invariant factorial

.PHONY: all run check fact clean

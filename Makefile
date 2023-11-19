CC=gcc
CCFLAGS=-Wall -Wextra -static -o substring

SOURCE=substring.c

compile:
	$(CC) $(CCFLAGS) $(SOURCE)

clean:
	rm -rf substring
	rm -rf *.c~
	rm -rf *~

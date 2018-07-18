CC = gcc
CFLAGS = -I.
linked2: link2.o
	$(CC) $(CFLAGS) $^ -o $@ -Wall -Wextra
	

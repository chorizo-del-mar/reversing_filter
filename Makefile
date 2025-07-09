FILES = main.c
CC = gcc
FLAGS = -Wall -Wextra -O2 -o reversing_filter

reversing_filter:
	$(CC) $(FLAGS) $(FILES)

clean:
	rm -v reversing_filter

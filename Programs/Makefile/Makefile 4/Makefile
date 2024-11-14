# In this make file we can create variables names as CC & FLAG.
CC=gcc

FLAG=-c

all: final
	
final : main.o helper.o
	$(CC) main.o helper.o -o final

main.o : main.c
	$(CC) $(FLAG) main.c -o main.o

helper.o : helper.c -o helper.o
	$(CC) $(FLAG) helper.c

clean:
	rm main.o helper.o

all: final
	
final : main.o helper.o
	gcc main.o helper.o -o final

main.o : main.c
	gcc -c main.c

helper.o : helper.c
	gcc -c helper.c

clean:
	rm main.o helper.o

all: servidor cliente

servidor:
	gcc -o server server.c

cliente:
	gcc -o client client.c

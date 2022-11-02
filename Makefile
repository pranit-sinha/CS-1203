CC=gcc
CFLAGS=-Wall -std=c99

helloworld: hello_world.c
	$(CC) hello_world.c -o exe/hello

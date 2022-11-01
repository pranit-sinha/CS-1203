CC=gcc
CFLAGS=-Wall

helloworld: hello_world.c
	gcc -std=c99 hello_world.c -o exe/hello

CC			= gcc
CFLAGS		= -Wall -std=c99
OBJFILES	= LinkedList.o Array.o ReverseLinkedList.o SelectionSortArray.o SelectionSortLinkedList.o 
BUILD		= build

reverse: LinkedList.o ReverseLinkedList.o 
	make build && $(CC) $(CFLAGS) -o $(BUILD)/reverse LinkedList.o ReverseLinkedList.o  

sellink: LinkedList.o SelectionSortLinkedList.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/selectlink LinkedList.o SelectionSortLinkedList.o

selarr: Array.o SelectionSortArray.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/selectarr Array.o SelectionSortArray.o

build:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) $(OBJFILES)

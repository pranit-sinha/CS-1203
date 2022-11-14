CC			= gcc
CFLAGS		= -Wall -std=c99
OBJFILES	= LinkedList.o Array.o LinkedListImplementation.o ReverseLinkedList.o SelectionSortArray.o SelectionSortLinkedList.o ChunkReverseLinkedList.o bst.o SelSort.o
BUILD		= build

all: LinkedList.o Array.o LinkedListImplementation.o ReverseLinkedList.o SelectionSortArray.o SelectionSortLinkedList.o ChunkReverseLinkedList.o bst.o SelSort.o
	make implement && make reverse && make selarr && make bst

implement: LinkedList.o LinkedListImplementation.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/implement LinkedList.o LinkedListImplementation.o

reverse: LinkedList.o ReverseLinkedList.o 
	make build && $(CC) $(CFLAGS) -o $(BUILD)/reverse LinkedList.o ReverseLinkedList.o  

chunk: LinkedList.o ChunkReverseLinkedList.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/chunk LinkedList.o ChunkReverseLinkedList.o

sellink: LinkedList.o SelectionSortLinkedList.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/selectlink LinkedList.o SelectionSortLinkedList.o

selarr: Array.o SelectionSortArray.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/selectarr Array.o SelectionSortArray.o

bst: Array.o SelSort.o bst.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/bst Array.o SelSort.o bst.o

build:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) $(OBJFILES)

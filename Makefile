CC			= gcc
CFLAGS		= -Wall -std=c99
OBJFILES	= LinkedList.o Array.o LinkedListImplementation.o ReverseLinkedList.o SelectionSortLinkedList.o ChunkReverseLinkedList.o bst.o Sort.o SelectionSortArray.o bstdelete.o heap.o avl.o
BUILD		= build

all: LinkedList.o Array.o LinkedListImplementation.o ReverseLinkedList.o SelectionSortLinkedList.o ChunkReverseLinkedList.o bst.o SelectionSortArray.o heap.o avl.o 
	make implement && make reverse && make selarr && make bst && make bstdel && make heap && make avl

implement: LinkedList.o LinkedListImplementation.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/implement LinkedList.o LinkedListImplementation.o

reverse: LinkedList.o ReverseLinkedList.o 
	make build && $(CC) $(CFLAGS) -o $(BUILD)/reverse LinkedList.o ReverseLinkedList.o  

chunk: LinkedList.o ChunkReverseLinkedList.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/chunk LinkedList.o ChunkReverseLinkedList.o

sellink: LinkedList.o SelectionSortLinkedList.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/selectlink LinkedList.o SelectionSortLinkedList.o

selarr: Array.o Sort.o SelectionSortArray.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/selectarr Array.o Sort.o SelectionSortArray.o

insarr: Array.o InsertionSortArray.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/insertarr Array.o InsertionSortArray.o

bst: Array.o Sort.o bst.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/bst Array.o Sort.o bst.o

bstdel: Array.o Sort.o bstdelete.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/bstdel Array.o Sort.o bstdelete.o

heap: Array.o heap.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/heap Array.o heap.o 

avl: Array.o Sort.o avl.o
	make build && $(CC) $(CFLAGS) -o $(BUILD)/avl Array.o Sort.o avl.o 

build:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) $(OBJFILES)

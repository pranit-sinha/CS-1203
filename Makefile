CC			= gcc
CFLAGS		= -Wall -std=c99
OBJFILES	= LinkedList.o ReverseLinkedList.o
TARGET		= reverse
BUILD		= build

$(BUILD)/$(TARGET): $(OBJFILES) 
	$(CC) $(CFLAGS) -o $(BUILD)/$(TARGET) $(OBJFILES)  

build:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) $(OBJFILES)

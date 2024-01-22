CC = g++
CFLAGS = -Wall -g

TARGET = main

all: $(TARGET)
	./$(TARGET).exe

$(TARGET) : $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp
	
clean:
	del $(TARGET).exe
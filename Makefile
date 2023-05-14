CC = gcc
CFLAGS = -W -Wall
TARGET = tasklist
OBJECTS = main.c project_manager.o

all : $(TARGET)
$(TARGET) : $(OBJECTS)
			  $(CC) $(CFLAGES) -o $@ $^
clean:
	  rm *.o tasklist

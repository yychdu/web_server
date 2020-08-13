TARGET=server
CC=arm-linux-gnueabihf-gcc
SRC=*.c

all:
	$(CC) $(SRC) -I./ -o $(TARGET) -lpthread

.PHONY:clean
clean:
	rm $(TARGET)
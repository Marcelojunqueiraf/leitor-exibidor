TARGET = a.out

all:
	gcc -std=c99 -Wall leitor.c main.c -o $(TARGET) -lm

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
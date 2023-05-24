TARGET=a.out

all:
	gcc -std=c99 -Wall main.c -o $(TARGET) -lm

clean:
	rm a.out
	rm *.gch
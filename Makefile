TARGET = main.out
FLAGS = -Wall -std=c99 -lm
LEITORES = leitores/bytes.c leitores/class-file.c

all:
	gcc $(FLAGS) $(LEITORES) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
TARGET = leitor-exibidor
FLAGS = -Wall -std=c99 -lm
LEITORES = leitores/read-bytes.c leitores/read-class-file.c leitores/show.c

all:
	gcc $(FLAGS) $(LEITORES) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
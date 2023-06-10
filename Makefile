TARGET = leitor-exibidor
FLAGS = -Wall -std=c99 -lm
LEITORES = leitores/read-bytes.c leitores/read-class-file.c leitores/attributes.c
EXIBIDORES = exibidores/show.c exibidores/attribute.c exibidores/common.c

all:
	gcc $(FLAGS) $(LEITORES) $(EXIBIDORES) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
TARGET = leitor-exibidor
FLAGS = -Wall -std=c99 -lm
COMMON = common/get-utf8.c
LEITORES_ATTRIBUTES = leitores/attributes/attributes.c leitores/attributes/code.c leitores/attributes/line-number-table.c  leitores/attributes/source-file.c
LEITORES = leitores/read-bytes.c leitores/read-class-file.c $(LEITORES_ATTRIBUTES)
EXIBIDORES = exibidores/show.c exibidores/attribute.c

all:
	gcc $(FLAGS) $(COMMON) $(LEITORES) $(EXIBIDORES) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
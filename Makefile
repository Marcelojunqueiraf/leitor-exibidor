TARGET = leitor-exibidor
FLAGS = -Wall -std=c99 -lm
COMMON = common/get-utf8.c
LEITORES_ATTRIBUTES = leitores/attributes/attributes.c leitores/attributes/code.c leitores/attributes/line-number-table.c  leitores/attributes/source-file.c
LEITORES = leitores/read-bytes.c leitores/read-class-file.c $(LEITORES_ATTRIBUTES)
EXIBIDORES_ATTRIBUTES = exibidores/attributes/attributes.c exibidores/attributes/code.c exibidores/attributes/line-number-table.c  #exibidores/attributes/source-file.c
EXIBIDORES = exibidores/show.c $(EXIBIDORES_ATTRIBUTES)

all:
	gcc $(FLAGS) $(COMMON) $(LEITORES) $(EXIBIDORES) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
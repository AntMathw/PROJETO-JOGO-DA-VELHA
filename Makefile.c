Nome do compilador
CC = gcc

Flags de compilação: -Wall (todos os avisos), -Wextra (avisos extras), -std=c99 (padrão C99)
CFLAGS = -Wall -Wextra -std=c99

Nome do executável final
TARGET = velha

Diretório onde os arquivos fonte (.c) estão localizados
SRCDIR = src

Lista de todos os arquivos fonte que precisam ser compilados
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/game.c

Converte a lista de arquivos fonte (.c) para arquivos objeto (.o) no mesmo diretório
Ex: src/main.c -> src/main.o
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.o, $(SOURCES))

Define os targets que não são arquivos reais (clean, all)
.PHONY: all clean

-----------------
Regra Principal (Default)
-----------------
O comando 'make' sem argumentos executa esta regra
all: (TARGET)@echo""@echo"Compila 
c
\c
​
  
a
~
 oconclu 
ı
ˊ
 da!Use 
′
 ./(TARGET)' para executar o jogo."

-----------------
Criação do Executável
-----------------
Liga os arquivos objeto para criar o executável final
$(TARGET): $(OBJECTS)
@echo "Montando o executável: $(TARGET)"
$(CC) $(CFLAGS) $^ -o $@

-----------------
Regra de Compilação de Objetos
-----------------
Regra genérica para compilar qualquer arquivo .c em .o
$< é o nome do arquivo .c (source)
$@ é o nome do arquivo .o (target)
$(SRCDIR)/%.o: $(SRCDIR)/%.c
@echo "Compilando: $<"
$(CC) $(CFLAGS) -c $< -o $@

-----------------
Regra de Limpeza
-----------------
Remove o executável final e todos os arquivos objeto gerados
clean:
@echo "Limpando arquivos binários e objetos..."
$(RM) $(TARGET)
$(RM) $(OBJECTS)
@echo "Limpeza concluída."

-----------------
Regra de Execução (Opcional, mas útil)
-----------------
Permite rodar o jogo com 'make run'
run: (TARGET)@echo""@echo"IniciandooJogodaVelha..."./(TARGET)

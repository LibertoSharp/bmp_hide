# Nome del programma finale
PROGRAM_NAME = bmp

# Cartelle dei sorgenti e degli header
SRC_DIR = src
INC_DIR = includes

# File sorgente (espansi)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# File oggetto (sostituisce .c con .o mantenendo il path)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Header files
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Compilatore e flag
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -lm

# Regola di default
all: $(PROGRAM_NAME)

# Link finale
$(PROGRAM_NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Compila ogni file .c in .o
# Usa pattern rule su percorsi
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Pulisce i file oggetto
clean:
	rm -f $(OBJ_FILES)

# Pulisce tutto: oggetti + binario
fclean: clean
	rm -f $(PROGRAM_NAME)

# Ricompila tutto da zero
re: fclean all

# Indica che questi target non sono file
.PHONY: all clean fclean re


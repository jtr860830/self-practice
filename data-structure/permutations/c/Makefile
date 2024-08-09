CC = gcc
ARGS = -Wall -std=c11
SRC = main.c
OBJ = main.o
EXE = perm

all: $(OBJ)
	$(CC) $(ARGS) -o $(EXE) $(OBJ)  

$(OBJ): $(SRC)
	$(CC) $(ARGS) -c $(SRC) -o $(OBJ)

.PHONY: clean
clean:
	rm -rf $(EXE) $(OBJ)

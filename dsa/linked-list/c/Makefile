CC = gcc
ARGS = -Wall -std=c11
SRC = main.c
OBJ = main.o
EXE = linked-list

all: $(OBJ)
	$(CC) $(ARGS) -o $(EXE) $(OBJ)  

$(OBJ): $(SRC)
	$(CC) $(ARGS) -c $(SRC) -o $(OBJ)

.PHONY: clean
clean:
	rm -rf $(EXE) $(OBJ)

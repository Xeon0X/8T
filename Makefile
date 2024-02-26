CC=g++
CFLAGS= -c -Wall 
LIBFLAGS=-lSDL2main  -lSDL2
OBJ_DIR = obj
FILES_DIR = src/core


all:  bin/main

bin/main : $(OBJ_DIR)/main.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o -o bin/main $(LIBFLAGS)


$(OBJ_DIR)/main.o: $(FILES_DIR)/main.cpp
	$(CC) $(CFLAGS) $(FILES_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.cpp  $(FILES_DIR)/%.h
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*.o 
	rm -rf bin/main






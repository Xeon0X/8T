CC=g++
CFLAGS= -c -Wall 
LIBFLAGS=-lSDL2main  -lSDL2
OBJ_DIR = obj


all:  bin/main

bin/main : $(OBJ_DIR)/main.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o -o bin/main $(LIBFLAGS)


$(OBJ_DIR)/main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/%.o: src/%.cpp  src/%.h
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*.o 
	rm -rf bin/main






CC=g++
CFLAGS= -c -g -Wall -Isrc/core -Isrc/graphics
LIBFLAGS=-lSDL2main  -lSDL2 -lSDL2_image -lSDL2_ttf 
OBJ_DIR = obj
FILES_DIR = src/core
FILES_DIR_GRAPHIC = src/graphics


all:  bin/graphic

bin/graphic : $(OBJ_DIR)/PlayGraphic.o $(OBJ_DIR)/Graphic.o $(OBJ_DIR)/GridGraphic.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o
	$(CC) $(OBJ_DIR)/PlayGraphic.o $(OBJ_DIR)/Graphic.o $(OBJ_DIR)/GridGraphic.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o -o bin/graphic $(LIBFLAGS)


$(OBJ_DIR)/main.o: $(FILES_DIR)/main.cpp
	$(CC) $(CFLAGS) $(FILES_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/PlayGraphic.o: $(FILES_DIR_GRAPHIC)/PlayGraphic.cpp
	$(CC) $(CFLAGS) $(FILES_DIR_GRAPHIC)/PlayGraphic.cpp -o $(OBJ_DIR)/PlayGraphic.o

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.cpp  $(FILES_DIR)/%.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(FILES_DIR_GRAPHIC)/%.cpp  $(FILES_DIR_GRAPHIC)/%.h
	$(CC) $(CFLAGS) $< -o $@



clean:
	rm -rf $(OBJ_DIR)/*.o 
	rm -rf bin/main






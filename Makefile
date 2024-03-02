CC=g++
CFLAGS= -c -g -Wall -Isrc/core -Isrc/graphics
LIBFLAGS=-lSDL2main  -lSDL2 -lSDL2_image -lSDL2_ttf 
OBJ_DIR = obj
FILES_DIR = src/core
FILES_DIR_GRAPHIC = src/graphics
FILES_DIR_CONSOLE = src/console

all:  bin/graphic bin/console

bin/graphic : $(OBJ_DIR)/PlayGraphic.o $(OBJ_DIR)/Graphic.o $(OBJ_DIR)/GridGraphic.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o
	$(CC) $(OBJ_DIR)/PlayGraphic.o $(OBJ_DIR)/Graphic.o $(OBJ_DIR)/GridGraphic.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o -o bin/graphic $(LIBFLAGS)

bin/console : $(OBJ_DIR)/playConsole.o $(OBJ_DIR)/Console.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o
	$(CC) $(OBJ_DIR)/playConsole.o $(OBJ_DIR)/Console.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Card.o $(OBJ_DIR)/Case.o $(OBJ_DIR)/Deck.o $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Piece.o -o bin/console $(LIBFLAGS)

$(OBJ_DIR)/playConsole.o: $(FILES_DIR_CONSOLE)/playConsole.cpp
	$(CC) $(CFLAGS) $(FILES_DIR_CONSOLE)/playConsole.cpp -o $(OBJ_DIR)/playConsole.o

$(OBJ_DIR)/main.o: $(FILES_DIR)/main.cpp
	$(CC) $(CFLAGS) $(FILES_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/PlayGraphic.o: $(FILES_DIR_GRAPHIC)/PlayGraphic.cpp
	$(CC) $(CFLAGS) $(FILES_DIR_GRAPHIC)/PlayGraphic.cpp -o $(OBJ_DIR)/PlayGraphic.o

$(OBJ_DIR)/%.o: $(FILES_DIR)/%.cpp  $(FILES_DIR)/%.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(FILES_DIR_GRAPHIC)/%.cpp  $(FILES_DIR_GRAPHIC)/%.h
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(FILES_DIR_CONSOLE)/%.cpp  $(FILES_DIR_CONSOLE)/%.h
	$(CC) $(CFLAGS) $< -o $@



clean:
	rm -rf $(OBJ_DIR)/*.o 
	rm -rf bin/main






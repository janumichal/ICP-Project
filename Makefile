SOURCES = src/Main.cpp src/Chess_common/Board.cpp src/Chess_common/Field.cpp src/Chess_common/Game.cpp src/Chess_common/History.cpp src/Chess_common/HistoryItem.cpp src/Chess_common/Move.cpp src/Chess_common/Tab.cpp src/Chess_common/others.cpp

HEADER = src/enum/colors_piece.h src/Chess_pieces/Piece.h src/Chess_pieces/Bishop.h src/Chess_pieces/Knight.h src/Chess_pieces/King.h src/Chess_pieces/Pawn.h src/Chess_pieces/Queen.h src/Chess_pieces/Rook.h src/Chess_common/Board.h src/Chess_common/Field.h src/enum/direction.h src/Chess_common/HistoryItem.h src/Chess_common/History.h src/Chess_common/Game.h src/Chess_common/Move.h src/Chess_common/Tab.h src/Chess_common/others.h

SOURCE_OBJ = Main.o Board.o Field.o Game.o History.o HistoryItem.o Move.o Tab.o others.o


chess: $(SOURCE_OBJ)
	g++ -o chess $(SOURCE_OBJ)

Main.o: $(SOURCES) $(HEADER)
	g++ -c $(SOURCES) $(HEADER)


run:
	./chess

clean:
	rm -rf doc/html *.o chess *.zip

doxygen:
	doxygen src/doxyconf

pack: clean
	zip -r xjanum03-xgajda06-100-0.zip doc examples src Makefile README.txt


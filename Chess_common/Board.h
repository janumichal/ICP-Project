//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_BOARD_H
#define CPP_CHESS_BOARD_H

#include "../Chess_pieces/Bishop.h"
#include "../Chess_pieces/King.h"
#include "../Chess_pieces/Knight.h"
#include "../Chess_pieces/Rook.h"
#include "../Chess_pieces/Pawn.h"
#include "../Chess_pieces/Queen.h"
#include "../Chess_pieces/Piece.h"
#include "Field.h"
#include "HistoryItem.h"
#include "Move.h"

const int BOARD_SIZE = 8;

using namespace std;

class Board {
private:
    Field* board_array[BOARD_SIZE][BOARD_SIZE];
    HistoryItem *historyItem;
    bool white_on_move;
    int white_points;
    int black_points;

public:
    bool game_end = false;

    Board();
    bool is_white_on_move();
    void printPoints();
    Field* getField(int, int);
    HistoryItem* movePiece(Field *, Field *);

private:
    void moveBishop(Field *, Field *);
    void moveQueen(Field *, Field *);
    void moveKing(Field *, Field *);
    void moveRook(Field *, Field *);
    void moveInDir(direction , Field *, Field *);
    void movePawn(Field *, Field *);
    void moveKnight(Field *from, Field *to);
    void move(Field *, Field *);

public:
    void moveHistory(Field *, Field *, Piece *, Piece *);


    //############################################# CREATING BOARD #####################################################
    // show piece placement in text mode
    void showPiecesText();
    void fillBoard();
    void placePieces(color_piece );

private:
    void fillArrayAround();
    bool isInArray(int x, int y);

public:
    int getWhite_points();
    int getBlack_points();

};


#endif //CPP_CHESS_BOARD_H

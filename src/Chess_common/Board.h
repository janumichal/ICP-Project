/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

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

/**
 * @brief Class for Board
 */
class Board {
private:
    Field* board_array[BOARD_SIZE][BOARD_SIZE];
    HistoryItem *historyItem;
    bool white_on_move;
    int white_points;
    int black_points;

public:
    /**
     * @brief Checks if game ended
     */
    bool game_end = false;

    /**
     * @brief Creates instance of board.
     */
    Board();

    /**
     * @brief Check if is white on move.
     * @return if white on move.
     */
    bool is_white_on_move();

    /**
     * @brief Prints out the points
     */
    void printPoints();

    /**
     * @brief get field from 2D array on position [x][y]
     * @param x Vertical position
     * @param y Horizontal position
     * @return field on position
     */
    Field* getField(int x, int y);

    /**
     * @brief moves piece from to to and saves move to history
     * @param from field from
     * @param to field to
     * @return history item
     */
    HistoryItem* movePiece(Field *from, Field *to);

private:
    /**
     * @brief moves Bishop from field from to field to
     * @param from field from
     * @param to field to
     */
    void moveBishop(Field *from, Field *to);

    /**
     * @brief moves Queen from field from to field to
     * @param from field from
     * @param to field to
     */
    void moveQueen(Field *from, Field *to);

    /**
     * @brief moves King from field from to field to
     * @param from field from
     * @param to field to
     */
    void moveKing(Field *from, Field *to);

    /**
     * @brief moves Rook from field from to field to
     * @param from field from
     * @param to field to
     */
    void moveRook(Field *from, Field *to);

    /**
     * @brief moves piece in direction
     * @param direction direction to go to
     * @param from field from
     * @param to field to
     */
    void moveInDir(direction direction, Field *from, Field *to);

    /**
     * @brief moves Pawn from field from to field to
     * @param from field from
     * @param to field to
     */
    void movePawn(Field *from, Field *to);

    /**
     * @brief moves Knight from field from to field to
     * @param from field from
     * @param to field to
     */
    void moveKnight(Field *from, Field *to);

    /**
     * @brief move from field from to field to
     * @param from field from
     * @param to field to
     */
    void move(Field *from, Field *to);

public:
    /**
     * @brief applayes history item and specified move
     * @param from field from
     * @param to field to
     * @param target piece that has been taken (null if doesnt exist)
     * @param exchange for what was exchenged (empty if not)
     */
    void moveHistory(Field *from, Field *to, Piece *target, Piece *exchange);

    /**
     * @brief cleans board of everything
     */
    void cleanBoard();


    //############################################# CREATING BOARD #####################################################
    // show piece placement in text mode
    /**
     * @brief Displays piece placement in console
     */
    void showPiecesText();

    /**
     * @brief fills board on starting point
     */
    void fillBoard();

    /**
     * @brief places pieces of specified color
     * @param color specified color
     */
    void placePieces(color_piece color);

private:
    /**
     * @brief fills enum map in field
     */
    void fillArrayAround();

    /**
     * @brief checks if position is still in array
     * @param x position x
     * @param y position y
     * @return if is inside array
     */
    bool isInArray(int x, int y);

public:
    /**
     * @brief get points of white player
     * @return points
     */
    int getWhite_points();
    /**
     * @brief get points of black player
     * @return points
     */
    int getBlack_points();

};


#endif //CPP_CHESS_BOARD_H

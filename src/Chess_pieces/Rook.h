/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_ROOK_H
#define CPP_CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    /*!
     * @brief Class for Rook piece.
     * @param x Vertical location of piece.
     * @param y Horizontal location of piece.
     * @param color Color of piece.
     */
    Rook(int x, int y, color_piece color) : Piece(x, y, 5, color, 'r'){}

    /*!
     * @brief Checks if move is valid for Rook.
     * @param x Vertical location that piece has to move on.
     * @param y Horizontal location that piece has to move on.
     * @return Is valid.
     */
    bool isMoveValid(int x, int y){
        return ((x == this->x && y != this->y) || (x != this->x && y == this->y));
    }
};

#endif //CPP_CHESS_ROOK_H

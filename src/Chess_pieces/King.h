/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_KING_H
#define CPP_CHESS_KING_H

#include "Piece.h"

class King : public Piece{
public:
    /*!
     * @brief Checks if move is valid for King.
     * @param x Vertical location of piece.
     * @param y Horizontal location of piece.
     * @param color Color of piece.
     */
    King(int x, int y, color_piece color) : Piece(x, y, 0, color, 'K'){}

    /*!
     * @brief Checks if move is valid for King.
     * @param x Vertical location that piece has to move on.
     * @param y Horizontal location that piece has to move on.
     * @return Is valid.
     */
    bool isMoveValid(int x, int y){
        return (!(x == this->x && y == this->y)) && ((( this->x == x+1 ) || ( this->x == x-1 ) || (this->x == x && this->y != y)) && (( this->y == y-1 ) || ( this->y == y+1 ) || (this->y == y && this->x != x)) );
    }
};

#endif //CPP_CHESS_KING_H

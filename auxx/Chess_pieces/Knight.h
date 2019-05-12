/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_KNIGHT_H
#define CPP_CHESS_KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
public:
    /**
     * @brief Class for Knight piece.
     * @param x Vertical location of piece.
     * @param y Horizontal location of piece.
     * @param color Color of piece.
     */
    Knight(int x, int y, color_piece color) : Piece(x, y, 3, color, 'k'){}

    /**
     * @brief Checks if move is valid for Knight.
     * @param x Vertical location that piece has to move on.
     * @param y Horizontal location that piece has to move on.
     * @return Is valid.
     */
    bool isMoveValid(int x, int y){
        if(x > this->x){
            if(y > this->y){ // LEFT DOWN
                return ((x == (this->x+1) && y == (this->y+2)) || (x == (this->x+2) && y == (this->y+1)));
            }else if (y < this->y){ //LEFT UP
                return ((x == (this->x+1) && y == (this->y-2)) || (x == (this->x+2) && y == (this->y-1)));
            }
            return false;
        }else if (x < this->x){
            if(y > this->y){ // RIGHT DOWN
                return ((x == (this->x-1) && y == (this->y+2)) || (x == (this->x-2) && y == (this->y+1)));
            }else if (y < this->y){ //RIGHT UP
                return ((x == (this->x-1) && y == (this->y-2)) || (x == (this->x-2) && y == (this->y-1)));
            }
            return false;
        }
        return false;
    }
};

#endif //CPP_CHESS_KNIGHT_H

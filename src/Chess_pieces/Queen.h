/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_QUEEN_H
#define CPP_CHESS_QUEEN_H

#include "Piece.h"

class Queen : public Piece{
public:
    /**
    * @brief Class for Queen piece.
    * @param x Vertical location of piece.
    * @param y Horizontal location of piece.
    * @param color Color of piece.
    */
    Queen(int x, int y, color_piece color) : Piece(x, y, 9, color, 'q'){}

    /**
     * @brief Checks if move is valid for Queen.
     * @param x Vertical location that piece has to move on.
     * @param y Horizontal location that piece has to move on.
     * @return Is valid.
     */
    bool isMoveValid(int x, int y){
        int array_size = 8; //TODO CHANGE FOR BOARDSIZE

        for (int i = 1; i <= array_size; i++){

            if ((x == this->x-i)&&(y == this->y-i)){
                return true;
            }else if((x == this->x-i)&&(y == this->y+i)){
                return true;
            }else if ((x == this->x+i)&&(y == this->y+i)){
                return true;
            }else if (((x == this->x+i)&&(y == this->y-i))){
                return true;
            }
        }
        return ((x == this->x && y != this->y) || (x != this->x && y == this->y));
    }
};

#endif //CPP_CHESS_QUEEN_H

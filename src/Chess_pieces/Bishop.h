/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_BISHOP_H
#define CPP_CHESS_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {
public:
    /*!
     * @brief Class for Bishop piece.
     * @param x Vertical location of piece.
     * @param y Horizontal location of piece.
     * @param color Color of piece.
     */
    Bishop(int x, int y, color_piece color) : Piece(x,y,3,color, 'b'){}

    /*!
     * @brief Checks if move is valid for Bishop.
     * @param x Vertical location that piece has to move on.
     * @param y Horizontal location that piece has to move on.
     * @return Is valid.
     */
    bool isMoveValid(int x, int y){
        int array_size = 8;
        for (int i = 1; i <= array_size; i++){
            if ((x == this->x-i)&&(y == this->y-i)){
                return true;
            }else if((x == this->x-i)&&(y == this->y+i)){
                return true;
            }else if ((x == this->x+i)&&(y == this->y+i)){
                return true;
            }else if ((x == this->x+i)&&(y == this->y-i)){
                return true;
            }
        }
        return false;
    }
};

#endif //CPP_CHESS_BISHOP_H

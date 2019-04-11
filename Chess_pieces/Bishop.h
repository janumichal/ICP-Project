//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_BISHOP_H
#define CPP_CHESS_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int x, int y, color_piece color) : Piece(x,y,3,color){}
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

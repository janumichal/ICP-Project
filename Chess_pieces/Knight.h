//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_KNIGHT_H
#define CPP_CHESS_KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
public:
    Knight(int x, int y, color_piece color) : Piece(x, y, 3, color){}
    bool isMoveValid(int x, int y){
        if(x > this.x){
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

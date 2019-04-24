//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_QUEEN_H
#define CPP_CHESS_QUEEN_H

#include "Piece.h"

class Queen : public Piece{
public:
    Queen(int x, int y, color_piece color) : Piece(x, y, 9, color, 'q'){}
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

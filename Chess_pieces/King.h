//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_KING_H
#define CPP_CHESS_KING_H

#include "Piece.h"

class King : public Piece{
public:
    King(int x, int y, color_piece color) : Piece(x, y, 0, color, 'K'){}
    bool isMoveValid(int x, int y){
        return (!(x == this->x && y == this->y)) && ((( this->x == x+1 ) || ( this->x == x-1 ) || (this->x == x && this->y != y)) && (( this->y == y-1 ) || ( this->y == y+1 ) || (this->y == y && this->x != x)) );
    }
};

#endif //CPP_CHESS_KING_H

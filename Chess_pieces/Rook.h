//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_ROOK_H
#define CPP_CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    Rook(int x, int y, color_piece color) : Piece(x, y, 5, color, 'r'){}
    bool isMoveValid(int x, int y){
        return ((x == this->x && y != this->y) || (x != this->x && y == this->y));
    }
};

#endif //CPP_CHESS_ROOK_H

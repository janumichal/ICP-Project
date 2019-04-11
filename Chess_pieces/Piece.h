//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_PIECE_H
#define CPP_CHESS_PIECE_H

#include "../enum/colors_piece.h"

class Piece{
protected:
    int x,y;
    color_piece color;
    int value_of_piece;

public:
    Piece(int x, int y, int value_of_piece, color_piece color){
        this->x = x;
        this->y = y;
        this->value_of_piece = value_of_piece;
        this->color = color;
    }

    int getValue(){
        return this->value_of_piece;
    }

    color_piece getColor(){
        return this->color;
    }

    void setCol(int x){
        this->x = x;
    }

    void setRow(int y){
        this->y = y;
    }
};

#endif //CPP_CHESS_PIECE_H

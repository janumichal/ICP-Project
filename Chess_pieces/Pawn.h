//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_PAWN_H
#define CPP_CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece{
private:
    bool is_on_starting_position = true;
public:
    Pawn(int x, int y, color_piece color) : Piece(x, y, 1, color){}
    bool isMoveValid(int x, int y, Piece *target){
        if (this->color == BLACK){
            if (target == nullptr){
                if(getIsOnStart()){
                    setNotOnStart();
                    return (y <= (this->y + 2) && y > this->y && this->x == x);
                }
                return (y <= (this->y + 1) && y > this->y && x == this->x);
            }else{
                return (y <= (this->y + 1) && (x == this->x+1 || x == this->x-1));
            }
        }else{
            if (target == nullptr){
                if(getIsOnStart()){
                    setNotOnStart();
                    return (this->y <= (y + 2)  && this->y > y && this->x == x); // CHECKED
                }
                return (this->y == (y + 1) && this->y > y  && x == this->x); // CHECKED
            }else{
                return (this->y == (y + 1) && (x+1 == this->x || x-1 == this->x)); // CHECKED
            }
        }
    }
    bool getIsOnStart(){
        return this->is_on_starting_position;
    }

    void setNotOnStart(){
        this->is_on_starting_position = false;
    }
};

#endif //CPP_CHESS_PAWN_H

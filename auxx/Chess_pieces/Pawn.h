/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_PAWN_H
#define CPP_CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece{
private:
    bool is_on_starting_position = true;
public:
    /**
     * @brief Class for Pawn piece.
     * @param x Vertical location of piece.
     * @param y Horizontal location of piece.
     * @param color Color of piece.
     */
    Pawn(int x, int y, color_piece color) : Piece(x, y, 1, color, 'p'){}

    /**
     * @brief Checks if move is valid for Pawn.
     * @param x Vertical location that piece has to move on.
     * @param y Horizontal location that piece has to move on.
     * @param target Pointer on piece on position (nullptr if empty)
     * @return Is Valid
     */
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

    /**
     * @brief Checks if piece is on starting position.
     * @return Is on starting position.
     */
    bool getIsOnStart(){
        return this->is_on_starting_position;
    }

    /**
     * @brief Sets is_on_starting_position as false.
     */
    void setNotOnStart(){
        this->is_on_starting_position = false;
    }
};

#endif //CPP_CHESS_PAWN_H

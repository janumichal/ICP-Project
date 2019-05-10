/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_PIECE_H
#define CPP_CHESS_PIECE_H

#include "../enum/colors_piece.h"

class Piece{
protected:
    int x,y;
    color_piece color;
    int value_of_piece;
    char name;

public:
    /**
     * @brief Class for Original piece
     * @param x Vertical location of piece.
     * @param y Horizontal location of piece.
     * @param value_of_piece Value of specific piece.
     * @param color Color of piece.
     * @param name Name of piece.
     */
    Piece(int x, int y, int value_of_piece, color_piece color, char name){
        this->x = x;
        this->y = y;
        this->value_of_piece = value_of_piece;
        this->color = color;
        this->name = name;
    }

    /**
     * @brief Getter for piece value.
     * @return value of piece
     */
    int getValue(){
        return this->value_of_piece;
    }

    /**
     * @brief Getter for piece color.
     * @return color of piece
     */
    color_piece getColor(){
        return this->color;
    }

    /**
     * @brief Setter for column.
     */
    void setCol(int x){
        this->x = x;
    }

    /**
     * @brief Setter for row.
     */
    void setRow(int y){
        this->y = y;
    }

    /**
     * @brief Getter for piece name.
     * @return name of piece
     */
    char getName(){
        return this->name;
    }

};

#endif //CPP_CHESS_PIECE_H

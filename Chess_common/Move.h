//
// Created by janum on 23.04.2019.
//

#ifndef CPP_CHESS_MOVE_H
#define CPP_CHESS_MOVE_H

#include "Field.h"
#include "../enum/colors_piece.h"

using namespace std;

class Move{
private:
    Field *from;
    Field *to;
    bool is_take;
    bool is_check;
    bool is_mat;
    color_piece color;

    bool is_king;
    bool is_queen;
    bool is_bishop;

    bool is_knight;
    bool is_pawn;
    bool is_rook;

    int column;
    int row;

    char exchange;

public:
    Move(){
        this->column = -1;
        this->row = -1;
        this->is_take = false;
        this->is_check = false;
        this->is_mat = false;

        this->is_knight = false;
        this->is_king = false;
        this->is_queen = false;
        this->is_bishop = false;
        this->is_pawn = false;
        this->is_rook = false;
    }

    void setColor(color_piece color) {
        this->color = color;
    }

    color_piece getColor() {
        return this->color;
    }


    string pritnMove(){
        string output;
        if (isKing()){
            output += 'K';
        }else if (isQueen()){
            output += 'D';
        }else if (isKnight()){
            output += 'J';
        }else if (isBishop()){
            output += 'S';
        }else if (isRook()){
            output += 'V';
        }

        if (this->from != nullptr){
            char x = (char)(this->from->getCol() + 97);
            char y = (char)(8 - this->from->getRow() + 48);
            output += x;
            output += y;

        }else {
            if (this->column != -1){
                char znak = (char)(this->column + 97); // COLUMN WRONG
                output += znak;
            }else if (this->row != -1){
                char znak = (char)(8 - this->row + 48); // COLUMN WRONG
                output += znak;
            }
        }

        if (isTake()){
            output += 'x';
        }

        char x = (char)(this->to->getCol() + 97);
        char y = (char)(8 - this->to->getRow() + 48);
        output += x;
        output += 'y';
        if (this->getExchange() != '\0'){
            output += this->getExchange();
        }
        if (isMat()){
            output += '#';
        }else if (isCheck()){
            output += '+';
        }
        return output;
    }

    char getExchange() {
        return this->exchange;
    }

    void setExchange(char exchange) {
        this->exchange = exchange;
    }

    void setFrom(Field* from) {
        this->from = from;
    }

    void setTo(Field* to) {
        this->to = to;
    }

    void setTake() {
        this->is_take = true;
    }

    void setCheck() {
        this->is_check = true;
    }

    void setMat() {
        this->is_mat = true;
    }

    void setKing() {
        this->is_king = true;
    }

    void setQueen() {
        this->is_queen = true;
    }

    void setBishop() {
        this->is_bishop = true;
    }

    void setKnight() {
        this->is_knight = true;
    }

    void setPawn() {
        this->is_pawn = true;
    }

    void setRook() {
        this->is_rook = true;
    }

    Field* getFrom() {
        return this->from;
    }

    Field* getTo() {
        return this->to;
    }

    bool isTake() {
        return this->is_take;
    }

    bool isCheck() {
        return this->is_check;
    }

    bool isMat() {
        return this->is_mat;
    }

    bool isKing() {
        return this->is_king;
    }

    bool isQueen() {
        return this->is_queen;
    }

    bool isBishop() {
        return this->is_bishop;
    }

    bool isKnight() {
        return this->is_knight;
    }

    bool isPawn() {
        return this->is_pawn;
    }

    bool isRook() {
        return this->is_rook;
    }

    void setColumn(char column) {
        this->column = ((int)column - 97);
    }

    void setColumn(int column) {
        this->column = column;
    }

    void setRow(char row) {
        this->row = 8 - ((int)row - 48);
    }

    void setRow(int row) {
        this->row = row;
    }

    int getColumn() {
        return this->column;
    }

    int getRow() {
        return this->row;
    }


};

#endif //CPP_CHESS_MOVE_H

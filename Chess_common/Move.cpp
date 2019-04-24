//
// Created by janum on 24.04.2019.
//

#include "Move.h"

using namespace std;

Move::Move(){
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
    this->exchange = '\0';

    this->from = nullptr;
    this->to = nullptr;
}

void Move::setColor(color_piece color) {
    this->color = color;
}

color_piece Move::getColor() {
    return this->color;
}


string Move::pritnMove(){
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

char Move::getExchange() {
    return this->exchange;
}

void Move::setExchange(char exchange) {
    this->exchange = exchange;
}

void Move::setFrom(Field* from) {
    this->from = from;
}

void Move::setTo(Field* to) {
    this->to = to;
}

void Move::setTake() {
    this->is_take = true;
}

void Move::setCheck() {
    this->is_check = true;
}

void Move::setMat() {
    this->is_mat = true;
}

void Move::setKing() {
    this->is_king = true;
}

void Move::setQueen() {
    this->is_queen = true;
}

void Move::setBishop() {
    this->is_bishop = true;
}

void Move::setKnight() {
    this->is_knight = true;
}

void Move::setPawn() {
    this->is_pawn = true;
}

void Move::setRook() {
    this->is_rook = true;
}

Field* Move::getFrom() {
    return this->from;
}

Field* Move::getTo() {
    return this->to;
}

bool Move::isTake() {
    return this->is_take;
}

bool Move::isCheck() {
    return this->is_check;
}

bool Move::isMat() {
    return this->is_mat;
}

bool Move::isKing() {
    return this->is_king;
}

bool Move::isQueen() {
    return this->is_queen;
}

bool Move::isBishop() {
    return this->is_bishop;
}

bool Move::isKnight() {
    return this->is_knight;
}

bool Move::isPawn() {
    return this->is_pawn;
}

bool Move::isRook() {
    return this->is_rook;
}

void Move::setColumn(char column) {
    this->column = ((int)column - 97);
}

void Move::setColumn(int column) {
    this->column = column;
}

void Move::setRow(char row) {
    this->row = 8 - ((int)row - 48);
}

void Move::setRow(int row) {
    this->row = row;
}

int Move::getColumn() {
    return this->column;
}

int Move::getRow() {
    return this->row;
}


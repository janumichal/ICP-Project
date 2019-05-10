//
// Created by janum on 24.04.2019.
//

#include "Field.h"

using namespace std;

Field::Field(int x, int y){
    setCol(x);
    setRow(y);
}

Field* Field::nextField(direction direction){
    return this->fields_around[direction];
}

void Field::addNextField(direction direction, Field *field){
    this->fields_around[direction] = field;
}

void Field::setCol(int col){
    this->col = col;
}

void Field::setRow(int row){
    this->row = row;
}

int Field::getRow() {
    return this->row;
}

int Field::getCol() {
    return this->col;
}

// get piece placed in this field
Piece* Field::getPiece() {
    return this->piece_on_board;
}

// set piece on this field
void Field::setPiece(Piece* piece){
    this->piece_on_board = piece;
}

// check if field is empty
bool Field::isEmpty(){
    return this->piece_on_board == nullptr;
}

// put piece on field if empty and return true if piece was successfuly placed
void Field::putPiece(Piece* piece){
    removePiece();
    if (piece != nullptr){
        piece->setCol(this->getCol());
        piece->setRow(this->getRow());
    }
    setPiece(piece);
}

Piece* Field::removePiece() {
    Piece *piece = this->piece_on_board;
    this->piece_on_board = nullptr;
    return piece;
}


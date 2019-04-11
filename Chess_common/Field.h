//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_FIELD_H
#define CPP_CHESS_FIELD_H

#include <map>
#include "../Chess_pieces/Piece.h"
#include "../enum/direction.h"

class Field{
private:
    int row{};
    int col{};

    Piece *piece_on_board = nullptr;
    std::map<direction , Field*> fields_around;

    Field(int x, int y){
        setCol(x);
        setRow(y);
    }

    Field* nextField(direction direction){
        return this->fields_around[direction];
    }

    void addNextField(direction direction, Field *field){
        this->fields_around[direction] = field;
    }

    void setCol(int col){
        this->col = col;
    }

    void setRow(int row){
        this.row = row;
    }

    int getRow() {
        return this->row;
    }

    int getCol() {
        return this->col;
    }

    // get piece placed in this field
    Piece* getPiece() {
        return this->piece_on_board;
    }

    // set piece on this field
    void setPiece(Piece piece){
        this.piece_on_board = piece;
    }

    // check if field is empty
    bool isEmpty(){
        return this->piece_on_board == nullptr;
    }

    // put piece on field if empty and return true if piece was successfuly placed
    void putPiece(Piece piece){
        removePiece();
        if (piece != null){
            piece.setCol(this.getCol());
            piece.setRow(this.getRow());
        }
        setPiece(piece);
    }

    Piece* removePiece() {
        Piece *piece = this.piece_on_board;
        this->piece_on_board = nullptr;
        return piece;
    }

};

#endif //CPP_CHESS_FIELD_H

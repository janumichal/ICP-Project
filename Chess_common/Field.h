//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_FIELD_H
#define CPP_CHESS_FIELD_H

#include <map>
#include "../Chess_pieces/Piece.h"
#include "../enum/direction.h"

using namespace std;

class Field{
private:
    int row{};
    int col{};
    Piece *piece_on_board = nullptr;
    std::map<direction , Field*> fields_around;

public:
    Field(int , int );
    Field* nextField(direction );
    void addNextField(direction , Field *);
    void setCol(int col);
    void setRow(int row);
    int getRow() ;
    int getCol();
    Piece* getPiece();
    void setPiece(Piece *);
    bool isEmpty();
    void putPiece(Piece *);
    Piece* removePiece();

};

#endif //CPP_CHESS_FIELD_H

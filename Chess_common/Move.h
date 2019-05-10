/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

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
    Move();
    void setColor(color_piece color);
    color_piece getColor();
    string pritnMove();
    char getExchange() ;
    void setExchange(char exchange);
    void setFrom(Field* from);
    void setTo(Field* to);
    void setTake();
    void setCheck();
    void setMat();
    void setKing();
    void setQueen();
    void setBishop();
    void setKnight();
    void setPawn();
    void setRook();
    Field* getFrom();
    Field* getTo();
    bool isTake();
    bool isCheck();
    bool isMat();
    bool isKing();
    bool isQueen();
    bool isBishop();
    bool isKnight();
    bool isPawn();
    bool isRook();
    void setColumn(char column);
    void setColumn(int column);
    void setRow(char row);
    void setRow(int row);
    int getColumn();
    int getRow();

};

#endif //CPP_CHESS_MOVE_H

#include <utility>

//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_HISTORYITEM_H
#define CPP_CHESS_HISTORYITEM_H

#include "../Chess_pieces/Piece.h"
#include "Field.h"

using namespace std;

class HistoryItem{
private:
    Field* from;
    Field* to;
    Piece* target_to;
    Piece* exchange;
public:
    HistoryItem();
    void addValues(Field *from, Field *to, Piece *target_to);
    Field* getFrom();
    Field* getTo();
    Piece* getTarget_to();
    void setExchange(Piece* piece);
    Piece* getExchange();

};

#endif //CPP_CHESS_HISTORYITEM_H

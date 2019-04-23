#include <utility>

//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_HISTORYITEM_H
#define CPP_CHESS_HISTORYITEM_H

#include "../Chess_pieces/Piece.h"
#include "Field.h"

class HistoryItem{
private:
    Field* from;
    Field* to;
    Piece* target_to;
    Piece* exchange;
public:
    HistoryItem(){}

    void addValues(Field *from, Field *to, Piece *target_to){
        this->from = from;
        this->to = to;
        this->target_to = target_to;
        this->exchange = nullptr;
    }

    Field* getFrom() {
        return this->from;
    }

    Field* getTo() {
        return this->to;
    }

    Piece* getTarget_to() {
        return this->target_to;
    }

    void setExchange(Piece* piece){
        this->exchange = piece;
    }

    Piece* getExchange() {
        return this->exchange;
    }
};

#endif //CPP_CHESS_HISTORYITEM_H

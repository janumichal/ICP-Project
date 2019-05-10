/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_HISTORYITEM_H
#define CPP_CHESS_HISTORYITEM_H

#include "../Chess_pieces/Piece.h"
#include "Field.h"
#include <utility>

using namespace std;

class HistoryItem{
private:
    Field* from;
    Field* to;
    Piece* target_to;
    Piece* exchange;
public:
    /**
     * @brief Created instance of Item in History.
     */
    HistoryItem();

    /**
     * @brief Adds value to HistoryItem.
     * @param from Field piece moves from.
     * @param to Field piece moves to.
     * @param target_to Pointer to Piece on field to.
     */
    void addValues(Field *from, Field *to, Piece *target_to);

    /**
     * @brief Getter for from field in HistoryItem.
     * @return Field from.
     */
    Field* getFrom();

    /**
     * @brief Getter for to field in HistoryItem.
     * @return Field to.
     */
    Field* getTo();

    /**
     * @brief Getter for pointer on piece placed on field from.
     * @return pointer to piece.
     */
    Piece* getTarget_to();

    /**
     * @brief Setter for exchange.
     * @param piece Piece to exchange for
     */
    void setExchange(Piece* piece);

    /**
     * @brief Getter for exchange.
     * @return Pointer on piece is being exchanged.
     */
    Piece* getExchange();

};

#endif //CPP_CHESS_HISTORYITEM_H

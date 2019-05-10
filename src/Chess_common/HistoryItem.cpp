/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#include "HistoryItem.h"

using namespace std;

HistoryItem::HistoryItem() = default;

void HistoryItem::addValues(Field *from, Field *to, Piece *target_to){
    this->from = from;
    this->to = to;
    this->target_to = target_to;
    this->exchange = nullptr;
}

Field* HistoryItem::getFrom() {
    return this->from;
}

Field* HistoryItem::getTo() {
    return this->to;
}

Piece* HistoryItem::getTarget_to() {
    return this->target_to;
}

void HistoryItem::setExchange(Piece* piece){
    this->exchange = piece;
}

Piece* HistoryItem::getExchange() {
    return this->exchange;
}


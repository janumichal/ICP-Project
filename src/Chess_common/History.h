/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_HISTORY_H
#define CPP_CHESS_HISTORY_H

#include <vector>
#include "HistoryItem.h"

using namespace std;

class History{
private:
    vector<HistoryItem*> array;
    int pointer;

public:
    History();
    void add(HistoryItem* item);

private:
    void clear();

public:
    HistoryItem* undo();
    HistoryItem* redo();

};



#endif //CPP_CHESS_HISTORY_H

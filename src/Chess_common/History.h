/**
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
    /**
     * @brief Creates instance of History.
     */
    History();

    /**
     * @brief Adds item to History.
     * @param item Item being added.
     */
    void add(HistoryItem* item);

private:
    /**
     * @brief Cleans whole History.
     */
    void clear();

public:
    /**
     * @brief moves pointer in History back.
     * @return HistoryItem on current index.
     */
    HistoryItem* undo();

    /**
     * @brief moves pointer in History forward.
     * @return HistoryItem on current index.
     */
    HistoryItem* redo();

};



#endif //CPP_CHESS_HISTORY_H

/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_TAB_H
#define CPP_CHESS_TAB_H

#include "Game.h"

using namespace std;

class Tab {
    Game *game;
public:
    Tab();
    void next();
    void prew();
    void undo();
    void redo();
    void move(Field *from, Field *to);
    void start_auto();
    void loadAllMoves(string moves_input);
    void newGame();

};

#endif //CPP_CHESS_TAB_H

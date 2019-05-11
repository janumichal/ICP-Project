/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_TAB_H
#define CPP_CHESS_TAB_H

#include "Game.h"

using namespace std;

/**
 * @brief Class for Tab
 */
class Tab {
    Game *game;
public:
    /**
     * @brief Creates instance of Tab.
     */
    Tab();

    /**
     * @brief Next move in Auto mode.
     */
    void next();

    /**
     * @brief Preview move in Auto mode.
     */
    void prew();

    /**
     * @brief Undo move in Manual mode.
     */
    void undo();

    /**
     * @brief Redo move in Manual mode
     */
    void redo();

    /**
     * @brief moves piece from field from to field to.
     * @param from Moves from.
     * @param to Moves to.
     */
    void move(Field *from, Field *to);

    /**
     * @brief starts Automatic mode.
     */
    void start_auto();

    /**
     * @brief Loads all moves from string
     * @param moves_input string moves are being load from.
     */
    void loadAllMoves(string moves_input);

    /**
     * @brief Creates new game.
     */
    void newGame();

};

#endif //CPP_CHESS_TAB_H

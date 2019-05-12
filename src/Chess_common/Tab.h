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

public:
    /**
     * @brief instance of game
     */
    Game *game;
    /**
     * @brief Creates instance of Tab.
     */
    Tab();

    /**
     * @brief loads file and validates the moves.
     * @param url
     */
    void Load(const string &url);
    /**
     * @brief prints games
     */
    void PrintGame();
    /**
     * @brief moves from to
     * @param from position of out piece
     * @param to position where to go
     */
    void Move(string from, string to);

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

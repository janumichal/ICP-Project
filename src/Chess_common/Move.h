/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_MOVE_H
#define CPP_CHESS_MOVE_H

#include "Field.h"
#include "../enum/colors_piece.h"

using namespace std;

/**
 * @brief Class for Move
 */
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
    /**
     * @brief Creates instance for move.
     */
    Move();

    /**
     * @brief Setter of color in move.
     * @param color Color to set.
     */
    void setColor(color_piece color);

    /**
     * @brief Getter for color in move.
     * @return Color in move.
     */
    color_piece getColor();

    /**
     * @brief Prints move in valid format.
     * @return Move in valid format.
     */
    string pritnMove();

    /**
     * @brief Getter for exchange.
     * @return Character representing piece exchange for.
     */
    char getExchange();

    /**
     * @brief Setter for exchange.
     * @param exchange Sets exchange character.
     */
    void setExchange(char exchange);

    /**
     * @brief Setter for field from in move.
     * @param from Field piece is moving from.
     */
    void setFrom(Field* from);

    /**
     * @brief Setter for field to in move
     * @param to Field piece is moving to.
     */
    void setTo(Field* to);

    /**
     * @brief Setter for take in move.
     */
    void setTake();

    /**
     * @brief Setter for check in move.
     */
    void setCheck();

    /**
     * @brief Setter for mat in move.
     */
    void setMat();

    /**
     * @brief Setter for King in move.
     */
    void setKing();

    /**
     * @brief Setter for Queen in move.
     */
    void setQueen();

    /**
     * @brief Setter for Bishop in move.
     */
    void setBishop();

    /**
     * @brief Setter for Knight in move.
     */
    void setKnight();

    /**
     * @brief Setter for Pawn in move.
     */
    void setPawn();

    /**
     * @brief Setter for Rook in move.
     */
    void setRook();

    /**
     * @brief getter for from in move
     * @return Field piece move from.
     */
    Field* getFrom();

    /**
     * @brief getter for to in move
     * @return Field piece move to.
     */
    Field* getTo();

    /**
     * @return Move is take.
     */
    bool isTake();

    /**
     * @return Move is check.
     */
    bool isCheck();

    /**
     * @return Move is mat.
     */
    bool isMat();

    /**
     * @return Move is King.
     */
    bool isKing();

    /**
     * @return Move is Queen.
     */
    bool isQueen();

    /**
     * @return Move is Bishop.
     */
    bool isBishop();

    /**
     * @return Move is Knight.
     */
    bool isKnight();

    /**
     * @return Move is Pawn.
     */
    bool isPawn();

    /**
     * @return Move is Rook.
     */
    bool isRook();

    /**
     * @brief Setter for column in move in character form.
     * @param column Column on board.
     */
    void setColumn(char column);

    /**
     * @brief Setter for column in move in numeric form.
     * @param column Column on board.
     */
    void setColumn(int column);

    /**
     * @brief Setter for row in move in character form.
     * @param row Row on board.
     */
    void setRow(char row);

    /**
     * @brief Setter for row in move in numeric form.
     * @param row Row on board.
     */
    void setRow(int row);

    /**
     * @brief Getter for column in move.
     * @return column
     */
    int getColumn();

    /**
     * @brief Getter for row in move.
     * @return row
     */
    int getRow();

};

#endif //CPP_CHESS_MOVE_H

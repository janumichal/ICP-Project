/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#ifndef CPP_CHESS_GAME_H
#define CPP_CHESS_GAME_H

#include <iostream>
#include "History.h"
#include "HistoryItem.h"
#include "Move.h"
#include "Board.h"
#include "../enum/colors_piece.h"
#include "../enum/direction.h"
#include "others.h"

using namespace std;
/**
 * @brief Class for Game
 */
class Game{
private:
    History *history;
    HistoryItem *item;
    vector<Move*> loaded_moves;
    bool is_pawn;
    int index;
    bool auto_mode;
    bool game_end = false;
public:
    /**
     * @brief Board with pieces
     */
    Board *board;


    /**
     * @brief Creates instance of game.
     */
    Game();

    /**
     * @brief Check if is Automatic mode.
     * @return is Automatic mode.
     */
    bool isAuto_mode();

    /**
     * @brief Sets Automatic mode off.
     */
    void setAuto_modeOFF();

    /**
     * @brief Sets automatic mode on.
     */
    void setAuto_modeON();

    /**
     * @brief Prewious move.
     */
    void prew();

    /**
     * @brief Next move.
     */
    void next();

    /**
     * @brief Applayes move from loaded_moves.
     */
    void applyMove();

    /**
     * @brief Loads Move in full format
     * @param one_move Loaded move.
     */
    void fullFormat(Move *one_move);

    /**
     * @brief Applayes exchange from move.
     * @param one_move move with the exchange.
     */
    void exchange(Move* one_move);

    /**
     * @brief saves HistoryItem to History
     * @param one_move move that is being saved.
     * @param piece Exchange piece.
     */
    void saveHistory(Move *one_move, Piece *piece);

    /**
     * @brief Loads simplified format of move.
     * @param one_move move that is being loading from.
     */
    void simpleFormat(Move* one_move);

    /**
     * @brief Gets field from and saves it to move
     * @param one_move move is being saved in.
     */
    void getFromCoords(Move* one_move);

    /**
     * @brief Check valid moves for Queen.
     * @param move move with coordinates.
     */
    void queenCheck(Move *move);

    /**
     * @brief Check valid moves for Bishop.
     * @param move move with coordinates.
     */
    bool bishopCheck(Move *move);

    /**
     * @brief Checks all direction for move validation.
     * @param move move with coords.
     * @param to Field to move to.
     * @param piece Piece that is being moved.
     * @return
     */
    bool bishopAll(Move *move, Field *to, const string &piece);

    /**
     * @brief move validation in simplified format in with set column.
     * @param move move with coordinates.
     * @param piece piece that is being moved.
     * @return if is valid move.
     */
    bool bishopCheckCol(Move *move, const string &piece);

    /**
     * @brief move validation in simplified format in with set row.
     * @param move move with coordinates.
     * @param piece piece that is being moved.
     * @return if is valid move.
     */
    bool bishopCheckRow(Move *move, const string &piece);

    /**
     * @brief Check valid moves for Rook.
     * @param move move with coordinates.
     */
    bool rookCheck(Move *move);

    /**
     * @brief Checks all direction for move validation.
     * @param move move with coords.
     * @param to Field to move to.
     * @param piece Piece that is being moved.
     * @return
     */
    bool rookCheckAll(Move *move, Field *to, const string &piece);

    /**
     * @brief move validation in simplified format in with set row.
     * @param move move with coordinates.
     * @param piece piece that is being moved.
     * @return if is valid move.
     */
    bool rookCheckRow(Move *move , const string &piece);

    /**
     * @brief Check if something is not in direction
     * @param f1 Field starts from.
     * @param dir1 Direction goes to.
     * @param move Move with all coordinates.
     * @param piece Piece that is being moved
     * @return If something is in way.
     */
    bool oneSide(Field *f1, direction dir1, Move *move, const string &piece);

    /**
     * @brief Check if something is not in directions
     * @param f1 Field starts from.
     * @param dir1 Direction goes to.
     * @param f2 Field starts from.
     * @param dir2 Direction goes to.
     * @param move Move with all coordinates.
     * @param piece Piece that is being moved
     * @return If something is in way.
     */
    bool twoSides(Field *f1, direction dir1, Field *f2, direction dir2, Move *move, const string &piece);

    /**
     * @brief move validation in simplified format in with set column.
     * @param move move with coordinates.
     * @param piece piece that is being moved.
     * @return if is valid move.
     */
    bool rookCheckCol(Move *move, const string &piece);

    /**
     * @brief Check valid moves for Knight.
     * @param one_move move with coordinates.
     */
    void knightCheck(Move *one_move);

    /**
     * @brief move aplication in simplified format in with set row.
     * @param move move with coordinates.
     * @param to Position where move to.
     */
    void knightCheckRow(Move *move, Field *to);

    /**
     * @brief move aplication in simplified format in with set row.
     * @param move move with coordinates.
     * @param to Position where move to.
     * @param dir Direction to go to.
     */
    void knightCheckRowN(Field *to, Move *move, direction dir);

    /**
     * @brief move aplication in simplified format in with set column.
     * @param move move with coordinates.
     * @param to Position where move to.
     */
    void knightCheckColumn(Move *move, Field *to);

    /**
     * @brief move aplication in simplified format in with set column.
     * @param move move with coordinates.
     * @param to Position where move to.
     * @param dir Direction to go to.
     */
    void knightCheckColumnN(Field *to, Move *move, direction dir);

    /**
     * @brief applyes move that is in simplified format
     * @param one_move
     * @param to
     */
    void knightCheckAllmoves(Move *one_move, Field *to);

    /**
     * @brief applyes move.
     * @param from field to move from.
     * @param one_move move with coordinates.
     */
    void pieceCheckMove(Field *from, Move *one_move);

    /**
     * @brief Check valid moves for King.
     * @param one_move move with coordinates.
     */
    void kingCheck(Move *one_move);

    /**
     * @brief Check valid moves for Pawn.
     * @param dir whitch direction pice moves in
     * @param one_move move with coordinates.
     */
    void pawnCheck(direction dir, Move *one_move);

    /**
     * @brief application of move where pawn takes piece.
     * @param dir1 direction to move to
     * @param dir2 direction to move to
     * @param one_move move with all coordinates
     */
    void pawnCheckTake(direction dir1, direction dir2, Move *one_move);

    /**
     * @brief applyes move
     * @param from move from
     * @param to move to
     */
    void move(Field *from, Field *to);

    /**
     * @brief deletes moves from index to end
     */
    void delFromIndex();

    /**
     * @brief Creates move
     * @param from from where to move
     * @param to where to move to.
     * @return move that has been saved.
     */
    Move* createMove(Field *from, Field *to);

    /**
     * @brief getter of points of specific color.
     * @param color Color
     * @return points
     */
    int points(color_piece color);

    /**
     * @brief undo move.
     */
    void undo();

    /**
     * @brief redo move.
     */
    void redo();

    /**
     * @brief loads all moves from string.
     * @param all_moves moves in string form.
     */
    void loadAllMoves(const string &all_moves);

    /**
     * @brief Prints all saved moves to console.
     */
    void printAllMoves();

    /**
     * @brief check format of one move
     * @param coordinates move in string form
     * @return move in Move instance
     */
    Move* formatMove(string coordinates);

    /**
     *
     * @param coordinates Move in string form
     * @param sign sign from move
     * @param counter counter of length
     * @param move move in instance format
     * @return move in Move instance
     */
    Move* isBodyMove(string coordinates, char sign, int counter, Move *move);

    /**
     *
     * @param coordinates Move in string form
     * @param sign sign from move
     * @param counter counter of length
     * @param move move in instance format
     * @return move in Move instance
     */
    Move* isValidFromTakeToEndMove(string coordinates, char sign, int counter, Move *move);

    /**
     *
     * @param coordinates Move in string form
     * @param counter counter of length
     * @param sign sign from move
     * @param move move in instance format
     * @return move in Move instance
     */
    Move* endSwitchFormatMove(string coordinates, int counter, char sign, Move *move);

    /**
     * @brief check valid format.
     * @param coordinates move in string format
     * @return if is valid.
     */
    bool validFormat(string coordinates);

    /**
     * @brief if is valid character
     * @param Character the character
     * @return if is valid
     */
    bool isValidSign(char Character);

    /**
     * @brief Check if is valid number.
     * @param Character Character that is being transfered to number.
     * @return if is valid.
     */
    bool isValidNumber(char Character);

    /**
     * @brief Check if move is in valid format.
     * @param coordinates move in string format
     * @param sign one character of string move
     * @param counter counter of move length
     * @return if is valid.
     */
    bool isValidFromTakeToEnd(string coordinates, char sign, int counter);

    /**
     * @brief  Check if move is in valid format.
     * @param coordinates move in string format
     * @param sign one character of string move
     * @param counter counter of move length
     * @return if is valid.
     */
    bool endSwitchFormat(string coordinates, char sign, int counter);

    /**
     * @brief Check if move is in valid format.
     * @param coordinates move in string format
     * @param sign one character of string move
     * @param counter counter of move length
     * @return if is valid.
     */
    bool isBody(string coordinates, char sign, int counter);

    /**
     * @brief Setter for column in character format
     * @param sign column in character.
     * @return column number
     */
    int setColumnI(char sign);

    /**
     * @brief Setter for row in character format
     * @param sign row in character.
     * @return row number
     */
    int setRowI(char sign);

    /**
     * @brief Finds King of specific color on board.
     * @param color color of king
     * @return pointer on king
     */
    Field *findKing(color_piece color);

    /**
     * @brief Check if is CheckMat.
     * @param one_move move in instance format
     * @return if is checkmat.
     */
    bool checkMat(Move *one_move);

    /**
     * @brief check if is mat
     * @param from king is on field from
     * @param color_king color of king.
     * @return if is mat.
     */
    bool isMat(Field *from, color_piece color_king);

    /**
     * @brief check if is check
     * @param from king is on field from
     * @param color_king color of king.
     * @return if is check.
     */
    bool isCheck(Field *from, color_piece color_king);

    /**
     * @brief finds if moves are being valid for Bishop or Queen.
     * @param f Field moves from
     * @param color color of piece
     * @param piece pointer on piece
     * @return if move is valid
     */
    bool controlEX(Field *f, color_piece color, char piece);

    /**
     * @brief Setter for index
     * @param i index
     */
    void setIndex(int i);
};

#endif //CPP_CHESS_GAME_H

//
// Created by janum on 23.04.2019.
//

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
    Board *board;

    Game();
    bool isAuto_mode();
    void setAuto_modeOFF();
    void setAuto_modeON();
    void prew();
    void next();
    void applyMove();
    void fullFormat(Move *one_move);
    void exchange(Move* one_move);
    void saveHistory(Move *one_move, Piece *piece);
    void simpleFormat(Move* one_move);
    void getFromCoords(Move* one_move);
    void queenCheck(Move *move);
    bool bishopCheck(Move *move);
    bool bishopAll(Move *move, Field *to, const string &piece);
    bool bishopCheckCol(Move *move, const string &piece);
    bool bishopCheckRow(Move *move, const string &piece);
    bool rookCheck(Move *move);
    bool rookCheckAll(Move *move, Field *to, const string &piece);
    bool rookCheckRow(Move *move , const string &piece);
    bool oneSide(Field *f1, direction dir1, Move *move, const string &piece);
    bool twoSides(Field *f1, direction dir1, Field *f2, direction dir2, Move *move, const string &piece);
    bool rookCheckCol(Move *move, const string &piece);
    void knightCheck(Move *one_move);
    void knightCheckRow(Move *move, Field *to);
    void knightCheckRowN(Field *to, Move *move, direction dir);
    void knightCheckColumn(Move *move, Field *to);
    void knightCheckColumnN(Field *to, Move *move, direction dir);
    void knightCheckAllmoves(Move *one_move, Field *to);
    void pieceCheckMove(Field *from, Move *one_move);
    void kingCheck(Move *one_move);
    void pawnCheck(direction dir, Move *one_move);
    void pawnCheckTake(direction dir1, direction dir2, Move *one_move);
    void move(Field *from, Field *to);
    void delFromIndex();
    Move* createMove(Field *from, Field *to);
    int points(color_piece color);
    void undo();
    void redo();
    void loadAllMoves(const string &all_moves);
    void printAllMoves();
    Move* formatMove(string coordinates);
    Move* isBodyMove(string coordinates, char sign, int counter, Move *move);
    Move* isValidFromTakeToEndMove(string coordinates, char sign, int counter, Move *move);
    Move* endSwitchFormatMove(string coordinates, int counter, char sign, Move *move);
    bool validFormat(string coordinates);
    bool isValidSign(char Character);
    bool isValidNumber(char Character);
    bool isValidFromTakeToEnd(string coordinates, char sign, int counter);
    bool endSwitchFormat(string coordinates, char sign, int counter);
    bool isBody(string coordinates, char sign, int counter);
    int setColumnI(char sign);
    int setRowI(char sign);
    Field *findKing(color_piece );
    bool checkMat(Move *);
    bool isMat(Field *, color_piece );
    bool isCheck(Field *, color_piece );
    bool controlEX(Field *, color_piece , char );
    void setIndex(int);
};

#endif //CPP_CHESS_GAME_H

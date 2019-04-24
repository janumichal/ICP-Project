//
// Created by janum on 24.04.2019.
//

#ifndef CPP_CHESS_STRING_WORK_H
#define CPP_CHESS_STRING_WORK_H

#include "string"
#include "iostream"
#include "algorithm"
#include "vector"
#include <sstream>

#include "../Chess_pieces/Piece.h"
#include "../Chess_pieces/Rook.h"
#include "../Chess_pieces/King.h"
#include "../Chess_pieces/Queen.h"
#include "../Chess_pieces/Bishop.h"
#include "../Chess_pieces/Knight.h"
#include "../Chess_pieces/Pawn.h"


using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string &s);
string rtrim(const string &s);
string trim(const string &s);
vector<string> split(const string& s, char delimiter);

bool isRook(Piece *piece);
bool isPawn(Piece *piece);
bool isKing(Piece *piece);
bool isQueen(Piece *piece);
bool isBishop(Piece *piece);
bool isKnight(Piece *piece);

#endif //CPP_CHESS_STRING_WORK_H

/**
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

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

/**
 * @brief Trims string from left.
 * @param s String to trim.
 * @return Trimmed string
 */
string ltrim(const string &s);

/**
 * @brief Trims string from right.
 * @param s String to trim.
 * @return Trimmed string
 */
string rtrim(const string &s);

/**
 * @brief Trims string from both sides.
 * @param s String to trim.
 * @return Trimmed string
 */
string trim(const string &s);

/**
 * @brief Splits string by delimiter.
 * @param s String to split
 * @param delimiter Delimiter for splitting.
 * @return Splitted string in vector.
 */
vector<string> split(const string& s, char delimiter);

/**
 * @brief Check if piece is instance of Rook.
 * @param piece Piece to check.
 * @return Is instance.
 */
bool isRook(Piece *piece);

/**
 * @brief Check if piece is instance of Pawn.
 * @param piece Piece to check.
 * @return Is instance.
 */
bool isPawn(Piece *piece);

/**
 * @brief Check if piece is instance of King.
 * @param piece Piece to check.
 * @return Is instance.
 */
bool isKing(Piece *piece);

/**
 * @brief Check if piece is instance of Queen.
 * @param piece Piece to check.
 * @return Is instance.
 */
bool isQueen(Piece *piece);

/**
 * @brief Check if piece is instance of Bishop.
 * @param piece Piece to check.
 * @return Is instance.
 */
bool isBishop(Piece *piece);

/**
 * @brief Check if piece is instance of Knight.
 * @param piece Piece to check.
 * @return Is instance.
 */
bool isKnight(Piece *piece);

#endif //CPP_CHESS_STRING_WORK_H

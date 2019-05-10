/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */
#include "others.h"


string ltrim(const string &s){
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s){
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end +1);
}

string trim(const string &s){
    return rtrim(ltrim(s));
}

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool isRook(Piece *piece){
    if(piece == nullptr){
        return false;
    }
    return piece->getName() == 'r';
}

bool isPawn(Piece *piece){
    if(piece == nullptr){
        return false;
    }
    return piece->getName() == 'p';
}

bool isKing(Piece *piece){
    if(piece == nullptr){
        return false;
    }
    return piece->getName() == 'K';
}

bool isQueen(Piece *piece){
    if(piece == nullptr){
        return false;
    }
    return piece->getName() == 'q';
}

bool isBishop(Piece *piece){
    if(piece == nullptr){
        return false;
    }
    return piece->getName() == 'b';
}

bool isKnight(Piece *piece){
    if(piece == nullptr){
        return false;
    }
    return piece->getName() == 'k';
}
//
// Created by janum on 11.04.2019.
//

#ifndef CPP_CHESS_BOARD_H
#define CPP_CHESS_BOARD_H

#include "../Chess_pieces/Bishop.h"
#include "../Chess_pieces/King.h"
#include "../Chess_pieces/Knight.h"
#include "../Chess_pieces/Rook.h"
#include "../Chess_pieces/Pawn.h"
#include "../Chess_pieces/Queen.h"
#include "../Chess_pieces/Piece.h"
#include "Field.h"
#include "HistoryItem.h"

const int BOARD_SIZE = 8;

using namespace std;

class Board {
private:
    Field ***board_array;
    HistoryItem *historyItem;
    bool white_on_move;
    int white_points;
    int black_points;

public:

    Board(){
        this->white_on_move = true;
        this->white_points = 0;
        this->black_points = 0;

        board_array = new Field**[BOARD_SIZE];
        for (int x = 0; x < BOARD_SIZE; x++){
            for (int y = 0; y < BOARD_SIZE; y++){
                auto *field = new Field(x, y);
                board_array[x][y] = field;
            }
        }
        fillArrayAround();
    }


    bool is_white_on_move(){
        return this->white_on_move;
    }

    void printPoints(){
        cout << "White: " + to_string(getWhite_points()) + " Black: " + to_string(getBlack_points()) << endl;
    }

    Field* getField(int x, int y){
        return this->board_array[x][y];
    }

    HistoryItem* movePiece(Field *from, Field *to){
        Piece *player = from->getPiece();
        Piece *target = to->getPiece();

        if (player != nullptr){
            if (is_white_on_move()){
                if (player->getColor() == BLACK){
                    printf("WHITE IS ON MOVE");
                    // TODO WINDOW POPUP
                    return nullptr;
                }
            }else {
                if (player->getColor()== WHITE){
                    printf("BLACK IS ON MOVE");
                    // TODO WINDOW POPUP
                    return nullptr;
                }
            }
        }

        if (typeid(player) == typeid(Pawn())){ // MOVE PAWN
            if(((Pawn*)player)->isMoveValid(to->getCol(), to->getRow(), target)){
                movePawn(from, to);
            }else {
                printf("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(Rook())){ // MOVE ROOK
            if (((Rook*)player)->isMoveValid(to->getCol(), to->getRow())){
                moveRook(from, to);
            }else {
                printf("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if (typeid(player) == typeid(Knight())){ // MOVE KNIGHT
            if (((Knight*)player)->isMoveValid(to->getCol(), to->getRow())){
                moveKnight(from, to);
            }else {
                printf("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(Bishop())){ // MOVE BISHOP
            if (((Bishop*)player)->isMoveValid(to->getCol(), to->getRow())){
                moveBishop(from, to);
            }else {
                printf("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(King())){
            if (((King*)player)->isMoveValid(to->getCol(), to->getRow())){
                moveKing(from, to);
            }else {
                printf("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(Queen())){
            if (((Queen*)player)->isMoveValid(to->getCol(), to->getRow())){
                moveQueen(from, to);
            }else {
                printf("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else{
            printf("NO movable piece avalible");
            // TODO WINDOW POPUP
            return nullptr;
        }
        return this->historyItem;
    }

private:
    void moveBishop(Field *from, Field *to){
        if (from->getCol() < to->getCol() && from->getRow() < to->getRow()){ // GO RIGHT DOWN
            moveInDir(RIGHT_DOWN, from, to);
        }else if (from->getCol() < to->getCol() && from->getRow() > to->getRow()){ // GO RIGHT UP
            moveInDir(RIGHT_UP, from, to);
        }else if (from->getCol() > to->getCol() && from->getRow() < to->getRow()){ // GO LEFT DOWN
            moveInDir(LEFT_DOWN, from, to);
        }else if (from->getCol() > to->getCol() && from->getRow() > to->getRow()){ // GO LEFT UP
            moveInDir(LEFT_UP, from, to);
        }
    }

    void moveQueen(Field *from, Field *to){
        if (from->getCol() < to->getCol() && from->getRow() < to->getRow()){ // GO RIGHT DOWN
            moveInDir(RIGHT_DOWN, from, to);
        }else if (from->getCol() < to->getCol() && from->getRow() > to->getRow()){ // GO RIGHT UP
            moveInDir(RIGHT_UP, from, to);
        }else if (from->getCol() > to->getCol() && from->getRow() < to->getRow()){ // GO LEFT DOWN
            moveInDir(LEFT_DOWN, from, to);
        }else if (from->getCol() > to->getCol() && from->getRow() > to->getRow()){ // GO LEFT UP
            moveInDir(LEFT_UP, from, to);
        }else if (from->getCol() < to->getCol() && from->getRow() == to->getRow()){ // GO RIGHT
            moveInDir(RIGHT, from, to);
        }else if (from->getCol() > to->getCol() && from->getRow() == to->getRow()){ // GO LEFT
            moveInDir(LEFT, from, to);
        }else if (from->getRow() < to->getRow() && from->getCol() == to->getCol()){ // GO DOWN
            moveInDir(DOWN, from, to);
        }else if (from->getRow() > to->getRow() && from->getCol() == to->getCol()){ // GO UP
            moveInDir(UP, from, to);
        }
    }


    //King
    void moveKing(Field *from, Field *to){
        move(from, to);
    }

    // ROOK
    void moveRook(Field *from, Field *to){
        if (from->getCol() < to->getCol()){ // GO RIGHT
            moveInDir(RIGHT, from, to);
        }else if (from->getCol() > to->getCol()){ // GO LEFT
            moveInDir(LEFT, from, to);
        }else if (from->getRow() < to->getRow()){ // GO DOWN
            moveInDir(DOWN, from, to);
        }else if (from->getRow() > to->getRow()){ // GO UP
            moveInDir(UP, from, to);
        }
    }

    void moveInDir(direction direction, Field *from, Field *to){
        Field *pointer = from->nextField(direction);
        bool free_path = true;

        while (to != pointer){
            if(pointer->getPiece() != nullptr){
                free_path = false;
                break;
            }else{
                pointer = pointer->nextField(direction);
            }
        }

        if (free_path){
            move(from, to);
        }else {
            printf("NOT FREE PATH");
        }
    }

    // PAWN
    void movePawn(Field *from, Field *to){
        if (from->getPiece()->getColor() == WHITE){
            if (to->getPiece() == nullptr){
                moveInDir(UP, from, to);
            }else {
                move(from, to);
            }
        }else{
            if (to->getPiece() == nullptr){
                Field *pointer = from->nextField(DOWN);
                bool free_path = true;

                while (to != pointer){
                    if(pointer->getPiece() != nullptr){
                        free_path = false;
                        break;
                    }else{
                        pointer = pointer->nextField(DOWN);
                    }
                }

                if (free_path){
                    move(from, to);
                }else {
                    printf("NOT FREE PATH");
                }
            }else {
                move(from, to);
            }
        }
    }


    // Knight
    void moveKnight(Field *from, Field *to){
        move(from, to);
    }

    void move(Field *from, Field *to){
        if (!to->isEmpty()){
            if(from->getPiece()->getColor() == to->getPiece()->getColor()){
                printf("CANT ATTACK SAME COLOR");
                // TODO WINDOW POPUP
            }else{
                Piece *piece_to;
                Piece *piece_from = from->removePiece();
                piece_to = to->removePiece();
                if (piece_to->getColor() == WHITE){
                    this->black_points += piece_to->getValue();
                }else{
                    this->white_points += piece_to->getValue();
                }
                to->putPiece(piece_from);
                this->historyItem = new HistoryItem();
                this->historyItem->addValues(from, to, piece_to);
                this->white_on_move = !this->white_on_move;
            }
        }else{
            Piece *piece_from = from->removePiece();
            to->putPiece(piece_from);
            this->historyItem = new HistoryItem();
            this->historyItem->addValues(from, to, nullptr);
            this->white_on_move = !this->white_on_move;
        }
    }

public:
    void moveHistory(Field *from, Field *to, Piece *target, Piece *exchange){
        Piece *piece = to->removePiece();
        if (exchange == nullptr){
            from->putPiece(piece);
        }else{
            if (typeid(piece) == typeid(Pawn)){
                from->putPiece(exchange);
            }else {
                from->putPiece(new Pawn(from->getCol(), from->getRow(), piece->getColor()));
            }
        }
        to->putPiece(target);
    }


    //############################################# CREATING BOARD #####################################################
    // show piece placement in text mode
    void showPiecesText(){
        printf("---------------------------------------------------------------------------------------------------------\n");
        for (int y = 0; y < BOARD_SIZE; y++){
            printf("|");
            for (int x = 0; x < BOARD_SIZE; x++){
                Piece *piece = this->board_array[x][y]->getPiece();
                if(typeid(piece) == typeid(Rook)){
                    printf("  Rook (V)  ");
                }else if(typeid(piece) == typeid(Knight)){
                    printf(" Knight (J) ");
                }else if(typeid(piece) == typeid(Bishop)){
                    printf(" Bishop (S) ");
                }else if(typeid(piece) == typeid(King)){
                    printf("  King (K)  ");
                }else if(typeid(piece) == typeid(Queen)){
                    printf(" Queen (D)  ");
                }else if(typeid(piece) == typeid(Pawn)){
                    printf("  pawn (p)  ");
                }else{
                    printf("            ");
                }
                if (x == BOARD_SIZE-1){
                    printf("|\n");
                }else {
                    printf("|");
                }
            }
            printf("---------------------------------------------------------------------------------------------------------\n");
        }
    }

    void fillBoard(){
        placePieces(BLACK);
        placePieces(WHITE);
    }

    void placePieces(color_piece color){
        bool is_black = color == BLACK;
        int y = is_black ? 0 : BOARD_SIZE-1;
        for (int x = 0; x < BOARD_SIZE; x++){
            // place PAWN
            this->board_array[x][is_black ? y+1 : y-1]->putPiece(new Pawn(x, is_black ? y+1 : y-1, color));
            switch (x){
                case 0:
                case (BOARD_SIZE-1):
                    // place ROOKS
                    this->board_array[x][y]->putPiece(new Rook(x, y, color));
                    break;
                case 1:
                case (BOARD_SIZE-2):
                    // place KNIGHTS
                    this->board_array[x][y]->putPiece(new Knight(x, y, color));
                    break;
                case 2:
                case (BOARD_SIZE-3):
                    //place BISHOPS
                    this->board_array[x][y]->putPiece(new Bishop(x, y, color));
                    break;
                case 3:
                    // place KING
                    this->board_array[x][y]->putPiece(new King(x, y, color));
                    break;
                case (BOARD_SIZE-4):
                    // place QUEEN
                    this->board_array[x][y]->putPiece(new Queen(x, y, color));
                    break;
            }
        }
    }

private:
    void fillArrayAround(){
        for (int x = 0; x < BOARD_SIZE; x++){
            for (int y = 0; y < BOARD_SIZE; y++){
                Field *actual_field = this->board_array[x][y];

                for (int k = 0;k < 8;k++){
                    int x1;
                    int y1;
                    switch (k){
                        case 0:
                            x1 = x-1;
                            y1 = y-1;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(LEFT_UP, this->board_array[x1][y1]);
                            }
                            break;
                        case 1:
                            x1 = x;
                            y1 = y-1;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(UP, this->board_array[x1][y1]);
                            }
                            break;
                        case 2:
                            x1 = x+1;
                            y1 = y-1;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(RIGHT_UP, this->board_array[x1][y1]);
                            }
                            break;
                        case 3:
                            x1 = x+1;
                            y1 = y;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(RIGHT, this->board_array[x1][y1]);
                            }
                            break;
                        case 4:
                            x1 = x+1;
                            y1 = y+1;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(RIGHT_DOWN, this->board_array[x1][y1]);
                            }
                            break;
                        case 5:
                            x1 = x;
                            y1 = y+1;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(DOWN, this->board_array[x1][y1]);
                            }
                            break;
                        case 6:
                            x1 = x-1;
                            y1 = y+1;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(LEFT_DOWN, this->board_array[x1][y1]);
                            }
                            break;
                        case 7:
                            x1 = x-1;
                            y1 = y;
                            if (isInArray(x1,y1)){
                                actual_field->addNextField(LEFT, this->board_array[x1][y1]);
                            }
                            break;
                    }
                }
            }
        }
    }

    bool isInArray(int x, int y){
        if((x >= 0)&&(x <= BOARD_SIZE-1)){
            return((y >= 0)&&(y <= BOARD_SIZE-1));
        }
        return false;
    }

public:
    int getWhite_points() {
        return white_points;
    }

    int getBlack_points() {
        return black_points;
    }

};


#endif //CPP_CHESS_BOARD_H

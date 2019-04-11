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
#import "Field.h"
#import "HistoryItem.h"

const int BOARD_SIZE = 8;

class Board {
private:
    Field[][] *board_array;
    HistoryItem historyItem;
    bool white_on_move;
    int white_points;
    int black_points;

public:

    Board(){
        this->white_on_move = true;
        this->white_points = 0;
        this->black_points = 0;

        board_array = new Field[BOARD_SIZE][BOARD_SIZE];
        for (int x = 0; x < BOARD_SIZE; x++){
            for (int y = 0; y < BOARD_SIZE; y++){
                Field field = new Field(x, y);
                board_array[x][y] = field;
            }
        }
        fillArrayAround();
    }


    bool is_white_on_move(){
        return this->white_on_move;
    }

    void printPoints(){
        cout << "White: " + getWhite_points() + " Black: " + getBlack_points() << endl;
    }

    Field getField(int x, int y){
        return this->board_array[x][y];
    }

    HistoryItem* movePiece(Field *from, Field *to){
        Piece *player = from->getPiece();
        Piece *target = to->getPiece();

        if (player != nullptr){
            if (is_white_on_move()){
                if (player->getColor() == BLACK){
                    System.out.println("WHITE IS ON MOVE");
                    // TODO WINDOW POPUP
                    return nullptr;
                }
            }else {
                if (player->getColor()== WHITE){
                    System.out.println("BLACK IS ON MOVE");
                    // TODO WINDOW POPUP
                    return nullptr;
                }
            }
        }

        if (typeid(player) == typeid(Pawn())){ // MOVE PAWN
            if(((Pawn) player)->isMoveValid(to->getCol(), to->getRow(), target)){
                movePawn(from, to);
            }else {
                System.out.println("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(Rook())){ // MOVE ROOK
            if (((Rook) player)->isMoveValid(to->getCol(), to->getRow())){
                moveRook(from, to);
            }else {
                System.out.println("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if (typeid(player) == typeid(Knight())){ // MOVE KNIGHT
            if (((Knight) player)->isMoveValid(to->getCol(), to->getRow())){
                moveKnight(from, to);
            }else {
                System.out.println("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(Bishop())){ // MOVE BISHOP
            if (((Bishop) player)->isMoveValid(to->getCol(), to->getRow())){
                moveBishop(from, to);
            }else {
                System.out.println("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(King())){
            if (((King) player)->isMoveValid(to->getCol(), to->getRow())){
                moveKing(from, to);
            }else {
                System.out.println("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else if(typeid(player) == typeid(Queen())){
            if (((Queen) player)->isMoveValid(to->getCol(), to->getRow())){
                moveQueen(from, to);
            }else {
                System.out.println("IS NOT VALID MOVE");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else{
            System.out.println("NO movable piece avalible");
            // TODO WINDOW POPUP
            return nullptr;
        }
        return this.historyItem;
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






};


#endif //CPP_CHESS_BOARD_H

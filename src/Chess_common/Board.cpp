/*!
 * @authors Michal Janů (xjanum03), Richard Gajda (xgajda06)
 */

#include "Board.h"
#include <iostream>
#include "others.h"

using namespace std;

Board::Board(){
    this->white_on_move = true;
    this->white_points = 0;
    this->black_points = 0;

    for (int x = 0; x < BOARD_SIZE; x++){
        for (int y = 0; y < BOARD_SIZE; y++){
            auto *field = new Field(x, y);
            board_array[x][y] = field;
        }
    }
    fillArrayAround();
}

bool Board::is_white_on_move(){
    return this->white_on_move;
}

void Board::printPoints(){
    cout << "White: " + to_string(getWhite_points()) + " Black: " + to_string(getBlack_points()) << endl;
}

Field* Board::getField(int x, int y){
    return this->board_array[x][y];
}

HistoryItem* Board::movePiece(Field *from, Field *to){
    Piece *player = from->getPiece();
    Piece *target = to->getPiece();

    if (player != nullptr){
        if (is_white_on_move()){
            if (player->getColor() == BLACK){
                printf("WHITE IS ON MOVE\n");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }else {
            if (player->getColor()== WHITE){
                printf("BLACK IS ON MOVE\n");
                // TODO WINDOW POPUP
                return nullptr;
            }
        }
    }

    if (isPawn(player)){ // MOVE PAWN
        if(((Pawn*)player)->isMoveValid(to->getCol(), to->getRow(), target)){
            movePawn(from, to);
        }else {
            printf("IS NOT VALID MOVE");
            // TODO WINDOW POPUP
            return nullptr;
        }
    }else if(isRook(player)){ // MOVE ROOK
        if (((Rook*)player)->isMoveValid(to->getCol(), to->getRow())){
            moveRook(from, to);
        }else {
            printf("IS NOT VALID MOVE\n");
            // TODO WINDOW POPUP
            return nullptr;
        }
    }else if (isKnight(player)){ // MOVE KNIGHT
        if (((Knight*)player)->isMoveValid(to->getCol(), to->getRow())){
            moveKnight(from, to);
        }else {
            printf("IS NOT VALID MOVE\n");
            // TODO WINDOW POPUP
            return nullptr;
        }
    }else if(isBishop(player)){ // MOVE BISHOP
        if (((Bishop*)player)->isMoveValid(to->getCol(), to->getRow())){
            moveBishop(from, to);
        }else {
            printf("IS NOT VALID MOVE\n");
            // TODO WINDOW POPUP
            return nullptr;
        }
    }else if(isKing(player)){
        if (((King*)player)->isMoveValid(to->getCol(), to->getRow())){
            moveKing(from, to);
        }else {
            printf("IS NOT VALID MOVE\n");
            // TODO WINDOW POPUP
            return nullptr;
        }
    }else if(isQueen(player)){
        if (((Queen*)player)->isMoveValid(to->getCol(), to->getRow())){
            moveQueen(from, to);
        }else {
            printf("IS NOT VALID MOVE\n");
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

void Board::moveBishop(Field *from, Field *to){
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

void Board::moveQueen(Field *from, Field *to){
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
void Board::moveKing(Field *from, Field *to){
    move(from, to);
}

// ROOK
void Board::moveRook(Field *from, Field *to){
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

void Board::moveInDir(direction direction, Field *from, Field *to){
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
void Board::movePawn(Field *from, Field *to){
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
void Board::moveKnight(Field *from, Field *to){
    move(from, to);
}

void Board::move(Field *from, Field *to){
    if (!to->isEmpty()){
        if(from->getPiece()->getColor() == to->getPiece()->getColor()){
            printf("CANT ATTACK SAME COLOR");
            this->validation = false;
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
            if(isKing(piece_to)){
                printf("GAME ENDS KING TAKEN\n"); // TODO POPUP
                this->game_end = true;
            }
        }
    }else{
        Piece *piece_from = from->removePiece();
        to->putPiece(piece_from);
        this->historyItem = new HistoryItem();
        this->historyItem->addValues(from, to, nullptr);
        this->white_on_move = !this->white_on_move;
    }
}

void Board::cleanBoard(){
    for (int x = 0; x < BOARD_SIZE; x++){
        for (int y = 0; y < BOARD_SIZE; y++){
            this->board_array[x][y]->putPiece(nullptr);
        }
    }
}

void Board::moveHistory(Field *from, Field *to, Piece *target, Piece *exchange){
    Piece *piece = to->removePiece();
    if (exchange == nullptr){
        from->putPiece(piece);
    }else{
        if (isPawn(piece)){
            from->putPiece(exchange);
        }else {
            from->putPiece(new Pawn(from->getCol(), from->getRow(), piece->getColor()));
        }
    }
    to->putPiece(target);
    this->white_on_move = !this->white_on_move;
}

//############################################# CREATING BOARD #####################################################
// show piece placement in text mode
void Board::showPiecesText(){
    printf("         A            B            C            D            E            F            G          H        \n");
    printf("  ---------------------------------------------------------------------------------------------------------\n");
    for (int y = 0; y < BOARD_SIZE; y++){
        printf("%d",8-y);
        printf(" |");
        for (int x = 0; x < BOARD_SIZE; x++){
            Piece *piece = this->board_array[x][y]->getPiece();
            if(isRook(piece)){
                if(piece->getColor() == WHITE){
                    printf("  Rook (W)  ");
                }else{
                    printf("  Rook (B)  ");
                }
            }else if(isKnight(piece)){
                if(piece->getColor() == WHITE){
                    printf(" Knight (W) ");
                }else{
                    printf(" Knight (B) ");
                }
            }else if(isBishop(piece)){

                if(piece->getColor() == WHITE){
                    printf(" Bishop (W) ");
                }else{
                    printf(" Bishop (B) ");
                }
            }else if(isKing(piece)){
                if(piece->getColor() == WHITE){
                    printf("  King (W)  ");
                }else{
                    printf("  King (B)  ");
                }
            }else if(isQueen(piece)){
                if(piece->getColor() == WHITE){
                    printf(" Queen (W)  ");
                }else{
                    printf(" Queen (B)  ");
                }
            }else if(isPawn(piece)){
                if(piece->getColor() == WHITE){
                    printf("  pawn (W)  ");
                }else{
                    printf("  pawn (B)  ");
                }
            }else{
                printf("            ");
            }
            if (x == BOARD_SIZE-1){
                printf("|\n");
            }else {
                printf("|");
            }
        }
        printf("  ---------------------------------------------------------------------------------------------------------\n");
    }
}

void Board::fillBoard(){
    placePieces(BLACK);
    placePieces(WHITE);
}

void Board::placePieces(color_piece color){
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
                this->board_array[x][y]->putPiece(new Queen(x, y, color));
                break;
            case (BOARD_SIZE-4):
                // place QUEEN
                this->board_array[x][y]->putPiece(new King(x, y, color));
                break;
        }
    }
}

void Board::fillArrayAround(){
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

bool Board::isInArray(int x, int y){
    if((x >= 0)&&(x <= BOARD_SIZE-1)){
        return((y >= 0)&&(y <= BOARD_SIZE-1));
    }
    return false;
}

int Board::getWhite_points() {
    return white_points;
}

int Board::getBlack_points() {
    return black_points;
}